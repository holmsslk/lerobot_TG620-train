#include "robot_can_node.hpp"
void RobotCanNode::traj_get_callback(const trajectory_msgs::msg::JointTrajectory::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received trajectory with %zu points", msg->points.size());

    // push into pool
    traj_pool_.push(*msg);
    RCLCPP_INFO(this->get_logger(), "Trajectory added to pool. Pool size: %zu", traj_pool_.size());

    // if not executing, start executing next
    if (!executing_)
    {
        execute_next_traj();
    }
}

void RobotCanNode::execute_next_traj()
{
    if (traj_pool_.empty())
    {
        RCLCPP_INFO(this->get_logger(), "No trajectories in pool.");
        executing_ = false;
        uint8_t last_status = can_driver_->get_button_status();
        if (static_cast<int>(motor_driver::BUTTONSTATUS::TEACH_REPEAT) == last_status)
        {
            can_driver_->send_button();
        }
        return;
    }

    executing_ = true;
    current_traj_ = traj_pool_.front();
    traj_pool_.pop();

    points_ = current_traj_.points;
    current_idx_ = 0;
    log_buffer_.clear();

    // open log file (optionally you can make file name unique or timestamped)
    joint_log_file_.open("joint_traj_log.txt", std::ios::out | std::ios::app);
    joint_log_file_ << std::fixed << std::setprecision(6);
    start_time_ = this->now();
    joint_log_file_ << start_time_.seconds() << std::endl;

    // start timer with 1ms period (adjust to your real control rate)
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(1),
        std::bind(&RobotCanNode::send_next_point, this));

    RCLCPP_INFO(this->get_logger(), "Started executing trajectory (%zu points)", points_.size());
}

void RobotCanNode::send_next_point()
{
    if (current_idx_ >= points_.size())
    {
        // finished
        if (timer_)
            timer_->cancel();
        auto end_time = this->now();
        auto duration = end_time - start_time_;

        RCLCPP_INFO(this->get_logger(),
                    "Trajectory finished. Time cost: %.3f sec, points: %zu",
                    duration.seconds(), points_.size());

        for (auto &line : log_buffer_)
            joint_log_file_ << line;
        joint_log_file_.close();
        executing_ = false;
        // immediately execute next in pool if exists
        execute_next_traj();
        return;
    }

    auto &point = points_[current_idx_];
    auto now = this->now();
    rclcpp::Duration elapsed = now - start_time_;

    // wait until time_from_start
    if (elapsed < point.time_from_start)
    {
        return;
    }

    // send control for each joint position/vel/effort
    for (size_t i = 0; i < point.positions.size(); ++i)
    {
        uint8_t motor_id = static_cast<uint8_t>(i + 1);
        std::optional<float> pos = point.positions[i];
        std::optional<float> vel = (i < point.velocities.size()) ? std::optional<float>(point.velocities[i]) : std::nullopt;
        std::optional<float> eff = (i < point.effort.size()) ? std::optional<float>(point.effort[i]) : std::nullopt;//
        uint8_t kp = 50;
        uint8_t kd = 5;
        can_driver_->send_motor_control(motor_id,
                                        motor_driver::MotorEnableMode::MOTOR_ENABLE,
                                        motor_driver::MotorControlMode::EFFORT_POSITION_MODE,
                                        pos, vel, eff, kp, kd);
    }

    // buffer log line (do not write to disk every time for performance)
    std::ostringstream oss;
    oss << elapsed.seconds();
    for (size_t i = 0; i < point.positions.size(); ++i)
    {
        oss << " " << point.positions[i];
        if (i < point.velocities.size())
            oss << " " << point.velocities[i];
        else
            oss << " 0.0";
        if (i < point.effort.size())
            oss << " " << point.effort[i];
        else
            oss << " 0.0";
    }
    oss << "\n";
    log_buffer_.push_back(oss.str());

    current_idx_++;
}
