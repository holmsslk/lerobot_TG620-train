// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/StateAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/state_action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const StateAction & msg,
  std::ostream & out)
{
  out << "{";
  // member: state_name
  {
    out << "state_name: ";
    rosidl_generator_traits::value_to_yaml(msg.state_name, out);
    out << ", ";
  }

  // member: operation_mode
  {
    out << "operation_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.operation_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StateAction & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_name: ";
    rosidl_generator_traits::value_to_yaml(msg.state_name, out);
    out << "\n";
  }

  // member: operation_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "operation_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.operation_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StateAction & msg, bool use_flow_style = false)
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
  const robot_interfaces::msg::StateAction & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::StateAction & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::StateAction>()
{
  return "robot_interfaces::msg::StateAction";
}

template<>
inline const char * name<robot_interfaces::msg::StateAction>()
{
  return "robot_interfaces/msg/StateAction";
}

template<>
struct has_fixed_size<robot_interfaces::msg::StateAction>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::msg::StateAction>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::msg::StateAction>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__TRAITS_HPP_
