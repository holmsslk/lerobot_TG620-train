// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/QtPub.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/qt_pub__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const QtPub & msg,
  std::ostream & out)
{
  out << "{";
  // member: working_mode
  {
    out << "working_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.working_mode, out);
    out << ", ";
  }

  // member: enable_flag
  {
    out << "enable_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.enable_flag, out);
    out << ", ";
  }

  // member: joint_group_positions
  {
    if (msg.joint_group_positions.size() == 0) {
      out << "joint_group_positions: []";
    } else {
      out << "joint_group_positions: [";
      size_t pending_items = msg.joint_group_positions.size();
      for (auto item : msg.joint_group_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: gripper_msgs
  {
    if (msg.gripper_msgs.size() == 0) {
      out << "gripper_msgs: []";
    } else {
      out << "gripper_msgs: [";
      size_t pending_items = msg.gripper_msgs.size();
      for (auto item : msg.gripper_msgs) {
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
  const QtPub & msg,
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

  // member: enable_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enable_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.enable_flag, out);
    out << "\n";
  }

  // member: joint_group_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_group_positions.size() == 0) {
      out << "joint_group_positions: []\n";
    } else {
      out << "joint_group_positions:\n";
      for (auto item : msg.joint_group_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: gripper_msgs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.gripper_msgs.size() == 0) {
      out << "gripper_msgs: []\n";
    } else {
      out << "gripper_msgs:\n";
      for (auto item : msg.gripper_msgs) {
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

inline std::string to_yaml(const QtPub & msg, bool use_flow_style = false)
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
  const robot_interfaces::msg::QtPub & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::QtPub & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::QtPub>()
{
  return "robot_interfaces::msg::QtPub";
}

template<>
inline const char * name<robot_interfaces::msg::QtPub>()
{
  return "robot_interfaces/msg/QtPub";
}

template<>
struct has_fixed_size<robot_interfaces::msg::QtPub>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::msg::QtPub>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::msg::QtPub>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__TRAITS_HPP_
