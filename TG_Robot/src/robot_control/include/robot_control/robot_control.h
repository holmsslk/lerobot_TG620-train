#ifndef __ROBOT_CONTROL_H__
#define __ROBOT_CONTROL_H__

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "control_msgs/action/follow_joint_trajectory.hpp"
#include "robot_interfaces/msg/robot_control_msg.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "robot_interfaces/srv/compute_gravity.hpp"
// #include "sensor_msgs/msg/joint_state.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip> // 格式化输出
#include <std_msgs/msg/bool.hpp>
#include <queue>
#include <mutex>
#include <thread>
using namespace std;

class RobotControl : public rclcpp::Node
{
public:
    using FollowJointTrajectory = control_msgs::action::FollowJointTrajectory;
    using GoalHandleFollowJointTrajectory = rclcpp_action::ServerGoalHandle<FollowJointTrajectory>;
    explicit RobotControl(std::string name);
    ~RobotControl() {}

private:
    robot_interfaces::msg::RobotControlMsg motor_control_msg;
    rclcpp_action::Server<FollowJointTrajectory>::SharedPtr action_server_;
    // rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pos_publisher;
    rclcpp::Publisher<robot_interfaces::msg::RobotControlMsg>::SharedPtr motor_control_pub_;
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr State_Timer;
    rclcpp::Client<robot_interfaces::srv::ComputeGravity>::SharedPtr gravity_client_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr done_sub_;
    std::mutex queue_mutex_;
    bool trajectory_running_ = false;
    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const FollowJointTrajectory::Goal> goal);
    rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleFollowJointTrajectory> goal_handle);
    void execute_move(const std::shared_ptr<GoalHandleFollowJointTrajectory> goal_handle);
    void handle_accepted(const std::shared_ptr<GoalHandleFollowJointTrajectory> goal_handle);
    void record(const std::shared_ptr<const control_msgs::action::FollowJointTrajectory::Goal> goal);
    std::vector<std::vector<double>> call_gravity_batch_service(
        const std::vector<std::string> &joint_names,
        const std::vector<std::vector<double>> &positions_list);
};
#endif /* __ROBOT_CONTROL_H__ */
