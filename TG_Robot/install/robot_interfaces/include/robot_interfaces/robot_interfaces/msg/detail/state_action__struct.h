// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/StateAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SAVE'.
/**
  * Constants
 */
enum
{
  robot_interfaces__msg__StateAction__SAVE = 0
};

/// Constant 'DELETE'.
enum
{
  robot_interfaces__msg__StateAction__DELETE = 1
};

// Include directives for member types
// Member 'state_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/StateAction in the package robot_interfaces.
typedef struct robot_interfaces__msg__StateAction
{
  rosidl_runtime_c__String state_name;
  /// 0: save, 1: delete
  uint8_t operation_mode;
} robot_interfaces__msg__StateAction;

// Struct for a sequence of robot_interfaces__msg__StateAction.
typedef struct robot_interfaces__msg__StateAction__Sequence
{
  robot_interfaces__msg__StateAction * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__StateAction__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__STRUCT_H_
