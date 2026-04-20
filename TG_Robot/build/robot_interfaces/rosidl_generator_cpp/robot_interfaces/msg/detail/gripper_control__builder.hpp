// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/GripperControl.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__GRIPPER_CONTROL__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__GRIPPER_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/gripper_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_GripperControl_data
{
public:
  explicit Init_GripperControl_data(::robot_interfaces::msg::GripperControl & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::GripperControl data(::robot_interfaces::msg::GripperControl::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::GripperControl msg_;
};

class Init_GripperControl_effort
{
public:
  explicit Init_GripperControl_effort(::robot_interfaces::msg::GripperControl & msg)
  : msg_(msg)
  {}
  Init_GripperControl_data effort(::robot_interfaces::msg::GripperControl::_effort_type arg)
  {
    msg_.effort = std::move(arg);
    return Init_GripperControl_data(msg_);
  }

private:
  ::robot_interfaces::msg::GripperControl msg_;
};

class Init_GripperControl_velocity
{
public:
  explicit Init_GripperControl_velocity(::robot_interfaces::msg::GripperControl & msg)
  : msg_(msg)
  {}
  Init_GripperControl_effort velocity(::robot_interfaces::msg::GripperControl::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_GripperControl_effort(msg_);
  }

private:
  ::robot_interfaces::msg::GripperControl msg_;
};

class Init_GripperControl_position
{
public:
  explicit Init_GripperControl_position(::robot_interfaces::msg::GripperControl & msg)
  : msg_(msg)
  {}
  Init_GripperControl_velocity position(::robot_interfaces::msg::GripperControl::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_GripperControl_velocity(msg_);
  }

private:
  ::robot_interfaces::msg::GripperControl msg_;
};

class Init_GripperControl_type
{
public:
  Init_GripperControl_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GripperControl_position type(::robot_interfaces::msg::GripperControl::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_GripperControl_position(msg_);
  }

private:
  ::robot_interfaces::msg::GripperControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::GripperControl>()
{
  return robot_interfaces::msg::builder::Init_GripperControl_type();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__GRIPPER_CONTROL__BUILDER_HPP_
