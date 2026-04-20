// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/ArmState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/arm_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'end_effector_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArmState & msg,
  std::ostream & out)
{
  out << "{";
  // member: end_effector_pose
  {
    out << "end_effector_pose: ";
    to_flow_style_yaml(msg.end_effector_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: end_effector_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_effector_pose:\n";
    to_block_style_yaml(msg.end_effector_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmState & msg, bool use_flow_style = false)
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
  const robot_interfaces::msg::ArmState & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::ArmState & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::ArmState>()
{
  return "robot_interfaces::msg::ArmState";
}

template<>
inline const char * name<robot_interfaces::msg::ArmState>()
{
  return "robot_interfaces/msg/ArmState";
}

template<>
struct has_fixed_size<robot_interfaces::msg::ArmState>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<robot_interfaces::msg::ArmState>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<robot_interfaces::msg::ArmState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__TRAITS_HPP_
