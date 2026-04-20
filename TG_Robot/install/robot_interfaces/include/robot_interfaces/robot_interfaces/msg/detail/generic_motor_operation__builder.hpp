// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/GenericMotorOperation.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_OPERATION__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_OPERATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/generic_motor_operation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_GenericMotorOperation_op_code
{
public:
  explicit Init_GenericMotorOperation_op_code(::robot_interfaces::msg::GenericMotorOperation & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::GenericMotorOperation op_code(::robot_interfaces::msg::GenericMotorOperation::_op_code_type arg)
  {
    msg_.op_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::GenericMotorOperation msg_;
};

class Init_GenericMotorOperation_motor_id
{
public:
  Init_GenericMotorOperation_motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GenericMotorOperation_op_code motor_id(::robot_interfaces::msg::GenericMotorOperation::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_GenericMotorOperation_op_code(msg_);
  }

private:
  ::robot_interfaces::msg::GenericMotorOperation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::GenericMotorOperation>()
{
  return robot_interfaces::msg::builder::Init_GenericMotorOperation_motor_id();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_OPERATION__BUILDER_HPP_
