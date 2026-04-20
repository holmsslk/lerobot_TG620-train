#ifndef __ROBOT_CAN_NODE_HPP__
#define __ROBOT_CAN_NODE_HPP__

#include "rclcpp/rclcpp.hpp"
#include "robot_interfaces/msg/robot_control_msg.hpp"
#include "robot_interfaces/msg/generic_motor_parameter.hpp"
#include "robot_interfaces/msg/generic_motor_operation.hpp"
#include "robot_interfaces/msg/gripper_control.hpp"
#include "std_msgs/msg/u_int8_multi_array.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/bool.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "robot_can_driver.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "can_receiver_driver.hpp"
#include "common_defs.hpp"
#include <queue>
#include <fstream>
#include <sstream>
typedef struct
{
    uint8_t motor_id;
    std::optional<motor_driver::MotorFeedbackType> type;
} MotorRequestTask;

class RobotCanNode : public rclcpp::Node
{
public:
    explicit RobotCanNode(const std::string &node_name);

private:
    // rclcpp::QoS qos;
    void motor_cmd_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
    void motor_control_callback(const robot_interfaces::msg::RobotControlMsg::SharedPtr msg);
    void publish_joint_states();
    void handle_button_event(uint8_t button_mode);
    void button_status_callback(const std_msgs::msg::UInt8::SharedPtr msg);
    void motor_request_timer_callback();

    // void can_send_timer_callback();
    void gripper_control_callback(const robot_interfaces::msg::GripperControl::SharedPtr msg);
    void motor_parameter_set_callback(const robot_interfaces::msg::GenericMotorParameter::SharedPtr msg);
    void motor_operation_set_callback(const robot_interfaces::msg::GenericMotorOperation::SharedPtr msg);
    void debug_parameter_set_callback(const robot_interfaces::msg::GenericMotorParameter::SharedPtr msg);
    void disable_motor(uint8_t motor_id);
    void write_param_and_save(uint8_t motor_id, motor_driver::ParamAddr addr, int32_t int_value);
    void write_param_and_save(uint8_t motor_id, motor_driver::ParamAddr addr, float float_value);
    void send_op_and_save(uint8_t motor_id, motor_driver::FuncOpCode op_code);
    void write_debug_param(uint8_t motor_id, motor_driver::DebugParamAddr addr, int32_t int_value);
    void write_debug_param(uint8_t motor_id, motor_driver::DebugParamAddr addr, float float_value);
    void motor_parameter_get_callback(const std_msgs::msg::UInt8 msg);
    void debug_parameter_get_callback(const std_msgs::msg::UInt8 msg);

    rclcpp::Subscription<robot_interfaces::msg::RobotControlMsg>::SharedPtr motor_control_sub_;
    rclcpp::Subscription<robot_interfaces::msg::GripperControl>::SharedPtr gripper_control_sub_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_sub_;
    rclcpp::Subscription<trajectory_msgs::msg::JointTrajectory>::SharedPtr traj_get_sub_;

    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr mode_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr teach_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr teachrepeat_pub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr traj_status_pub_;

    rclcpp::TimerBase::SharedPtr joint_state_timer_;
    rclcpp::TimerBase::SharedPtr motor_request_timer_;
    rclcpp::TimerBase::SharedPtr can_send_timer_;
    rclcpp::TimerBase::SharedPtr button_state_timer_;

    rclcpp::Subscription<robot_interfaces::msg::GenericMotorParameter>::SharedPtr motor_parameter_sub_;
    rclcpp::Subscription<robot_interfaces::msg::GenericMotorOperation>::SharedPtr motor_operation_sub_;
    rclcpp::Subscription<robot_interfaces::msg::GenericMotorParameter>::SharedPtr debug_parameter_sub_;
    rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr motor_parameter_get_sub_;
    rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr debug_parameter_get_sub_;
    rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr button_status_sub_;
    std::shared_ptr<motor_driver::RobotCanDriver> can_driver_;
    std::queue<MotorRequestTask> motor_request_queue_;

    bool use_canfd_;
    uint8_t last_mode = 0;

    // traj control
    void traj_get_callback(const trajectory_msgs::msg::JointTrajectory::SharedPtr msg);
    void send_next_point();
    void execute_next_traj();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Time start_time_;
    std::ofstream joint_log_file_;
    std::vector<std::string> log_buffer_;
    // Trajectory pool and current execution
    std::queue<trajectory_msgs::msg::JointTrajectory> traj_pool_;
    trajectory_msgs::msg::JointTrajectory current_traj_;
    std::vector<trajectory_msgs::msg::JointTrajectoryPoint> points_;
    size_t current_idx_{0};
    bool executing_{false};
};

#endif
