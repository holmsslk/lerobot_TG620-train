#include "robot_control.h"
#include "cubic_spline.h"

RobotControl::RobotControl(std::string name) : Node(name)
{
    using namespace std::placeholders;
    gravity_client_ = this->create_client<robot_interfaces::srv::ComputeGravity>("compute_gravity");
    this->action_server_ = rclcpp_action::create_server<FollowJointTrajectory>(
        this, "/arm_controller/follow_joint_trajectory",
        std::bind(&RobotControl::handle_goal, this, _1, _2),
        std::bind(&RobotControl::handle_cancel, this, _1),
        std::bind(&RobotControl::handle_accepted, this, _1));

    publisher_ = this->create_publisher<trajectory_msgs::msg::JointTrajectory>(
        "/joint_trajectory", 10);
}

rclcpp_action::GoalResponse RobotControl::handle_goal(const rclcpp_action::GoalUUID & /*uuid*/, std::shared_ptr<const FollowJointTrajectory::Goal> goal)
{
    std::cout << "---handle goal" << goal->trajectory.joint_names.size() << std::endl;
    std::cout << goal->trajectory.header.frame_id.c_str() << goal->trajectory.header.stamp.sec << goal->trajectory.header.stamp.nanosec << std::endl;
    std::lock_guard<std::mutex> lock(queue_mutex_);
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse RobotControl::handle_cancel(const std::shared_ptr<GoalHandleFollowJointTrajectory> /*goal_handle*/)
{
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    return rclcpp_action::CancelResponse::ACCEPT;
}

// 接受了目标处理句柄，可以用来跟踪和管理执行过程中的目标状态和结果
void RobotControl::handle_accepted(const std::shared_ptr<GoalHandleFollowJointTrajectory> goal_handle)
{
    using std::placeholders::_1;
    // .detach()将新创建的线程与当前线程分离，使得它可以在后台独立运行，不会阻塞当前线程的执行
    std::thread{std::bind(&RobotControl::execute_move, this, _1), goal_handle}.detach();
}
void RobotControl::execute_move(const std::shared_ptr<GoalHandleFollowJointTrajectory> goal_handle)
{
    const auto goal = goal_handle->get_goal();
    auto result = std::make_shared<FollowJointTrajectory::Result>();
    trajectory_msgs::msg::JointTrajectory msg;
    trajectory_msgs::msg::JointTrajectoryPoint point;
    cubicSpline spline;
    record(goal);
    std::vector<std::vector<double>> positions_list;
    std::vector<std::vector<double>> velocity_list;
    std::vector<double> time_list;
    std::vector<std::string> joint_names = goal->trajectory.joint_names;
    spline.Traj_Generate(goal, positions_list, velocity_list, time_list);
    if (positions_list.empty())
    {
        RCLCPP_WARN(rclcpp::get_logger("gravity_compensator_client"), "positions_list is empty!");
    }
    auto efforts_list = call_gravity_batch_service(joint_names, positions_list);
    if (efforts_list.size() != positions_list.size())
    {
        RCLCPP_ERROR(this->get_logger(), "Gravity batch service returned size mismatch!");
        goal_handle->abort(result);
        return;
    }
    std::ofstream outfile("spline_points.txt"); // 覆盖写
    if (!outfile.is_open())
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to open trajectory_points.txt for writing!");
        return;
    }
    for (size_t i = 0; i < efforts_list.size(); i++)
    {
        point.positions.resize(6);
        point.velocities.resize(6);
        point.effort.resize(6);
        // 写入位置和速度到文件
        outfile << "Point " << i << " positions: ";
        for (int j = 0; j < 6; j++)
        {
            point.positions[j] = positions_list[i][j];
            point.velocities[j] = velocity_list[i][j];
            point.effort[j] = efforts_list[i][j];
            outfile << point.positions[j] << " ";
        }
        outfile << " | velocities: ";
        for (int j = 0; j < 6; j++)
        {
            outfile << point.velocities[j] << " ";
        }
        double t = time_list.at(i);
        point.time_from_start.sec = static_cast<int32_t>(t);
        point.time_from_start.nanosec = static_cast<uint32_t>((t - point.time_from_start.sec) * 1e9);
        msg.points.push_back(point);
        outfile << " | time: " << t << std::endl;
    }
    publisher_->publish(msg);

    // 发布轨迹信息
    result->error_code = 0;
    result->error_string = "success";
    goal_handle->succeed(result);
    RCLCPP_INFO(this->get_logger(), "Goal Succeeded");
}
std::vector<std::vector<double>> RobotControl::call_gravity_batch_service(
    const std::vector<std::string> &joint_names,
    const std::vector<std::vector<double>> &positions_list)
{
    auto request = std::make_shared<robot_interfaces::srv::ComputeGravity::Request>();
    for (size_t i = 0; i < positions_list.size(); ++i)
    {
        sensor_msgs::msg::JointState js;
        js.name = joint_names;
        js.position = positions_list[i];
        request->joint_trajectory.push_back(js);
    }

    if (!gravity_client_->wait_for_service(1s))
    {
        RCLCPP_ERROR(this->get_logger(), "Gravity batch service not available!");
        return std::vector<std::vector<double>>(positions_list.size(),
                                                std::vector<double>(joint_names.size(), 0.0));
    }

    auto future = gravity_client_->async_send_request(request);
    if (future.wait_for(1s) != std::future_status::ready)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to call gravity batch service!");
        return std::vector<std::vector<double>>(positions_list.size(), std::vector<double>(joint_names.size(), 0.0));
    }
    std::vector<std::vector<double>> tau_list;
    auto resp = future.get();
    for (const auto &js : resp->efforts)
    {
        tau_list.push_back(js.effort); // 每帧的力矩
    }
    return tau_list;
}
void RobotControl::record(const std::shared_ptr<const control_msgs::action::FollowJointTrajectory::Goal> goal)
{
    RCLCPP_INFO(this->get_logger(), "Received trajectory with %zu points", goal->trajectory.points.size());

    std::ofstream outfile("trajectory_points.txt"); // 覆盖写
    if (!outfile.is_open())
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to open trajectory_points.txt for writing!");
        return;
    }

    for (size_t i = 0; i < goal->trajectory.points.size(); i++)
    {
        const auto &point = goal->trajectory.points[i];
        double t = point.time_from_start.sec + point.time_from_start.nanosec * 1e-9;

        // ---- 打印到日志 ----
        // RCLCPP_INFO(this->get_logger(), "Point %zu (t=%.3f s)", i, t);

        // ---- 写到文件 ----
        outfile << "Point " << i << " (t=" << std::fixed << std::setprecision(3) << t << "s)" << std::endl;

        // Positions
        outfile << "  positions: ";
        for (double v : point.positions)
            outfile << v << " ";
        outfile << std::endl;

        // Velocities
        if (!point.velocities.empty())
        {
            outfile << "  velocities: ";
            for (double v : point.velocities)
                outfile << v << " ";
            outfile << std::endl;
        }

        // Accelerations
        if (!point.accelerations.empty())
        {
            outfile << "  accelerations: ";
            for (double v : point.accelerations)
                outfile << v << " ";
            outfile << std::endl;
        }

        // Effort
        if (!point.effort.empty())
        {
            outfile << "  effort: ";
            for (double v : point.effort)
                outfile << v << " ";
            outfile << std::endl;
        }

        outfile << "---------------------------------" << std::endl;
    }

    outfile.close();
    RCLCPP_INFO(this->get_logger(), "Trajectory points saved to /home/nvidia/trajectory_points.txt");
}
int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotControl>("robot_control");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
