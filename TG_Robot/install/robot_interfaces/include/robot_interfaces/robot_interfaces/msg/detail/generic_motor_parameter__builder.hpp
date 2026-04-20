// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/GenericMotorParameter.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/generic_motor_parameter__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_GenericMotorParameter_int_value
{
public:
  explicit Init_GenericMotorParameter_int_value(::robot_interfaces::msg::GenericMotorParameter & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::GenericMotorParameter int_value(::robot_interfaces::msg::GenericMotorParameter::_int_value_type arg)
  {
    msg_.int_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::GenericMotorParameter msg_;
};

class Init_GenericMotorParameter_float_value
{
public:
  explicit Init_GenericMotorParameter_float_value(::robot_interfaces::msg::GenericMotorParameter & msg)
  : msg_(msg)
  {}
  Init_GenericMotorParameter_int_value float_value(::robot_interfaces::msg::GenericMotorParameter::_float_value_type arg)
  {
    msg_.float_value = std::move(arg);
    return Init_GenericMotorParameter_int_value(msg_);
  }

private:
  ::robot_interfaces::msg::GenericMotorParameter msg_;
};

class Init_GenericMotorParameter_command_type
{
public:
  explicit Init_GenericMotorParameter_command_type(::robot_interfaces::msg::GenericMotorParameter & msg)
  : msg_(msg)
  {}
  Init_GenericMotorParameter_float_value command_type(::robot_interfaces::msg::GenericMotorParameter::_command_type_type arg)
  {
    msg_.command_type = std::move(arg);
    return Init_GenericMotorParameter_float_value(msg_);
  }

private:
  ::robot_interfaces::msg::GenericMotorParameter msg_;
};

class Init_GenericMotorParameter_motor_id
{
public:
  Init_GenericMotorParameter_motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GenericMotorParameter_command_type motor_id(::robot_interfaces::msg::GenericMotorParameter::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_GenericMotorParameter_command_type(msg_);
  }

private:
  ::robot_interfaces::msg::GenericMotorParameter msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::GenericMotorParameter>()
{
  return robot_interfaces::msg::builder::Init_GenericMotorParameter_motor_id();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__BUILDER_HPP_
