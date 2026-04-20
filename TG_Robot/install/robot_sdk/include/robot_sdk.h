#ifndef __ROBOT_SDK_H__
#define __ROBOT_SDK_H__

#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/buffer_core.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2/LinearMath/Vector3.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/u_int8.hpp>
#include <rclcpp/rclcpp.hpp>
#include "robot_interfaces/srv/sdk_recv.hpp"
#include <robot_interfaces/msg/arm_state.hpp>
#include "robot_interfaces/msg/gripper_control.hpp"
#include "robot_interfaces/msg/key_pressed_action.hpp"
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/robot_state/robot_state.h>
#include <std_msgs/msg/int32_multi_array.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/pose_stamped.h>
#include <sensor_msgs/msg/joint_state.hpp>
enum WorkingMode
{
    BACK_TO_START = 0,
    DISABLE = 1,
    JOINT_CONTROL = 2,
    CARTESIAN = 3,
    MOVE_J = 4,
    MOVE_L = 5,
    MOVE_C = 6,
    TEACH = 7,
    TEACH_REPEAT = 8,
    STATE_OPERATION = 9,
    LOAD_STATE = 10,
    BACK_TO_INITIAL = 11,
    MOTOR_ZERO_POSITION_SET = 12,
    GRIPPER_CONTROL = 13,
    USER_PARAM_SET = 14,
    USER_PARAM_GET = 15,
    TEACH_STOP = 16,
    POSE_PRINT = 17,
    JOINT_STOP = 18,
    SPEED_CONFIG = 19
};

#define JOINT1_POSITIVE 41
#endif