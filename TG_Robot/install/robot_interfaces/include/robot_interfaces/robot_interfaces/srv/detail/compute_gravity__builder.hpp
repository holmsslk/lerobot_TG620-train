// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/ComputeGravity.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/compute_gravity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeGravity_Request_joint_trajectory
{
public:
  Init_ComputeGravity_Request_joint_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::ComputeGravity_Request joint_trajectory(::robot_interfaces::srv::ComputeGravity_Request::_joint_trajectory_type arg)
  {
    msg_.joint_trajectory = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::ComputeGravity_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::ComputeGravity_Request>()
{
  return robot_interfaces::srv::builder::Init_ComputeGravity_Request_joint_trajectory();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputeGravity_Response_efforts
{
public:
  Init_ComputeGravity_Response_efforts()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::ComputeGravity_Response efforts(::robot_interfaces::srv::ComputeGravity_Response::_efforts_type arg)
  {
    msg_.efforts = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::ComputeGravity_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::ComputeGravity_Response>()
{
  return robot_interfaces::srv::builder::Init_ComputeGravity_Response_efforts();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__BUILDER_HPP_
