#ifndef __ROBOT_STATE_MACHINE_H__
#define __ROBOT_STATE_MACHINE_H__

#include <rclcpp/rclcpp.hpp>
//#include <rclcpp/qos.hpp>
#include <std_msgs/msg/int8.hpp>
#include <std_msgs/msg/u_int8.hpp>
#include "std_msgs/msg/u_int8_multi_array.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/bool.hpp"
#include "std_msgs/msg/string.hpp"
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/pose.h>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <rosbag2_cpp/writer.hpp>
#include <rosbag2_cpp/reader.hpp>
#include <rosbag2_cpp/storage_options.hpp>
#include <rosbag2_cpp/converter_options.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/msg/move_it_error_codes.hpp>
#include <robot_interfaces/msg/robot_control_msg.hpp>
#include <robot_interfaces/msg/move_c_action.hpp>
#include <robot_interfaces/msg/state_action.hpp>
#include <robot_interfaces/msg/key_pressed_action.hpp>
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "robot_interfaces/msg/generic_motor_parameter.hpp"
#include "robot_interfaces/msg/generic_motor_operation.hpp"
#include "robot_interfaces/msg/gripper_control.hpp"
#include <urdf/model.h>
#include "common_defs.hpp"
#include <chrono>
#include <thread>
#include <sqlite3.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "robot_kinematics.hpp"
#include <fstream>
#include "robot_joint_recorder.hpp"
#include <iomanip>
#include <chrono>
#include <rclcpp_action/rclcpp_action.hpp>
#include <control_msgs/action/follow_joint_trajectory.hpp>
#define BACKTOSTART 0
#define DISABLE 1
#define JOINTCONTROL 2
#define CARTESIAN 3
#define MOVEJ 4
#define MOVEL 5
#define MOVEC 6
#define TEACH 7
#define TEACHREPEAT 8
#define STATEOPERATION 9
#define LOADSTATE 10
#define BACKTOINITIAL 11
#define MOTORZEROPOSSET 12
#define GRIPPERCONTROL 13
#define USERPARAMSET   14
#define USERPARAMGET   15
#define TEACH_STOP     16

#define JOINT1_POSITIVE 41
#define JOINT1_NEGATIVE 42
#define JOINT2_POSITIVE 43
#define JOINT2_NEGATIVE 44
#define JOINT3_POSITIVE 45
#define JOINT3_NEGATIVE 46
#define JOINT4_POSITIVE 47
#define JOINT4_NEGATIVE 48
#define JOINT5_POSITIVE 49
#define JOINT5_NEGATIVE 50
#define JOINT6_POSITIVE 51
#define JOINT6_NEGATIVE 52
#define GRIPPER_OPEN 53
#define GRIPPER_CLOSE 54
#define SERVO_MIX_KP  80
#define SERVO_MIX_KI  81
#define SERVO_MIX_KD  82

#define PI_ 3.141592654f
#define JOINT_ROTATE_POSITIVE_SPEED 0.08726f
#define JOINT_ROTATE_NEGATIVE_SPEED -0.08726f

typedef enum {
    CURRENT_MODE = 0x02,
    EFFORT_POSITION_MODE = 0x03,
    SPEED_MODE = 0x04,
    POSITION_ABS_MODE = 0x05,
    POSITION_INC_MODE = 0x06
} Motor_Control_Mode_e;

typedef enum {
    MOTOR_ENABLE = 0x01,
    MOTOR_DISABLE = 0x00
} Motor_Enable_Mode_e;

typedef enum {
    DIRECTION = 0x01,
    ORIENTATION = 0x02
} Robotic_Arm_Move_Type_e;

using FollowJointTrajectory = control_msgs::action::FollowJointTrajectory;
class StateMachine : public rclcpp :: Node {
    public:
        explicit StateMachine(std::string node_name);
        void post_init();
        ~StateMachine(){};
    private:
        // Kinematics Example
        std::shared_ptr<RobotKinematics> kinematics_;
        rclcpp::QoS qos;
        // State Management
        uint8_t current_mode_;
        rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr mode_sub;
        rclcpp::Subscription<robot_interfaces::msg::KeyPressedAction>::SharedPtr jointctrl_sub_;
        rclcpp::Subscription<robot_interfaces::msg::KeyPressedAction>::SharedPtr cartesian_sub_;
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr movej_sub_;
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr movel_sub_;
        rclcpp::Subscription<robot_interfaces::msg::MoveCAction>::SharedPtr movec_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr teach_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr teachrepeat_sub_;
        rclcpp::Subscription<robot_interfaces::msg::StateAction>::SharedPtr state_sd_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr state_load_sub_;
        rclcpp::Publisher<robot_interfaces::msg::GenericMotorParameter>::SharedPtr debug_param_msg_pub;
        rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SharedPtr client_;
        /* JOINTCTRL mode */
        std::thread jointctrl_thread_;
        std::atomic<bool> stop_jointctrl_thread_{false};
        std::atomic<bool> jointctrl_thread_running_{false};
        std::mutex jointctrl_mutex_;
        int active_joint_index_ = -1;
        float active_joint_speed_ = 0.0f;

        /* CARTESIAN mode */
        std::thread cartesian_thread_;
        std::atomic<bool> stop_cartesian_thread_{false};
        std::atomic<bool> cartesian_thread_running_{false};
        std::mutex cartesian_mutex_;
        Direction active_twist_direction_ = Direction::NONE;

        /* MOVEJ / MOVEL / MOVEC mode */

        /* TEACH / TEACH REPEAT mode */
        std::atomic_bool playback_stop_flag_;
        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_states_sub_;
        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr gravity_sub;
        rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr raw_traj_pub_;
        /* SAVE / LOAD STATE mode */

        rclcpp::Publisher<robot_interfaces::msg::RobotControlMsg>::SharedPtr motor_msg_pub;
        

        
        /* Teach and Teach Repeat*/
        sensor_msgs::msg::JointState::SharedPtr latest_joint_states_;
        std::unique_ptr<rosbag2_cpp::Writer> teach_bag_writer_;
        std::unique_ptr<rosbag2_cpp::Reader> play_bag_reader_;
        std::ofstream teach_txt_file_;

        uint32_t current_count_;
        bool recording_;

        void working_mode_callback(const std_msgs::msg::UInt8::SharedPtr msg);
        
        /* JOINTCONTROL mode */
        void jointctrl_motor_mode(const uint8_t joint_index, const float speed);
        void jointctrl_motor_mode_servo(const uint8_t joint_index, const float speed);
        void jointctrl_thread();
        void jointctrl_action_callback(const robot_interfaces::msg::KeyPressedAction::SharedPtr msg);

        /* CARTESIAN mode */
        void cartesian_move_thread();
        void cartesian_action_callback(const robot_interfaces::msg::KeyPressedAction::SharedPtr msg);
        std::vector<double> velocities;
        std::mutex velocities_mutex_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cer_vel_pub_;
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr angular_vel_sub_;
        void angular_vel_callback(const std_msgs::msg::Float64MultiArray vel_msg);

        void movej_action_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
        void movel_action_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
        void movec_action_callback(const robot_interfaces::msg::MoveCAction::SharedPtr msg);
        void joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg);

        /* TEACH and TEACHREPEAT mode */
        void teach_action_callback(const std_msgs::msg::String::SharedPtr msg);
        void teach_repeat_callback(const std_msgs::msg::String::SharedPtr msg);
        void gravity_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
        robot_interfaces::msg::GenericMotorParameter debug_param_msg;
        JointRecorder recorder_;

        /* SAVESTATE and LOADSTATE mode */
        void save_current_state_to_db(const std::string& state_name);
        void delete_state_from_db(const std::string& state_name);
        void load_state_from_db(const std::string& state_name);
        void save_delete_state_callback(const robot_interfaces::msg::StateAction::SharedPtr msg);
        void load_state_callback(const std_msgs::msg::String::SharedPtr msg);

        /*Gripper Control mode*/
        rclcpp::Subscription<robot_interfaces::msg::GripperControl>::SharedPtr gripper_sub_;
        rclcpp::Publisher<robot_interfaces::msg::GripperControl>::SharedPtr gripper_msg_pub;
        void gripper_action_callback(const robot_interfaces::msg::GripperControl::SharedPtr msg);


        /* MOTOR_ZERO_SSET mode */
        rclcpp::Publisher<robot_interfaces::msg::GenericMotorOperation>::SharedPtr motor_op_pub_;
        robot_interfaces::msg::GenericMotorOperation motor_op_msg;

        /*button control*/
        rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr button_states_pub;

        /*usr param set*/
        rclcpp::Subscription<robot_interfaces::msg::GenericMotorParameter>::SharedPtr usr_param_sub_;
        rclcpp::Publisher<robot_interfaces::msg::GenericMotorParameter>::SharedPtr usr_param_pub;
        void usr_param_callback(const robot_interfaces::msg::GenericMotorParameter::SharedPtr msg);
};

#endif
