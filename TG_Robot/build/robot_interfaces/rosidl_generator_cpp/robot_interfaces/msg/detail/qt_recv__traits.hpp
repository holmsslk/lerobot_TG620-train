// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/QtRecv.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__QT_RECV__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__QT_RECV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/qt_recv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'gripper_goal'
// Member 'joint_angles_goal'
// Member 'arm_pose_goal'
#include "std_msgs/msg/detail/float64_multi_array__traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const QtRecv & msg,
  std::ostream & out)
{
  out << "{";
  // member: working_mode
  {
    out << "working_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.working_mode, out);
    out << ", ";
  }

  // member: gripper_goal
  {
    out << "gripper_goal: ";
    to_flow_style_yaml(msg.gripper_goal, out);
    out << ", ";
  }

  // member: joint_angles_goal
  {
    out << "joint_angles_goal: ";
    to_flow_style_yaml(msg.joint_angles_goal, out);
    out << ", ";
  }

  // member: arm_pose_goal
  {
    out << "arm_pose_goal: ";
    to_flow_style_yaml(msg.arm_pose_goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const QtRecv & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: working_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "working_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.working_mode, out);
    out << "\n";
  }

  // member: gripper_goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_goal:\n";
    to_block_style_yaml(msg.gripper_goal, out, indentation + 2);
  }

  // member: joint_angles_goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_angles_goal:\n";
    to_block_style_yaml(msg.joint_angles_goal, out, indentation + 2);
  }

  // member: arm_pose_goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arm_pose_goal:\n";
    to_block_style_yaml(msg.arm_pose_goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const QtRecv & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::msg::QtRecv & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::QtRecv & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::QtRecv>()
{
  return "robot_interfaces::msg::QtRecv";
}

template<>
inline const char * name<robot_interfaces::msg::QtRecv>()
{
  return "robot_interfaces/msg/QtRecv";
}

template<>
struct has_fixed_size<robot_interfaces::msg::QtRecv>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Float64MultiArray>::value> {};

template<>
struct has_bounded_size<robot_interfaces::msg::QtRecv>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Float64MultiArray>::value> {};

template<>
struct is_message<robot_interfaces::msg::QtRecv>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__QT_RECV__TRAITS_HPP_
