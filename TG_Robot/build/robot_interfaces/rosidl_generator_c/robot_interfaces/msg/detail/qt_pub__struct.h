// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/QtPub.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint_group_positions'
// Member 'gripper_msgs'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/QtPub in the package robot_interfaces.
typedef struct robot_interfaces__msg__QtPub
{
  /// 机械臂工作模式
  uint8_t working_mode;
  /// enable or not
  bool enable_flag;
  /// ---------------- Joint Space Planning ----------------
  /// 机械臂目标关节位置
  rosidl_runtime_c__double__Sequence joint_group_positions;
  /// 夹爪信息
  rosidl_runtime_c__uint8__Sequence gripper_msgs;
} robot_interfaces__msg__QtPub;

// Struct for a sequence of robot_interfaces__msg__QtPub.
typedef struct robot_interfaces__msg__QtPub__Sequence
{
  robot_interfaces__msg__QtPub * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__QtPub__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__STRUCT_H_
