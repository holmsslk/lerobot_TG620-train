// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/MoveCAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/move_c_action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose_array'
#include "std_msgs/msg/detail/float64_multi_array__traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MoveCAction & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose_array
  {
    out << "pose_array: ";
    to_flow_style_yaml(msg.pose_array, out);
    out << ", ";
  }

  // member: must_pass_through_middle
  {
    out << "must_pass_through_middle: ";
    rosidl_generator_traits::value_to_yaml(msg.must_pass_through_middle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveCAction & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_array:\n";
    to_block_style_yaml(msg.pose_array, out, indentation + 2);
  }

  // member: must_pass_through_middle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "must_pass_through_middle: ";
    rosidl_generator_traits::value_to_yaml(msg.must_pass_through_middle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveCAction & msg, bool use_flow_style = false)
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
  const robot_interfaces::msg::MoveCAction & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::MoveCAction & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::MoveCAction>()
{
  return "robot_interfaces::msg::MoveCAction";
}

template<>
inline const char * name<robot_interfaces::msg::MoveCAction>()
{
  return "robot_interfaces/msg/MoveCAction";
}

template<>
struct has_fixed_size<robot_interfaces::msg::MoveCAction>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Float64MultiArray>::value> {};

template<>
struct has_bounded_size<robot_interfaces::msg::MoveCAction>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Float64MultiArray>::value> {};

template<>
struct is_message<robot_interfaces::msg::MoveCAction>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__TRAITS_HPP_
