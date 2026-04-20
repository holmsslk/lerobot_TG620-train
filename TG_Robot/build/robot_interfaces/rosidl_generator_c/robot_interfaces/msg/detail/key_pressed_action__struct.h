// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/KeyPressedAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__KEY_PRESSED_ACTION__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__KEY_PRESSED_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/KeyPressedAction in the package robot_interfaces.
typedef struct robot_interfaces__msg__KeyPressedAction
{
  uint8_t key_code;
  bool is_pressed;
} robot_interfaces__msg__KeyPressedAction;

// Struct for a sequence of robot_interfaces__msg__KeyPressedAction.
typedef struct robot_interfaces__msg__KeyPressedAction__Sequence
{
  robot_interfaces__msg__KeyPressedAction * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__KeyPressedAction__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__KEY_PRESSED_ACTION__STRUCT_H_
