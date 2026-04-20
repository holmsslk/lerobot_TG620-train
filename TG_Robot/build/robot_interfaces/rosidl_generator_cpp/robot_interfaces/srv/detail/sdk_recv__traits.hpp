// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:srv/SdkRecv.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__TRAITS_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/srv/detail/sdk_recv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'gripper_goal'
// Member 'joint_angles_goal'
// Member 'arm_pose_goal'
// Member 'motion_config'
#include "std_msgs/msg/detail/float64_multi_array__traits.hpp"
// Member 'usr_param'
#include "robot_interfaces/msg/detail/generic_motor_parameter__traits.hpp"

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SdkRecv_Request & msg,
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
    out << ", ";
  }

  // member: gripper_data
  {
    if (msg.gripper_data.size() == 0) {
      out << "gripper_data: []";
    } else {
      out << "gripper_data: [";
      size_t pending_items = msg.gripper_data.size();
      for (auto item : msg.gripper_data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: gripper_type
  {
    out << "gripper_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_type, out);
    out << ", ";
  }

  // member: joint_idx
  {
    out << "joint_idx: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_idx, out);
    out << ", ";
  }

  // member: vel_dir
  {
    out << "vel_dir: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_dir, out);
    out << ", ";
  }

  // member: usr_param
  {
    out << "usr_param: ";
    to_flow_style_yaml(msg.usr_param, out);
    out << ", ";
  }

  // member: motion_config
  {
    out << "motion_config: ";
    to_flow_style_yaml(msg.motion_config, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SdkRecv_Request & msg,
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

  // member: gripper_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.gripper_data.size() == 0) {
      out << "gripper_data: []\n";
    } else {
      out << "gripper_data:\n";
      for (auto item : msg.gripper_data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: gripper_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_type, out);
    out << "\n";
  }

  // member: joint_idx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_idx: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_idx, out);
    out << "\n";
  }

  // member: vel_dir
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_dir: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_dir, out);
    out << "\n";
  }

  // member: usr_param
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "usr_param:\n";
    to_block_style_yaml(msg.usr_param, out, indentation + 2);
  }

  // member: motion_config
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motion_config:\n";
    to_block_style_yaml(msg.motion_config, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SdkRecv_Request & msg, bool use_flow_style = false)
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
  const robot_interfaces::srv::SdkRecv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::SdkRecv_Request & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::SdkRecv_Request>()
{
  return "robot_interfaces::srv::SdkRecv_Request";
}

template<>
inline const char * name<robot_interfaces::srv::SdkRecv_Request>()
{
  return "robot_interfaces/srv/SdkRecv_Request";
}

template<>
struct has_fixed_size<robot_interfaces::srv::SdkRecv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::srv::SdkRecv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::srv::SdkRecv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'cur_joint_angles'
// Member 'cur_pos'
// already included above
// #include "std_msgs/msg/detail/float64_multi_array__traits.hpp"

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SdkRecv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: cur_joint_angles
  {
    out << "cur_joint_angles: ";
    to_flow_style_yaml(msg.cur_joint_angles, out);
    out << ", ";
  }

  // member: cur_pos
  {
    out << "cur_pos: ";
    to_flow_style_yaml(msg.cur_pos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SdkRecv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: cur_joint_angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cur_joint_angles:\n";
    to_block_style_yaml(msg.cur_joint_angles, out, indentation + 2);
  }

  // member: cur_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cur_pos:\n";
    to_block_style_yaml(msg.cur_pos, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SdkRecv_Response & msg, bool use_flow_style = false)
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
  const robot_interfaces::srv::SdkRecv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::SdkRecv_Response & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::SdkRecv_Response>()
{
  return "robot_interfaces::srv::SdkRecv_Response";
}

template<>
inline const char * name<robot_interfaces::srv::SdkRecv_Response>()
{
  return "robot_interfaces/srv/SdkRecv_Response";
}

template<>
struct has_fixed_size<robot_interfaces::srv::SdkRecv_Response>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Float64MultiArray>::value> {};

template<>
struct has_bounded_size<robot_interfaces::srv::SdkRecv_Response>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Float64MultiArray>::value> {};

template<>
struct is_message<robot_interfaces::srv::SdkRecv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_interfaces::srv::SdkRecv>()
{
  return "robot_interfaces::srv::SdkRecv";
}

template<>
inline const char * name<robot_interfaces::srv::SdkRecv>()
{
  return "robot_interfaces/srv/SdkRecv";
}

template<>
struct has_fixed_size<robot_interfaces::srv::SdkRecv>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_interfaces::srv::SdkRecv_Request>::value &&
    has_fixed_size<robot_interfaces::srv::SdkRecv_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_interfaces::srv::SdkRecv>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_interfaces::srv::SdkRecv_Request>::value &&
    has_bounded_size<robot_interfaces::srv::SdkRecv_Response>::value
  >
{
};

template<>
struct is_service<robot_interfaces::srv::SdkRecv>
  : std::true_type
{
};

template<>
struct is_service_request<robot_interfaces::srv::SdkRecv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_interfaces::srv::SdkRecv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__TRAITS_HPP_
