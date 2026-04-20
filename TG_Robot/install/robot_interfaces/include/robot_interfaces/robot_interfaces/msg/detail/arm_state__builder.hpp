// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/ArmState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/arm_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmState_end_effector_pose
{
public:
  Init_ArmState_end_effector_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::msg::ArmState end_effector_pose(::robot_interfaces::msg::ArmState::_end_effector_pose_type arg)
  {
    msg_.end_effector_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::ArmState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::ArmState>()
{
  return robot_interfaces::msg::builder::Init_ArmState_end_effector_pose();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__BUILDER_HPP_
