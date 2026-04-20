// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/MoveCAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/move_c_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MoveCAction_must_pass_through_middle
{
public:
  explicit Init_MoveCAction_must_pass_through_middle(::robot_interfaces::msg::MoveCAction & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::MoveCAction must_pass_through_middle(::robot_interfaces::msg::MoveCAction::_must_pass_through_middle_type arg)
  {
    msg_.must_pass_through_middle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::MoveCAction msg_;
};

class Init_MoveCAction_pose_array
{
public:
  Init_MoveCAction_pose_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveCAction_must_pass_through_middle pose_array(::robot_interfaces::msg::MoveCAction::_pose_array_type arg)
  {
    msg_.pose_array = std::move(arg);
    return Init_MoveCAction_must_pass_through_middle(msg_);
  }

private:
  ::robot_interfaces::msg::MoveCAction msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::MoveCAction>()
{
  return robot_interfaces::msg::builder::Init_MoveCAction_pose_array();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__BUILDER_HPP_
