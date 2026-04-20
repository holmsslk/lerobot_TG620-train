// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/RobotControlMsg.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ROBOT_CONTROL_MSG__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__ROBOT_CONTROL_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MOTOR_DISABLE'.
/**
  * Constants
 */
enum
{
  robot_interfaces__msg__RobotControlMsg__MOTOR_DISABLE = 0
};

/// Constant 'MOTOR_ENABLE'.
enum
{
  robot_interfaces__msg__RobotControlMsg__MOTOR_ENABLE = 1
};

/// Constant 'CURRENT_MODE'.
enum
{
  robot_interfaces__msg__RobotControlMsg__CURRENT_MODE = 2
};

/// Constant 'EFFORT_POSITION_MODE'.
enum
{
  robot_interfaces__msg__RobotControlMsg__EFFORT_POSITION_MODE = 3
};

/// Constant 'SPEED_MODE'.
enum
{
  robot_interfaces__msg__RobotControlMsg__SPEED_MODE = 4
};

/// Constant 'POSITION_ABS_MODE'.
enum
{
  robot_interfaces__msg__RobotControlMsg__POSITION_ABS_MODE = 5
};

/// Constant 'POSITION_INC_MODE'.
enum
{
  robot_interfaces__msg__RobotControlMsg__POSITION_INC_MODE = 6
};

// Include directives for member types
// Member 'motor_enable_flag'
// Member 'motor_mode'
// Member 'position'
// Member 'velocity'
// Member 'effort'
// Member 'kp'
// Member 'kd'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RobotControlMsg in the package robot_interfaces.
typedef struct robot_interfaces__msg__RobotControlMsg
{
  /// 0-disable  1-enable
  rosidl_runtime_c__uint8__Sequence motor_enable_flag;
  /// 04-velocity   05-position   02-effort
  rosidl_runtime_c__uint8__Sequence motor_mode;
  rosidl_runtime_c__double__Sequence position;
  rosidl_runtime_c__double__Sequence velocity;
  rosidl_runtime_c__double__Sequence effort;
  rosidl_runtime_c__uint8__Sequence kp;
  rosidl_runtime_c__uint8__Sequence kd;
} robot_interfaces__msg__RobotControlMsg;

// Struct for a sequence of robot_interfaces__msg__RobotControlMsg.
typedef struct robot_interfaces__msg__RobotControlMsg__Sequence
{
  robot_interfaces__msg__RobotControlMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__RobotControlMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ROBOT_CONTROL_MSG__STRUCT_H_
