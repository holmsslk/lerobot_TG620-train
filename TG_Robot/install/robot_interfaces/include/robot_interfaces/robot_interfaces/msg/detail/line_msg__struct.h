// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/LineMsg.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'initial_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/LineMsg in the package robot_interfaces.
typedef struct robot_interfaces__msg__LineMsg
{
  /// 0: line 1: circle
  uint8_t type;
  /// 0: start line pose  1: start center pose
  geometry_msgs__msg__Pose initial_pose;
  /// delta position with respect to the initial_pose
  float delta_x;
  float delta_y;
  float delta_z;
  /// 0: without any meaning  1: radius of the circle
  float radius;
} robot_interfaces__msg__LineMsg;

// Struct for a sequence of robot_interfaces__msg__LineMsg.
typedef struct robot_interfaces__msg__LineMsg__Sequence
{
  robot_interfaces__msg__LineMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__LineMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__STRUCT_H_
