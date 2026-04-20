// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robot_interfaces:msg/RobotControlMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robot_interfaces/msg/detail/robot_control_msg__struct.hpp"
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

void RobotControlMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robot_interfaces::msg::RobotControlMsg(_init);
}

void RobotControlMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robot_interfaces::msg::RobotControlMsg *>(message_memory);
  typed_message->~RobotControlMsg();
}

size_t size_function__RobotControlMsg__motor_enable_flag(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotControlMsg__motor_enable_flag(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotControlMsg__motor_enable_flag(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotControlMsg__motor_enable_flag(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__RobotControlMsg__motor_enable_flag(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__RobotControlMsg__motor_enable_flag(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__RobotControlMsg__motor_enable_flag(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__RobotControlMsg__motor_enable_flag(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__RobotControlMsg__motor_mode(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotControlMsg__motor_mode(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotControlMsg__motor_mode(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotControlMsg__motor_mode(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__RobotControlMsg__motor_mode(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__RobotControlMsg__motor_mode(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__RobotControlMsg__motor_mode(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__RobotControlMsg__motor_mode(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__RobotControlMsg__position(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotControlMsg__position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotControlMsg__position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotControlMsg__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__RobotControlMsg__position(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__RobotControlMsg__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__RobotControlMsg__position(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__RobotControlMsg__position(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__RobotControlMsg__velocity(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotControlMsg__velocity(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotControlMsg__velocity(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotControlMsg__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__RobotControlMsg__velocity(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__RobotControlMsg__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__RobotControlMsg__velocity(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__RobotControlMsg__velocity(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__RobotControlMsg__effort(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotControlMsg__effort(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotControlMsg__effort(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotControlMsg__effort(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__RobotControlMsg__effort(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__RobotControlMsg__effort(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__RobotControlMsg__effort(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__RobotControlMsg__effort(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__RobotControlMsg__kp(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotControlMsg__kp(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotControlMsg__kp(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotControlMsg__kp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__RobotControlMsg__kp(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__RobotControlMsg__kp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__RobotControlMsg__kp(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__RobotControlMsg__kp(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__RobotControlMsg__kd(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotControlMsg__kd(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotControlMsg__kd(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotControlMsg__kd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__RobotControlMsg__kd(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__RobotControlMsg__kd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__RobotControlMsg__kd(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__RobotControlMsg__kd(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotControlMsg_message_member_array[7] = {
  {
    "motor_enable_flag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::RobotControlMsg, motor_enable_flag),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotControlMsg__motor_enable_flag,  // size() function pointer
    get_const_function__RobotControlMsg__motor_enable_flag,  // get_const(index) function pointer
    get_function__RobotControlMsg__motor_enable_flag,  // get(index) function pointer
    fetch_function__RobotControlMsg__motor_enable_flag,  // fetch(index, &value) function pointer
    assign_function__RobotControlMsg__motor_enable_flag,  // assign(index, value) function pointer
    resize_function__RobotControlMsg__motor_enable_flag  // resize(index) function pointer
  },
  {
    "motor_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::RobotControlMsg, motor_mode),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotControlMsg__motor_mode,  // size() function pointer
    get_const_function__RobotControlMsg__motor_mode,  // get_const(index) function pointer
    get_function__RobotControlMsg__motor_mode,  // get(index) function pointer
    fetch_function__RobotControlMsg__motor_mode,  // fetch(index, &value) function pointer
    assign_function__RobotControlMsg__motor_mode,  // assign(index, value) function pointer
    resize_function__RobotControlMsg__motor_mode  // resize(index) function pointer
  },
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::RobotControlMsg, position),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotControlMsg__position,  // size() function pointer
    get_const_function__RobotControlMsg__position,  // get_const(index) function pointer
    get_function__RobotControlMsg__position,  // get(index) function pointer
    fetch_function__RobotControlMsg__position,  // fetch(index, &value) function pointer
    assign_function__RobotControlMsg__position,  // assign(index, value) function pointer
    resize_function__RobotControlMsg__position  // resize(index) function pointer
  },
  {
    "velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::RobotControlMsg, velocity),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotControlMsg__velocity,  // size() function pointer
    get_const_function__RobotControlMsg__velocity,  // get_const(index) function pointer
    get_function__RobotControlMsg__velocity,  // get(index) function pointer
    fetch_function__RobotControlMsg__velocity,  // fetch(index, &value) function pointer
    assign_function__RobotControlMsg__velocity,  // assign(index, value) function pointer
    resize_function__RobotControlMsg__velocity  // resize(index) function pointer
  },
  {
    "effort",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::RobotControlMsg, effort),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotControlMsg__effort,  // size() function pointer
    get_const_function__RobotControlMsg__effort,  // get_const(index) function pointer
    get_function__RobotControlMsg__effort,  // get(index) function pointer
    fetch_function__RobotControlMsg__effort,  // fetch(index, &value) function pointer
    assign_function__RobotControlMsg__effort,  // assign(index, value) function pointer
    resize_function__RobotControlMsg__effort  // resize(index) function pointer
  },
  {
    "kp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::RobotControlMsg, kp),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotControlMsg__kp,  // size() function pointer
    get_const_function__RobotControlMsg__kp,  // get_const(index) function pointer
    get_function__RobotControlMsg__kp,  // get(index) function pointer
    fetch_function__RobotControlMsg__kp,  // fetch(index, &value) function pointer
    assign_function__RobotControlMsg__kp,  // assign(index, value) function pointer
    resize_function__RobotControlMsg__kp  // resize(index) function pointer
  },
  {
    "kd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::msg::RobotControlMsg, kd),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotControlMsg__kd,  // size() function pointer
    get_const_function__RobotControlMsg__kd,  // get_const(index) function pointer
    get_function__RobotControlMsg__kd,  // get(index) function pointer
    fetch_function__RobotControlMsg__kd,  // fetch(index, &value) function pointer
    assign_function__RobotControlMsg__kd,  // assign(index, value) function pointer
    resize_function__RobotControlMsg__kd  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotControlMsg_message_members = {
  "robot_interfaces::msg",  // message namespace
  "RobotControlMsg",  // message name
  7,  // number of fields
  sizeof(robot_interfaces::msg::RobotControlMsg),
  RobotControlMsg_message_member_array,  // message members
  RobotControlMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotControlMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotControlMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotControlMsg_message_members,
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
get_message_type_support_handle<robot_interfaces::msg::RobotControlMsg>()
{
  return &::robot_interfaces::msg::rosidl_typesupport_introspection_cpp::RobotControlMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_interfaces, msg, RobotControlMsg)() {
  return &::robot_interfaces::msg::rosidl_typesupport_introspection_cpp::RobotControlMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
