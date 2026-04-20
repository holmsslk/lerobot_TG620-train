// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/QtPub.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/qt_pub__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_QtPub_gripper_msgs
{
public:
  explicit Init_QtPub_gripper_msgs(::robot_interfaces::msg::QtPub & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::QtPub gripper_msgs(::robot_interfaces::msg::QtPub::_gripper_msgs_type arg)
  {
    msg_.gripper_msgs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::QtPub msg_;
};

class Init_QtPub_joint_group_positions
{
public:
  explicit Init_QtPub_joint_group_positions(::robot_interfaces::msg::QtPub & msg)
  : msg_(msg)
  {}
  Init_QtPub_gripper_msgs joint_group_positions(::robot_interfaces::msg::QtPub::_joint_group_positions_type arg)
  {
    msg_.joint_group_positions = std::move(arg);
    return Init_QtPub_gripper_msgs(msg_);
  }

private:
  ::robot_interfaces::msg::QtPub msg_;
};

class Init_QtPub_enable_flag
{
public:
  explicit Init_QtPub_enable_flag(::robot_interfaces::msg::QtPub & msg)
  : msg_(msg)
  {}
  Init_QtPub_joint_group_positions enable_flag(::robot_interfaces::msg::QtPub::_enable_flag_type arg)
  {
    msg_.enable_flag = std::move(arg);
    return Init_QtPub_joint_group_positions(msg_);
  }

private:
  ::robot_interfaces::msg::QtPub msg_;
};

class Init_QtPub_working_mode
{
public:
  Init_QtPub_working_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QtPub_enable_flag working_mode(::robot_interfaces::msg::QtPub::_working_mode_type arg)
  {
    msg_.working_mode = std::move(arg);
    return Init_QtPub_enable_flag(msg_);
  }

private:
  ::robot_interfaces::msg::QtPub msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::QtPub>()
{
  return robot_interfaces::msg::builder::Init_QtPub_working_mode();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__BUILDER_HPP_
