// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_interfaces:msg/MotorFdb.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_interfaces/msg/detail/motor_fdb__rosidl_typesupport_introspection_c.h"
#include "robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_interfaces/msg/detail/motor_fdb__functions.h"
#include "robot_interfaces/msg/detail/motor_fdb__struct.h"


// Include directives for member types
// Member `motor_enable_flag`
// Member `motor_fdb_mode`
// Member `motor_angle_fdb`
// Member `motor_effort_fdb`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_interfaces__msg__MotorFdb__init(message_memory);
}

void robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_fini_function(void * message_memory)
{
  robot_interfaces__msg__MotorFdb__fini(message_memory);
}

size_t robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__size_function__MotorFdb__motor_enable_flag(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_enable_flag(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_enable_flag(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__fetch_function__MotorFdb__motor_enable_flag(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_enable_flag(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__assign_function__MotorFdb__motor_enable_flag(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_enable_flag(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__resize_function__MotorFdb__motor_enable_flag(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

size_t robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__size_function__MotorFdb__motor_fdb_mode(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_fdb_mode(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_fdb_mode(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__fetch_function__MotorFdb__motor_fdb_mode(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_fdb_mode(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__assign_function__MotorFdb__motor_fdb_mode(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_fdb_mode(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__resize_function__MotorFdb__motor_fdb_mode(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

size_t robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__size_function__MotorFdb__motor_angle_fdb(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_angle_fdb(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_angle_fdb(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__fetch_function__MotorFdb__motor_angle_fdb(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_angle_fdb(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__assign_function__MotorFdb__motor_angle_fdb(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_angle_fdb(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__resize_function__MotorFdb__motor_angle_fdb(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__size_function__MotorFdb__motor_effort_fdb(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_effort_fdb(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_effort_fdb(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__fetch_function__MotorFdb__motor_effort_fdb(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_effort_fdb(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__assign_function__MotorFdb__motor_effort_fdb(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_effort_fdb(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__resize_function__MotorFdb__motor_effort_fdb(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_message_member_array[4] = {
  {
    "motor_enable_flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__MotorFdb, motor_enable_flag),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__size_function__MotorFdb__motor_enable_flag,  // size() function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_enable_flag,  // get_const(index) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_enable_flag,  // get(index) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__fetch_function__MotorFdb__motor_enable_flag,  // fetch(index, &value) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__assign_function__MotorFdb__motor_enable_flag,  // assign(index, value) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__resize_function__MotorFdb__motor_enable_flag  // resize(index) function pointer
  },
  {
    "motor_fdb_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__MotorFdb, motor_fdb_mode),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__size_function__MotorFdb__motor_fdb_mode,  // size() function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_fdb_mode,  // get_const(index) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_fdb_mode,  // get(index) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__fetch_function__MotorFdb__motor_fdb_mode,  // fetch(index, &value) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__assign_function__MotorFdb__motor_fdb_mode,  // assign(index, value) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__resize_function__MotorFdb__motor_fdb_mode  // resize(index) function pointer
  },
  {
    "motor_angle_fdb",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__MotorFdb, motor_angle_fdb),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__size_function__MotorFdb__motor_angle_fdb,  // size() function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_angle_fdb,  // get_const(index) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_angle_fdb,  // get(index) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__fetch_function__MotorFdb__motor_angle_fdb,  // fetch(index, &value) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__assign_function__MotorFdb__motor_angle_fdb,  // assign(index, value) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__resize_function__MotorFdb__motor_angle_fdb  // resize(index) function pointer
  },
  {
    "motor_effort_fdb",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__msg__MotorFdb, motor_effort_fdb),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__size_function__MotorFdb__motor_effort_fdb,  // size() function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_const_function__MotorFdb__motor_effort_fdb,  // get_const(index) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__get_function__MotorFdb__motor_effort_fdb,  // get(index) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__fetch_function__MotorFdb__motor_effort_fdb,  // fetch(index, &value) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__assign_function__MotorFdb__motor_effort_fdb,  // assign(index, value) function pointer
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__resize_function__MotorFdb__motor_effort_fdb  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_message_members = {
  "robot_interfaces__msg",  // message namespace
  "MotorFdb",  // message name
  4,  // number of fields
  sizeof(robot_interfaces__msg__MotorFdb),
  robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_message_member_array,  // message members
  robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_message_type_support_handle = {
  0,
  &robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_interfaces, msg, MotorFdb)() {
  if (!robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_message_type_support_handle.typesupport_identifier) {
    robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_interfaces__msg__MotorFdb__rosidl_typesupport_introspection_c__MotorFdb_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
