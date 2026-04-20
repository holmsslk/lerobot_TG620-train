// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/GenericMotorParameter.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/generic_motor_parameter__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GenericMotorParameter & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_id
  {
    out << "motor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_id, out);
    out << ", ";
  }

  // member: command_type
  {
    out << "command_type: ";
    rosidl_generator_traits::value_to_yaml(msg.command_type, out);
    out << ", ";
  }

  // member: float_value
  {
    out << "float_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float_value, out);
    out << ", ";
  }

  // member: int_value
  {
    out << "int_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GenericMotorParameter & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_id, out);
    out << "\n";
  }

  // member: command_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command_type: ";
    rosidl_generator_traits::value_to_yaml(msg.command_type, out);
    out << "\n";
  }

  // member: float_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "float_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float_value, out);
    out << "\n";
  }

  // member: int_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GenericMotorParameter & msg, bool use_flow_style = false)
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
  const robot_interfaces::msg::GenericMotorParameter & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::GenericMotorParameter & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::GenericMotorParameter>()
{
  return "robot_interfaces::msg::GenericMotorParameter";
}

template<>
inline const char * name<robot_interfaces::msg::GenericMotorParameter>()
{
  return "robot_interfaces/msg/GenericMotorParameter";
}

template<>
struct has_fixed_size<robot_interfaces::msg::GenericMotorParameter>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::msg::GenericMotorParameter>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::msg::GenericMotorParameter>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__TRAITS_HPP_
