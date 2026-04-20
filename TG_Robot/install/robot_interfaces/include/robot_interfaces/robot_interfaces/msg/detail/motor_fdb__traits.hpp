// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/MotorFdb.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/motor_fdb__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorFdb & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_enable_flag
  {
    if (msg.motor_enable_flag.size() == 0) {
      out << "motor_enable_flag: []";
    } else {
      out << "motor_enable_flag: [";
      size_t pending_items = msg.motor_enable_flag.size();
      for (auto item : msg.motor_enable_flag) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: motor_fdb_mode
  {
    if (msg.motor_fdb_mode.size() == 0) {
      out << "motor_fdb_mode: []";
    } else {
      out << "motor_fdb_mode: [";
      size_t pending_items = msg.motor_fdb_mode.size();
      for (auto item : msg.motor_fdb_mode) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: motor_angle_fdb
  {
    if (msg.motor_angle_fdb.size() == 0) {
      out << "motor_angle_fdb: []";
    } else {
      out << "motor_angle_fdb: [";
      size_t pending_items = msg.motor_angle_fdb.size();
      for (auto item : msg.motor_angle_fdb) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: motor_effort_fdb
  {
    if (msg.motor_effort_fdb.size() == 0) {
      out << "motor_effort_fdb: []";
    } else {
      out << "motor_effort_fdb: [";
      size_t pending_items = msg.motor_effort_fdb.size();
      for (auto item : msg.motor_effort_fdb) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorFdb & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor_enable_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_enable_flag.size() == 0) {
      out << "motor_enable_flag: []\n";
    } else {
      out << "motor_enable_flag:\n";
      for (auto item : msg.motor_enable_flag) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: motor_fdb_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_fdb_mode.size() == 0) {
      out << "motor_fdb_mode: []\n";
    } else {
      out << "motor_fdb_mode:\n";
      for (auto item : msg.motor_fdb_mode) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: motor_angle_fdb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_angle_fdb.size() == 0) {
      out << "motor_angle_fdb: []\n";
    } else {
      out << "motor_angle_fdb:\n";
      for (auto item : msg.motor_angle_fdb) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: motor_effort_fdb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_effort_fdb.size() == 0) {
      out << "motor_effort_fdb: []\n";
    } else {
      out << "motor_effort_fdb:\n";
      for (auto item : msg.motor_effort_fdb) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorFdb & msg, bool use_flow_style = false)
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
  const robot_interfaces::msg::MotorFdb & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::MotorFdb & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::MotorFdb>()
{
  return "robot_interfaces::msg::MotorFdb";
}

template<>
inline const char * name<robot_interfaces::msg::MotorFdb>()
{
  return "robot_interfaces/msg/MotorFdb";
}

template<>
struct has_fixed_size<robot_interfaces::msg::MotorFdb>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::msg::MotorFdb>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::msg::MotorFdb>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__TRAITS_HPP_
