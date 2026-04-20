// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/KeyPressedAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__KEY_PRESSED_ACTION__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__KEY_PRESSED_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/key_pressed_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_KeyPressedAction_is_pressed
{
public:
  explicit Init_KeyPressedAction_is_pressed(::robot_interfaces::msg::KeyPressedAction & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::KeyPressedAction is_pressed(::robot_interfaces::msg::KeyPressedAction::_is_pressed_type arg)
  {
    msg_.is_pressed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::KeyPressedAction msg_;
};

class Init_KeyPressedAction_key_code
{
public:
  Init_KeyPressedAction_key_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_KeyPressedAction_is_pressed key_code(::robot_interfaces::msg::KeyPressedAction::_key_code_type arg)
  {
    msg_.key_code = std::move(arg);
    return Init_KeyPressedAction_is_pressed(msg_);
  }

private:
  ::robot_interfaces::msg::KeyPressedAction msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::KeyPressedAction>()
{
  return robot_interfaces::msg::builder::Init_KeyPressedAction_key_code();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__KEY_PRESSED_ACTION__BUILDER_HPP_
