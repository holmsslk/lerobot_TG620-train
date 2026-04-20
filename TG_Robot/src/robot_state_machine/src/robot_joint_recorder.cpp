#include "robot_joint_recorder.hpp"

JointRecorder::JointRecorder(double record_rate_hz)
: recording_(false), last_record_time_(0, 0, RCL_ROS_TIME)
{
    if (record_rate_hz <= 0.0) {
        record_period_ = 0.01; // 默认 100Hz
    } else {
        record_period_ = 1.0 / record_rate_hz;
    }
}

bool JointRecorder::start(const std::string &file_path,
                          const sensor_msgs::msg::JointState::SharedPtr &sample_msg)
{
    if (recording_) {
        RCLCPP_WARN(rclcpp::get_logger("JointRecorder"), "Already recording!");
        return false;
    }
    auto dir = std::filesystem::path(file_path).parent_path();
    RCLCPP_INFO(rclcpp::get_logger("JointRecorder"), "Saving to path: %s", dir.c_str());
    if (!std::filesystem::exists(dir)) {
        std::filesystem::create_directories(dir);
    }

    if (std::filesystem::exists(file_path)) {
        std::filesystem::remove(file_path);
    }
    

    file_.open(file_path, std::ios::out);
    if (!file_.is_open()) {
        RCLCPP_ERROR(rclcpp::get_logger("JointRecorder"), "Failed to open file: %s", file_path.c_str());
        return false;
    }

    // 写表头
    file_ << "timestamp";
    for (size_t i = 0; i < sample_msg->position.size(); i++) file_ << ",pos" << i;
    for (size_t i = 0; i < sample_msg->velocity.size(); i++) file_ << ",vel" << i;
    for (size_t i = 0; i < sample_msg->effort.size(); i++)  file_ << ",effort" << i;
    file_ << "\n";

    recording_ = true;
    last_record_time_ = rclcpp::Clock(RCL_ROS_TIME).now();
    rec_file_path_= file_path;
    first_record_time_ = last_record_time_;
    RCLCPP_INFO(rclcpp::get_logger("JointRecorder"), "Started recording to %s", file_path.c_str());
    // 启动后台写线程
    writer_thread_ = std::thread(&JointRecorder::writerLoop, this);
    return true;
}
void JointRecorder::stop()
{
    if (!recording_)
    return;

    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        stop_flag_ = true;
    }
    queue_cv_.notify_all();

    if (writer_thread_.joinable())
        writer_thread_.join();

    file_.close();
    recording_ = false; 
}

void JointRecorder::enqueue(const sensor_msgs::msg::JointState::SharedPtr &msg)
{
    if (!recording_)
        return;
    rclcpp::Time msg_time(msg->header.stamp);
    double dt = (msg_time - last_record_time_).seconds();
        
    if (dt < record_period_) {
        return; 
    }
    last_record_time_ = msg_time;
    std::lock_guard<std::mutex> lock(queue_mutex_);
    msg_queue_.push(msg);
    queue_cv_.notify_one();
}

void JointRecorder::writerLoop()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(queue_mutex_);
        queue_cv_.wait(lock, [this]()
                       { return !msg_queue_.empty() || stop_flag_; });

        if (stop_flag_ && msg_queue_.empty())
            break;

        auto msg = msg_queue_.front();
        msg_queue_.pop();
        lock.unlock();
        rclcpp::Time msg_time(msg->header.stamp);

        // 计算时间戳
        double t = (msg_time - first_record_time_).seconds();

        // 写数据
        file_ << std::fixed << std::setprecision(6) << t;
        for (auto p : msg->position)
            file_ << "," << p;
        for (auto v : msg->velocity)
            file_ << "," << v;
        file_ << std::endl;
    }
}

// 移动平均滤波函数
auto movingAverage = [](const std::vector<double> &data, int window_size = 10) {
    std::vector<double> result(data.size());
    int half = window_size / 2;
    for (size_t i = 0; i < data.size(); i++)
    {
        double sum = 0.0;
        int count = 0;
        //result[i] = data[i];
        for (int j = -half; j <= half; j++){
            int idx = static_cast<int>(i) + j;
            if (idx >= 0 && idx < (int)data.size())
            {
                sum += data[idx];
                count++;
            }
        }
        result[i] = sum / count;
    }
    return result;
};
trajectory_msgs::msg::JointTrajectory JointRecorder::repeat(const std::string &txt_file_path)
{
    std::ifstream ifs(txt_file_path);
    if (!ifs.is_open())
    {
        RCLCPP_ERROR(rclcpp::get_logger("JointRecorder"), "Failed to open trajectory file: %s", txt_file_path.c_str());
        return trajectory_msgs::msg::JointTrajectory();
    }

    std::string line;
    // 读表头
    std::getline(ifs, line);

    trajectory_msgs::msg::JointTrajectory traj_msg;
    traj_msg.joint_names = {"joint1", "joint2", "joint3", "joint4", "joint5", "joint6"};

    // 第一行时间，用于相对时间
    double t0 = 0.0;
    bool first_line = true;
    std::vector<double> times;
    std::vector<std::vector<double>> all_positions(6);
    std::vector<std::vector<double>> all_velocities(6);
    std::vector<std::vector<double>> all_efforts(6);
    //读出所有点
    while (std::getline(ifs, line))
    {
        std::stringstream ss(line);
        std::string token;

        // 读取时间戳
        std::getline(ss, token, ',');
        double t = std::stod(token);
        if (first_line)
        {
            t0 = t;
            first_line = false;
        }

        trajectory_msgs::msg::JointTrajectoryPoint point;
        // 读位置
        for (size_t i = 0; i < 6; i++)
        {
            if (!std::getline(ss, token, ',')) break;
            all_positions[i].push_back(std::stod(token));
        }

        // 读速度
        for (size_t i = 0; i < 6; i++)
        {
            if (!std::getline(ss, token, ',')) break;
            all_velocities[i].push_back(std::stod(token)/57.3);
            
        }

        // 读 effort（可选）
        for (size_t i = 0; i < 6; i++)
        {
            if (!std::getline(ss, token, ',')) break;
            all_efforts[i].push_back(std::stod(token));
        }

        // 填充时间
        times.push_back(t - t0);
    }

    ifs.close();

    // 对每个关节的位置和速度做滤波
    // for (size_t i = 0; i < 6; i++)
    // {
    //     all_velocities[i] = movingAverage(all_velocities[i], 5);
    // }
    // // ===== 用滤波后的速度重新积分计算位置 =====
    // for (size_t i = 0; i < 6; i++)
    // {
    //     std::vector<double> pos_filtered;
    //     pos_filtered.resize(all_velocities[i].size());
    //     pos_filtered[0] = all_positions[i][0];  // 起点位置保持一致

    //     for (size_t k = 1; k < all_velocities[i].size(); ++k)
    //     {
    //         double dt = times[k] - times[k - 1];
    //         double v_prev = all_velocities[i][k - 1];
    //         double v_curr = all_velocities[i][k];
    //         pos_filtered[k] = pos_filtered[k - 1] + 0.5 * (v_prev + v_curr) * dt ;
    //     }

    //     // 替换原始位置数据
    //     all_positions[i] = pos_filtered;
    // }

    // 构造 JointTrajectory
    for (size_t idx = 0; idx < times.size(); idx++)
    {
        trajectory_msgs::msg::JointTrajectoryPoint point;
        for (size_t j = 0; j < 6; j++)
        {
            point.positions.push_back(all_positions[j][idx]);
            point.velocities.push_back(all_velocities[j][idx]);
            point.effort.push_back(0.0);
        }
        point.time_from_start = rclcpp::Duration::from_seconds(times[idx]);
        traj_msg.points.push_back(point);
    }
    RCLCPP_INFO(rclcpp::get_logger("JointRecorder"), "Loaded trajectory with %zu points", traj_msg.points.size());
    return traj_msg;
}
