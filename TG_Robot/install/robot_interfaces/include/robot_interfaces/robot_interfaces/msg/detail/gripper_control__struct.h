// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/GripperControl.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__GRIPPER_CONTROL__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__GRIPPER_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/GripperControl in the package robot_interfaces.
typedef struct robot_interfaces__msg__GripperControl
{
  /// 0:智元 1：大寰 2：透传
  uint8_t type;
  double position;
  double velocity;
  double effort;
  rosidl_runtime_c__uint8__Sequence data;
} robot_interfaces__msg__GripperControl;

// Struct for a sequence of robot_interfaces__msg__GripperControl.
typedef struct robot_interfaces__msg__GripperControl__Sequence
{
  robot_interfaces__msg__GripperControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__GripperControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__GRIPPER_CONTROL__STRUCT_H_
