// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/GenericMotorParameter.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GenericMotorParameter in the package robot_interfaces.
typedef struct robot_interfaces__msg__GenericMotorParameter
{
  uint8_t motor_id;
  uint16_t command_type;
  float float_value;
  int32_t int_value;
} robot_interfaces__msg__GenericMotorParameter;

// Struct for a sequence of robot_interfaces__msg__GenericMotorParameter.
typedef struct robot_interfaces__msg__GenericMotorParameter__Sequence
{
  robot_interfaces__msg__GenericMotorParameter * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__GenericMotorParameter__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__STRUCT_H_
