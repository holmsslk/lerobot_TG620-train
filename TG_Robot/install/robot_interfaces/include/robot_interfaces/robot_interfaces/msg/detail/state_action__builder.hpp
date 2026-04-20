// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/StateAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/state_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_StateAction_operation_mode
{
public:
  explicit Init_StateAction_operation_mode(::robot_interfaces::msg::StateAction & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::StateAction operation_mode(::robot_interfaces::msg::StateAction::_operation_mode_type arg)
  {
    msg_.operation_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::StateAction msg_;
};

class Init_StateAction_state_name
{
public:
  Init_StateAction_state_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateAction_operation_mode state_name(::robot_interfaces::msg::StateAction::_state_name_type arg)
  {
    msg_.state_name = std::move(arg);
    return Init_StateAction_operation_mode(msg_);
  }

private:
  ::robot_interfaces::msg::StateAction msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::StateAction>()
{
  return robot_interfaces::msg::builder::Init_StateAction_state_name();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__BUILDER_HPP_
