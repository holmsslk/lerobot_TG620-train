// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/LineMsg.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/line_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'initial_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LineMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: initial_pose
  {
    out << "initial_pose: ";
    to_flow_style_yaml(msg.initial_pose, out);
    out << ", ";
  }

  // member: delta_x
  {
    out << "delta_x: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_x, out);
    out << ", ";
  }

  // member: delta_y
  {
    out << "delta_y: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_y, out);
    out << ", ";
  }

  // member: delta_z
  {
    out << "delta_z: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_z, out);
    out << ", ";
  }

  // member: radius
  {
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LineMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: initial_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "initial_pose:\n";
    to_block_style_yaml(msg.initial_pose, out, indentation + 2);
  }

  // member: delta_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_x: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_x, out);
    out << "\n";
  }

  // member: delta_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_y: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_y, out);
    out << "\n";
  }

  // member: delta_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_z: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_z, out);
    out << "\n";
  }

  // member: radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LineMsg & msg, bool use_flow_style = false)
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
  const robot_interfaces::msg::LineMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::LineMsg & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::LineMsg>()
{
  return "robot_interfaces::msg::LineMsg";
}

template<>
inline const char * name<robot_interfaces::msg::LineMsg>()
{
  return "robot_interfaces/msg/LineMsg";
}

template<>
struct has_fixed_size<robot_interfaces::msg::LineMsg>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<robot_interfaces::msg::LineMsg>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<robot_interfaces::msg::LineMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__TRAITS_HPP_
