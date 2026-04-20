// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:srv/ComputeGravity.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__TRAITS_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/srv/detail/compute_gravity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'joint_trajectory'
#include "sensor_msgs/msg/detail/joint_state__traits.hpp"

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeGravity_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint_trajectory
  {
    if (msg.joint_trajectory.size() == 0) {
      out << "joint_trajectory: []";
    } else {
      out << "joint_trajectory: [";
      size_t pending_items = msg.joint_trajectory.size();
      for (auto item : msg.joint_trajectory) {
        to_flow_style_yaml(item, out);
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
  const ComputeGravity_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint_trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_trajectory.size() == 0) {
      out << "joint_trajectory: []\n";
    } else {
      out << "joint_trajectory:\n";
      for (auto item : msg.joint_trajectory) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeGravity_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::ComputeGravity_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::ComputeGravity_Request & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::ComputeGravity_Request>()
{
  return "robot_interfaces::srv::ComputeGravity_Request";
}

template<>
inline const char * name<robot_interfaces::srv::ComputeGravity_Request>()
{
  return "robot_interfaces/srv/ComputeGravity_Request";
}

template<>
struct has_fixed_size<robot_interfaces::srv::ComputeGravity_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::srv::ComputeGravity_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::srv::ComputeGravity_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'efforts'
// already included above
// #include "sensor_msgs/msg/detail/joint_state__traits.hpp"

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeGravity_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: efforts
  {
    if (msg.efforts.size() == 0) {
      out << "efforts: []";
    } else {
      out << "efforts: [";
      size_t pending_items = msg.efforts.size();
      for (auto item : msg.efforts) {
        to_flow_style_yaml(item, out);
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
  const ComputeGravity_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: efforts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.efforts.size() == 0) {
      out << "efforts: []\n";
    } else {
      out << "efforts:\n";
      for (auto item : msg.efforts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeGravity_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::ComputeGravity_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::ComputeGravity_Response & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::ComputeGravity_Response>()
{
  return "robot_interfaces::srv::ComputeGravity_Response";
}

template<>
inline const char * name<robot_interfaces::srv::ComputeGravity_Response>()
{
  return "robot_interfaces/srv/ComputeGravity_Response";
}

template<>
struct has_fixed_size<robot_interfaces::srv::ComputeGravity_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::srv::ComputeGravity_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::srv::ComputeGravity_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_interfaces::srv::ComputeGravity>()
{
  return "robot_interfaces::srv::ComputeGravity";
}

template<>
inline const char * name<robot_interfaces::srv::ComputeGravity>()
{
  return "robot_interfaces/srv/ComputeGravity";
}

template<>
struct has_fixed_size<robot_interfaces::srv::ComputeGravity>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_interfaces::srv::ComputeGravity_Request>::value &&
    has_fixed_size<robot_interfaces::srv::ComputeGravity_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_interfaces::srv::ComputeGravity>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_interfaces::srv::ComputeGravity_Request>::value &&
    has_bounded_size<robot_interfaces::srv::ComputeGravity_Response>::value
  >
{
};

template<>
struct is_service<robot_interfaces::srv::ComputeGravity>
  : std::true_type
{
};

template<>
struct is_service_request<robot_interfaces::srv::ComputeGravity_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_interfaces::srv::ComputeGravity_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__TRAITS_HPP_
