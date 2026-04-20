// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/QtRecv.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__QT_RECV__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__QT_RECV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/qt_recv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_QtRecv_arm_pose_goal
{
public:
  explicit Init_QtRecv_arm_pose_goal(::robot_interfaces::msg::QtRecv & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::QtRecv arm_pose_goal(::robot_interfaces::msg::QtRecv::_arm_pose_goal_type arg)
  {
    msg_.arm_pose_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::QtRecv msg_;
};

class Init_QtRecv_joint_angles_goal
{
public:
  explicit Init_QtRecv_joint_angles_goal(::robot_interfaces::msg::QtRecv & msg)
  : msg_(msg)
  {}
  Init_QtRecv_arm_pose_goal joint_angles_goal(::robot_interfaces::msg::QtRecv::_joint_angles_goal_type arg)
  {
    msg_.joint_angles_goal = std::move(arg);
    return Init_QtRecv_arm_pose_goal(msg_);
  }

private:
  ::robot_interfaces::msg::QtRecv msg_;
};

class Init_QtRecv_gripper_goal
{
public:
  explicit Init_QtRecv_gripper_goal(::robot_interfaces::msg::QtRecv & msg)
  : msg_(msg)
  {}
  Init_QtRecv_joint_angles_goal gripper_goal(::robot_interfaces::msg::QtRecv::_gripper_goal_type arg)
  {
    msg_.gripper_goal = std::move(arg);
    return Init_QtRecv_joint_angles_goal(msg_);
  }

private:
  ::robot_interfaces::msg::QtRecv msg_;
};

class Init_QtRecv_working_mode
{
public:
  Init_QtRecv_working_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QtRecv_gripper_goal working_mode(::robot_interfaces::msg::QtRecv::_working_mode_type arg)
  {
    msg_.working_mode = std::move(arg);
    return Init_QtRecv_gripper_goal(msg_);
  }

private:
  ::robot_interfaces::msg::QtRecv msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::QtRecv>()
{
  return robot_interfaces::msg::builder::Init_QtRecv_working_mode();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__QT_RECV__BUILDER_HPP_
