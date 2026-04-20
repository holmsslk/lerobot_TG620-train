// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robot_interfaces:msg/MotorFdb.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robot_interfaces/msg/detail/motor_fdb__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robot_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MotorFdb_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robot_interfaces::msg::MotorFdb(_init);
}

void MotorFdb_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robot_interfaces::msg::MotorFdb *>(message_memory);
  typed_message->~MotorFdb();
}

size_t size_function__MotorFdb__motor_enable_flag(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorFdb__motor_enable_flag(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorFdb__motor_enable_flag(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorFdb__motor_enable_flag(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__MotorFdb__motor_enable_flag(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__MotorFdb__motor_enable_flag(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__MotorFdb__motor_enable_flag(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__MotorFdb__motor_enable_flag(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MotorFdb__motor_fdb_mode(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorFdb__motor_fdb_mode(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorFdb__motor_fdb_mode(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorFdb__motor_fdb_mode(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__MotorFdb__motor_fdb_mode(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__MotorFdb__motor_fdb_mode(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__MotorFdb__motor_fdb_mode(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__MotorFdb__motor_fdb_mode(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MotorFdb__motor_angle_fdb(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorFdb__motor_angle_fdb(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorFdb__motor_angle_fdb(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorFdb__motor_angle_fdb(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__MotorFdb__motor_angle_fdb(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__MotorFdb__motor_angle_fdb(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__MotorFdb__motor_angle_fdb(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__MotorFdb__motor_angle_fdb(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MotorFdb__motor_effort_fdb(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorFdb__motor_effort_fdb(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorFdb__motor_effort_fdb(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorFdb__motor_effort_fdb(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__MotorFdb__motor_effort_fdb(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__MotorFdb__motor_effort_fdb(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__MotorFdb__motor_effort_fdb(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__MotorFdb__motor_effort_fdb(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotorFdb_message_member_array[4] = {
  {
    "motor_enable_flag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::MotorFdb, motor_enable_flag),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorFdb__motor_enable_flag,  // size() function pointer
    get_const_function__MotorFdb__motor_enable_flag,  // get_const(index) function pointer
    get_function__MotorFdb__motor_enable_flag,  // get(index) function pointer
    fetch_function__MotorFdb__motor_enable_flag,  // fetch(index, &value) function pointer
    assign_function__MotorFdb__motor_enable_flag,  // assign(index, value) function pointer
    resize_function__MotorFdb__motor_enable_flag  // resize(index) function pointer
  },
  {
    "motor_fdb_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::MotorFdb, motor_fdb_mode),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorFdb__motor_fdb_mode,  // size() function pointer
    get_const_function__MotorFdb__motor_fdb_mode,  // get_const(index) function pointer
    get_function__MotorFdb__motor_fdb_mode,  // get(index) function pointer
    fetch_function__MotorFdb__motor_fdb_mode,  // fetch(index, &value) function pointer
    assign_function__MotorFdb__motor_fdb_mode,  // assign(index, value) function pointer
    resize_function__MotorFdb__motor_fdb_mode  // resize(index) function pointer
  },
  {
    "motor_angle_fdb",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::MotorFdb, motor_angle_fdb),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorFdb__motor_angle_fdb,  // size() function pointer
    get_const_function__MotorFdb__motor_angle_fdb,  // get_const(index) function pointer
    get_function__MotorFdb__motor_angle_fdb,  // get(index) function pointer
    fetch_function__MotorFdb__motor_angle_fdb,  // fetch(index, &value) function pointer
    assign_function__MotorFdb__motor_angle_fdb,  // assign(index, value) function pointer
    resize_function__MotorFdb__motor_angle_fdb  // resize(index) function pointer
  },
  {
    "motor_effort_fdb",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::MotorFdb, motor_effort_fdb),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorFdb__motor_effort_fdb,  // size() function pointer
    get_const_function__MotorFdb__motor_effort_fdb,  // get_const(index) function pointer
    get_function__MotorFdb__motor_effort_fdb,  // get(index) function pointer
    fetch_function__MotorFdb__motor_effort_fdb,  // fetch(index, &value) function pointer
    assign_function__MotorFdb__motor_effort_fdb,  // assign(index, value) function pointer
    resize_function__MotorFdb__motor_effort_fdb  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotorFdb_message_members = {
  "robot_interfaces::msg",  // message namespace
  "MotorFdb",  // message name
  4,  // number of fields
  sizeof(robot_interfaces::msg::MotorFdb),
  MotorFdb_message_member_array,  // message members
  MotorFdb_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorFdb_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotorFdb_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotorFdb_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace robot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_interfaces::msg::MotorFdb>()
{
  return &::robot_interfaces::msg::rosidl_typesupport_introspection_cpp::MotorFdb_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_interfaces, msg, MotorFdb)() {
  return &::robot_interfaces::msg::rosidl_typesupport_introspection_cpp::MotorFdb_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
