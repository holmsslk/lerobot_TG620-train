// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/MoveCAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose_array'
#include "std_msgs/msg/detail/float64_multi_array__struct.h"

/// Struct defined in msg/MoveCAction in the package robot_interfaces.
typedef struct robot_interfaces__msg__MoveCAction
{
  std_msgs__msg__Float64MultiArray pose_array;
  bool must_pass_through_middle;
} robot_interfaces__msg__MoveCAction;

// Struct for a sequence of robot_interfaces__msg__MoveCAction.
typedef struct robot_interfaces__msg__MoveCAction__Sequence
{
  robot_interfaces__msg__MoveCAction * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__MoveCAction__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__STRUCT_H_
