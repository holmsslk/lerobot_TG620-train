// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/LineMsg.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/line_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_LineMsg_radius
{
public:
  explicit Init_LineMsg_radius(::robot_interfaces::msg::LineMsg & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::LineMsg radius(::robot_interfaces::msg::LineMsg::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::LineMsg msg_;
};

class Init_LineMsg_delta_z
{
public:
  explicit Init_LineMsg_delta_z(::robot_interfaces::msg::LineMsg & msg)
  : msg_(msg)
  {}
  Init_LineMsg_radius delta_z(::robot_interfaces::msg::LineMsg::_delta_z_type arg)
  {
    msg_.delta_z = std::move(arg);
    return Init_LineMsg_radius(msg_);
  }

private:
  ::robot_interfaces::msg::LineMsg msg_;
};

class Init_LineMsg_delta_y
{
public:
  explicit Init_LineMsg_delta_y(::robot_interfaces::msg::LineMsg & msg)
  : msg_(msg)
  {}
  Init_LineMsg_delta_z delta_y(::robot_interfaces::msg::LineMsg::_delta_y_type arg)
  {
    msg_.delta_y = std::move(arg);
    return Init_LineMsg_delta_z(msg_);
  }

private:
  ::robot_interfaces::msg::LineMsg msg_;
};

class Init_LineMsg_delta_x
{
public:
  explicit Init_LineMsg_delta_x(::robot_interfaces::msg::LineMsg & msg)
  : msg_(msg)
  {}
  Init_LineMsg_delta_y delta_x(::robot_interfaces::msg::LineMsg::_delta_x_type arg)
  {
    msg_.delta_x = std::move(arg);
    return Init_LineMsg_delta_y(msg_);
  }

private:
  ::robot_interfaces::msg::LineMsg msg_;
};

class Init_LineMsg_initial_pose
{
public:
  explicit Init_LineMsg_initial_pose(::robot_interfaces::msg::LineMsg & msg)
  : msg_(msg)
  {}
  Init_LineMsg_delta_x initial_pose(::robot_interfaces::msg::LineMsg::_initial_pose_type arg)
  {
    msg_.initial_pose = std::move(arg);
    return Init_LineMsg_delta_x(msg_);
  }

private:
  ::robot_interfaces::msg::LineMsg msg_;
};

class Init_LineMsg_type
{
public:
  Init_LineMsg_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LineMsg_initial_pose type(::robot_interfaces::msg::LineMsg::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_LineMsg_initial_pose(msg_);
  }

private:
  ::robot_interfaces::msg::LineMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::LineMsg>()
{
  return robot_interfaces::msg::builder::Init_LineMsg_type();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__BUILDER_HPP_
