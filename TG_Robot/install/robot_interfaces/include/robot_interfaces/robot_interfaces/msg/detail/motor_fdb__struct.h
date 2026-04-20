// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/MotorFdb.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'motor_enable_flag'
// Member 'motor_fdb_mode'
// Member 'motor_angle_fdb'
// Member 'motor_effort_fdb'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MotorFdb in the package robot_interfaces.
typedef struct robot_interfaces__msg__MotorFdb
{
  rosidl_runtime_c__uint8__Sequence motor_enable_flag;
  rosidl_runtime_c__uint8__Sequence motor_fdb_mode;
  rosidl_runtime_c__float__Sequence motor_angle_fdb;
  rosidl_runtime_c__float__Sequence motor_effort_fdb;
} robot_interfaces__msg__MotorFdb;

// Struct for a sequence of robot_interfaces__msg__MotorFdb.
typedef struct robot_interfaces__msg__MotorFdb__Sequence
{
  robot_interfaces__msg__MotorFdb * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__MotorFdb__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__STRUCT_H_
