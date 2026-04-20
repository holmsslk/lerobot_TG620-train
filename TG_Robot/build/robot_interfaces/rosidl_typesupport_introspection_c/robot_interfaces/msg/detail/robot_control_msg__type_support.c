// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_interfaces:msg/RobotControlMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_interfaces/msg/detail/robot_control_msg__rosidl_typesupport_introspection_c.h"
#include "robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_interfaces/msg/detail/robot_control_msg__functions.h"
#include "robot_interfaces/msg/detail/robot_control_msg__struct.h"


// Include directives for member types
// Member `motor_enable_flag`
// Member `motor_mode`
// Member `position`
// Member `velocity`
// Member `effort`
// Member `kp`
// Member `kd`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_interfaces__msg__RobotControlMsg__init(message_memory);
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_fini_function(void * message_memory)
{
  robot_interfaces__msg__RobotControlMsg__fini(message_memory);
}

size_t robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__motor_enable_flag(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__motor_enable_flag(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__motor_enable_flag(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__motor_enable_flag(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__motor_enable_flag(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__motor_enable_flag(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__motor_enable_flag(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__motor_enable_flag(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

size_t robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__motor_mode(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__motor_mode(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__motor_mode(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__motor_mode(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__motor_mode(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__motor_mode(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__motor_mode(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__motor_mode(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

size_t robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__position(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__position(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__position(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__position(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__position(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__position(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__velocity(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__velocity(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__velocity(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__velocity(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__velocity(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__velocity(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__effort(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__effort(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__effort(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__effort(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__effort(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__effort(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__effort(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__effort(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__kp(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__kp(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__kp(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__kp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__kp(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__kp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__kp(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__kp(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

size_t robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__kd(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__kd(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__kd(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__kd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__kd(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__kd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__kd(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__kd(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_message_member_array[7] = {
  {
    "motor_enable_flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__RobotControlMsg, motor_enable_flag),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__motor_enable_flag,  // size() function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__motor_enable_flag,  // get_const(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__motor_enable_flag,  // get(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__motor_enable_flag,  // fetch(index, &value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__motor_enable_flag,  // assign(index, value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__motor_enable_flag  // resize(index) function pointer
  },
  {
    "motor_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__RobotControlMsg, motor_mode),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__motor_mode,  // size() function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__motor_mode,  // get_const(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__motor_mode,  // get(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__motor_mode,  // fetch(index, &value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__motor_mode,  // assign(index, value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__motor_mode  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__RobotControlMsg, position),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__position,  // size() function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__position,  // get_const(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__position,  // get(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__position,  // fetch(index, &value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__position,  // assign(index, value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__position  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__RobotControlMsg, velocity),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__velocity,  // size() function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__velocity,  // get_const(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__velocity,  // get(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__velocity,  // fetch(index, &value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__velocity,  // assign(index, value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__velocity  // resize(index) function pointer
  },
  {
    "effort",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__RobotControlMsg, effort),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__effort,  // size() function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__effort,  // get_const(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__effort,  // get(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__effort,  // fetch(index, &value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__effort,  // assign(index, value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__effort  // resize(index) function pointer
  },
  {
    "kp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__RobotControlMsg, kp),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__kp,  // size() function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__kp,  // get_const(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__kp,  // get(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__kp,  // fetch(index, &value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__kp,  // assign(index, value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__kp  // resize(index) function pointer
  },
  {
    "kd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__RobotControlMsg, kd),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__size_function__RobotControlMsg__kd,  // size() function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_const_function__RobotControlMsg__kd,  // get_const(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__get_function__RobotControlMsg__kd,  // get(index) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__fetch_function__RobotControlMsg__kd,  // fetch(index, &value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__assign_function__RobotControlMsg__kd,  // assign(index, value) function pointer
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__resize_function__RobotControlMsg__kd  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_message_members = {
  "robot_interfaces__msg",  // message namespace
  "RobotControlMsg",  // message name
  7,  // number of fields
  sizeof(robot_interfaces__msg__RobotControlMsg),
  robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_message_member_array,  // message members
  robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_message_type_support_handle = {
  0,
  &robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_interfaces, msg, RobotControlMsg)() {
  if (!robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_message_type_support_handle.typesupport_identifier) {
    robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_interfaces__msg__RobotControlMsg__rosidl_typesupport_introspection_c__RobotControlMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
