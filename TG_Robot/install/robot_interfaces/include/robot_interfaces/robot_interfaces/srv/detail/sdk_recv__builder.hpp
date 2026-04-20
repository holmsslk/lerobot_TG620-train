// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/SdkRecv.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/sdk_recv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SdkRecv_Request_motion_config
{
public:
  explicit Init_SdkRecv_Request_motion_config(::robot_interfaces::srv::SdkRecv_Request & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::SdkRecv_Request motion_config(::robot_interfaces::srv::SdkRecv_Request::_motion_config_type arg)
  {
    msg_.motion_config = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Request msg_;
};

class Init_SdkRecv_Request_usr_param
{
public:
  explicit Init_SdkRecv_Request_usr_param(::robot_interfaces::srv::SdkRecv_Request & msg)
  : msg_(msg)
  {}
  Init_SdkRecv_Request_motion_config usr_param(::robot_interfaces::srv::SdkRecv_Request::_usr_param_type arg)
  {
    msg_.usr_param = std::move(arg);
    return Init_SdkRecv_Request_motion_config(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Request msg_;
};

class Init_SdkRecv_Request_vel_dir
{
public:
  explicit Init_SdkRecv_Request_vel_dir(::robot_interfaces::srv::SdkRecv_Request & msg)
  : msg_(msg)
  {}
  Init_SdkRecv_Request_usr_param vel_dir(::robot_interfaces::srv::SdkRecv_Request::_vel_dir_type arg)
  {
    msg_.vel_dir = std::move(arg);
    return Init_SdkRecv_Request_usr_param(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Request msg_;
};

class Init_SdkRecv_Request_joint_idx
{
public:
  explicit Init_SdkRecv_Request_joint_idx(::robot_interfaces::srv::SdkRecv_Request & msg)
  : msg_(msg)
  {}
  Init_SdkRecv_Request_vel_dir joint_idx(::robot_interfaces::srv::SdkRecv_Request::_joint_idx_type arg)
  {
    msg_.joint_idx = std::move(arg);
    return Init_SdkRecv_Request_vel_dir(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Request msg_;
};

class Init_SdkRecv_Request_gripper_type
{
public:
  explicit Init_SdkRecv_Request_gripper_type(::robot_interfaces::srv::SdkRecv_Request & msg)
  : msg_(msg)
  {}
  Init_SdkRecv_Request_joint_idx gripper_type(::robot_interfaces::srv::SdkRecv_Request::_gripper_type_type arg)
  {
    msg_.gripper_type = std::move(arg);
    return Init_SdkRecv_Request_joint_idx(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Request msg_;
};

class Init_SdkRecv_Request_gripper_data
{
public:
  explicit Init_SdkRecv_Request_gripper_data(::robot_interfaces::srv::SdkRecv_Request & msg)
  : msg_(msg)
  {}
  Init_SdkRecv_Request_gripper_type gripper_data(::robot_interfaces::srv::SdkRecv_Request::_gripper_data_type arg)
  {
    msg_.gripper_data = std::move(arg);
    return Init_SdkRecv_Request_gripper_type(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Request msg_;
};

class Init_SdkRecv_Request_arm_pose_goal
{
public:
  explicit Init_SdkRecv_Request_arm_pose_goal(::robot_interfaces::srv::SdkRecv_Request & msg)
  : msg_(msg)
  {}
  Init_SdkRecv_Request_gripper_data arm_pose_goal(::robot_interfaces::srv::SdkRecv_Request::_arm_pose_goal_type arg)
  {
    msg_.arm_pose_goal = std::move(arg);
    return Init_SdkRecv_Request_gripper_data(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Request msg_;
};

class Init_SdkRecv_Request_joint_angles_goal
{
public:
  explicit Init_SdkRecv_Request_joint_angles_goal(::robot_interfaces::srv::SdkRecv_Request & msg)
  : msg_(msg)
  {}
  Init_SdkRecv_Request_arm_pose_goal joint_angles_goal(::robot_interfaces::srv::SdkRecv_Request::_joint_angles_goal_type arg)
  {
    msg_.joint_angles_goal = std::move(arg);
    return Init_SdkRecv_Request_arm_pose_goal(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Request msg_;
};

class Init_SdkRecv_Request_gripper_goal
{
public:
  explicit Init_SdkRecv_Request_gripper_goal(::robot_interfaces::srv::SdkRecv_Request & msg)
  : msg_(msg)
  {}
  Init_SdkRecv_Request_joint_angles_goal gripper_goal(::robot_interfaces::srv::SdkRecv_Request::_gripper_goal_type arg)
  {
    msg_.gripper_goal = std::move(arg);
    return Init_SdkRecv_Request_joint_angles_goal(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Request msg_;
};

class Init_SdkRecv_Request_working_mode
{
public:
  Init_SdkRecv_Request_working_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SdkRecv_Request_gripper_goal working_mode(::robot_interfaces::srv::SdkRecv_Request::_working_mode_type arg)
  {
    msg_.working_mode = std::move(arg);
    return Init_SdkRecv_Request_gripper_goal(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::SdkRecv_Request>()
{
  return robot_interfaces::srv::builder::Init_SdkRecv_Request_working_mode();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SdkRecv_Response_cur_pos
{
public:
  explicit Init_SdkRecv_Response_cur_pos(::robot_interfaces::srv::SdkRecv_Response & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::SdkRecv_Response cur_pos(::robot_interfaces::srv::SdkRecv_Response::_cur_pos_type arg)
  {
    msg_.cur_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Response msg_;
};

class Init_SdkRecv_Response_cur_joint_angles
{
public:
  explicit Init_SdkRecv_Response_cur_joint_angles(::robot_interfaces::srv::SdkRecv_Response & msg)
  : msg_(msg)
  {}
  Init_SdkRecv_Response_cur_pos cur_joint_angles(::robot_interfaces::srv::SdkRecv_Response::_cur_joint_angles_type arg)
  {
    msg_.cur_joint_angles = std::move(arg);
    return Init_SdkRecv_Response_cur_pos(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Response msg_;
};

class Init_SdkRecv_Response_success
{
public:
  Init_SdkRecv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SdkRecv_Response_cur_joint_angles success(::robot_interfaces::srv::SdkRecv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SdkRecv_Response_cur_joint_angles(msg_);
  }

private:
  ::robot_interfaces::srv::SdkRecv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::SdkRecv_Response>()
{
  return robot_interfaces::srv::builder::Init_SdkRecv_Response_success();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__BUILDER_HPP_
