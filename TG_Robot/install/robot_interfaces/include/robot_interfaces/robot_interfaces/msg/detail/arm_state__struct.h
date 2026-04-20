// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/ArmState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'end_effector_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/ArmState in the package robot_interfaces.
/**
  * geometry_msgs/Quaternion end_effector_quat
 */
typedef struct robot_interfaces__msg__ArmState
{
  geometry_msgs__msg__Pose end_effector_pose;
} robot_interfaces__msg__ArmState;

// Struct for a sequence of robot_interfaces__msg__ArmState.
typedef struct robot_interfaces__msg__ArmState__Sequence
{
  robot_interfaces__msg__ArmState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__ArmState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__STRUCT_H_
