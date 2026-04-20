// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/MotorFdb.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/motor_fdb__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorFdb_motor_effort_fdb
{
public:
  explicit Init_MotorFdb_motor_effort_fdb(::robot_interfaces::msg::MotorFdb & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::MotorFdb motor_effort_fdb(::robot_interfaces::msg::MotorFdb::_motor_effort_fdb_type arg)
  {
    msg_.motor_effort_fdb = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::MotorFdb msg_;
};

class Init_MotorFdb_motor_angle_fdb
{
public:
  explicit Init_MotorFdb_motor_angle_fdb(::robot_interfaces::msg::MotorFdb & msg)
  : msg_(msg)
  {}
  Init_MotorFdb_motor_effort_fdb motor_angle_fdb(::robot_interfaces::msg::MotorFdb::_motor_angle_fdb_type arg)
  {
    msg_.motor_angle_fdb = std::move(arg);
    return Init_MotorFdb_motor_effort_fdb(msg_);
  }

private:
  ::robot_interfaces::msg::MotorFdb msg_;
};

class Init_MotorFdb_motor_fdb_mode
{
public:
  explicit Init_MotorFdb_motor_fdb_mode(::robot_interfaces::msg::MotorFdb & msg)
  : msg_(msg)
  {}
  Init_MotorFdb_motor_angle_fdb motor_fdb_mode(::robot_interfaces::msg::MotorFdb::_motor_fdb_mode_type arg)
  {
    msg_.motor_fdb_mode = std::move(arg);
    return Init_MotorFdb_motor_angle_fdb(msg_);
  }

private:
  ::robot_interfaces::msg::MotorFdb msg_;
};

class Init_MotorFdb_motor_enable_flag
{
public:
  Init_MotorFdb_motor_enable_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorFdb_motor_fdb_mode motor_enable_flag(::robot_interfaces::msg::MotorFdb::_motor_enable_flag_type arg)
  {
    msg_.motor_enable_flag = std::move(arg);
    return Init_MotorFdb_motor_fdb_mode(msg_);
  }

private:
  ::robot_interfaces::msg::MotorFdb msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::MotorFdb>()
{
  return robot_interfaces::msg::builder::Init_MotorFdb_motor_enable_flag();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__BUILDER_HPP_
