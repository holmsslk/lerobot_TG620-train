// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/SdkRecv.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'gripper_goal'
// Member 'joint_angles_goal'
// Member 'arm_pose_goal'
// Member 'motion_config'
#include "std_msgs/msg/detail/float64_multi_array__struct.h"
// Member 'gripper_data'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'usr_param'
#include "robot_interfaces/msg/detail/generic_motor_parameter__struct.h"

/// Struct defined in srv/SdkRecv in the package robot_interfaces.
typedef struct robot_interfaces__srv__SdkRecv_Request
{
  /// 机械臂工作模式
  uint8_t working_mode;
  /// 夹爪目标状态
  std_msgs__msg__Float64MultiArray gripper_goal;
  /// 关节目标位置
  std_msgs__msg__Float64MultiArray joint_angles_goal;
  /// 机械臂目标姿态
  std_msgs__msg__Float64MultiArray arm_pose_goal;
  /// 夹爪原生数据
  rosidl_runtime_c__uint8__Sequence gripper_data;
  /// 夹爪类型
  uint8_t gripper_type;
  /// 关节序号
  uint8_t joint_idx;
  /// 转动方向
  uint8_t vel_dir;
  /// 用户配置参数
  robot_interfaces__msg__GenericMotorParameter usr_param;
  /// 速度配置
  std_msgs__msg__Float64MultiArray motion_config;
} robot_interfaces__srv__SdkRecv_Request;

// Struct for a sequence of robot_interfaces__srv__SdkRecv_Request.
typedef struct robot_interfaces__srv__SdkRecv_Request__Sequence
{
  robot_interfaces__srv__SdkRecv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__SdkRecv_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'cur_joint_angles'
// Member 'cur_pos'
// already included above
// #include "std_msgs/msg/detail/float64_multi_array__struct.h"

/// Struct defined in srv/SdkRecv in the package robot_interfaces.
typedef struct robot_interfaces__srv__SdkRecv_Response
{
  bool success;
  /// 关节目标位置
  std_msgs__msg__Float64MultiArray cur_joint_angles;
  /// 当前位姿
  std_msgs__msg__Float64MultiArray cur_pos;
} robot_interfaces__srv__SdkRecv_Response;

// Struct for a sequence of robot_interfaces__srv__SdkRecv_Response.
typedef struct robot_interfaces__srv__SdkRecv_Response__Sequence
{
  robot_interfaces__srv__SdkRecv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__SdkRecv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__STRUCT_H_
