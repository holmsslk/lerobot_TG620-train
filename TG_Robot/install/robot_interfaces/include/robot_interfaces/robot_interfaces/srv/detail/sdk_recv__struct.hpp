// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/SdkRecv.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'gripper_goal'
// Member 'joint_angles_goal'
// Member 'arm_pose_goal'
// Member 'motion_config'
#include "std_msgs/msg/detail/float64_multi_array__struct.hpp"
// Member 'usr_param'
#include "robot_interfaces/msg/detail/generic_motor_parameter__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__SdkRecv_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__SdkRecv_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SdkRecv_Request_
{
  using Type = SdkRecv_Request_<ContainerAllocator>;

  explicit SdkRecv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gripper_goal(_init),
    joint_angles_goal(_init),
    arm_pose_goal(_init),
    usr_param(_init),
    motion_config(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->working_mode = 0;
      this->gripper_type = 0;
      this->joint_idx = 0;
      this->vel_dir = 0;
    }
  }

  explicit SdkRecv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gripper_goal(_alloc, _init),
    joint_angles_goal(_alloc, _init),
    arm_pose_goal(_alloc, _init),
    usr_param(_alloc, _init),
    motion_config(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->working_mode = 0;
      this->gripper_type = 0;
      this->joint_idx = 0;
      this->vel_dir = 0;
    }
  }

  // field types and members
  using _working_mode_type =
    uint8_t;
  _working_mode_type working_mode;
  using _gripper_goal_type =
    std_msgs::msg::Float64MultiArray_<ContainerAllocator>;
  _gripper_goal_type gripper_goal;
  using _joint_angles_goal_type =
    std_msgs::msg::Float64MultiArray_<ContainerAllocator>;
  _joint_angles_goal_type joint_angles_goal;
  using _arm_pose_goal_type =
    std_msgs::msg::Float64MultiArray_<ContainerAllocator>;
  _arm_pose_goal_type arm_pose_goal;
  using _gripper_data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _gripper_data_type gripper_data;
  using _gripper_type_type =
    uint8_t;
  _gripper_type_type gripper_type;
  using _joint_idx_type =
    uint8_t;
  _joint_idx_type joint_idx;
  using _vel_dir_type =
    uint8_t;
  _vel_dir_type vel_dir;
  using _usr_param_type =
    robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator>;
  _usr_param_type usr_param;
  using _motion_config_type =
    std_msgs::msg::Float64MultiArray_<ContainerAllocator>;
  _motion_config_type motion_config;

  // setters for named parameter idiom
  Type & set__working_mode(
    const uint8_t & _arg)
  {
    this->working_mode = _arg;
    return *this;
  }
  Type & set__gripper_goal(
    const std_msgs::msg::Float64MultiArray_<ContainerAllocator> & _arg)
  {
    this->gripper_goal = _arg;
    return *this;
  }
  Type & set__joint_angles_goal(
    const std_msgs::msg::Float64MultiArray_<ContainerAllocator> & _arg)
  {
    this->joint_angles_goal = _arg;
    return *this;
  }
  Type & set__arm_pose_goal(
    const std_msgs::msg::Float64MultiArray_<ContainerAllocator> & _arg)
  {
    this->arm_pose_goal = _arg;
    return *this;
  }
  Type & set__gripper_data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->gripper_data = _arg;
    return *this;
  }
  Type & set__gripper_type(
    const uint8_t & _arg)
  {
    this->gripper_type = _arg;
    return *this;
  }
  Type & set__joint_idx(
    const uint8_t & _arg)
  {
    this->joint_idx = _arg;
    return *this;
  }
  Type & set__vel_dir(
    const uint8_t & _arg)
  {
    this->vel_dir = _arg;
    return *this;
  }
  Type & set__usr_param(
    const robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator> & _arg)
  {
    this->usr_param = _arg;
    return *this;
  }
  Type & set__motion_config(
    const std_msgs::msg::Float64MultiArray_<ContainerAllocator> & _arg)
  {
    this->motion_config = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__SdkRecv_Request
    std::shared_ptr<robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__SdkRecv_Request
    std::shared_ptr<robot_interfaces::srv::SdkRecv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SdkRecv_Request_ & other) const
  {
    if (this->working_mode != other.working_mode) {
      return false;
    }
    if (this->gripper_goal != other.gripper_goal) {
      return false;
    }
    if (this->joint_angles_goal != other.joint_angles_goal) {
      return false;
    }
    if (this->arm_pose_goal != other.arm_pose_goal) {
      return false;
    }
    if (this->gripper_data != other.gripper_data) {
      return false;
    }
    if (this->gripper_type != other.gripper_type) {
      return false;
    }
    if (this->joint_idx != other.joint_idx) {
      return false;
    }
    if (this->vel_dir != other.vel_dir) {
      return false;
    }
    if (this->usr_param != other.usr_param) {
      return false;
    }
    if (this->motion_config != other.motion_config) {
      return false;
    }
    return true;
  }
  bool operator!=(const SdkRecv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SdkRecv_Request_

// alias to use template instance with default allocator
using SdkRecv_Request =
  robot_interfaces::srv::SdkRecv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


// Include directives for member types
// Member 'cur_joint_angles'
// Member 'cur_pos'
// already included above
// #include "std_msgs/msg/detail/float64_multi_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__SdkRecv_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__SdkRecv_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SdkRecv_Response_
{
  using Type = SdkRecv_Response_<ContainerAllocator>;

  explicit SdkRecv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cur_joint_angles(_init),
    cur_pos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SdkRecv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cur_joint_angles(_alloc, _init),
    cur_pos(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _cur_joint_angles_type =
    std_msgs::msg::Float64MultiArray_<ContainerAllocator>;
  _cur_joint_angles_type cur_joint_angles;
  using _cur_pos_type =
    std_msgs::msg::Float64MultiArray_<ContainerAllocator>;
  _cur_pos_type cur_pos;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__cur_joint_angles(
    const std_msgs::msg::Float64MultiArray_<ContainerAllocator> & _arg)
  {
    this->cur_joint_angles = _arg;
    return *this;
  }
  Type & set__cur_pos(
    const std_msgs::msg::Float64MultiArray_<ContainerAllocator> & _arg)
  {
    this->cur_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__SdkRecv_Response
    std::shared_ptr<robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__SdkRecv_Response
    std::shared_ptr<robot_interfaces::srv::SdkRecv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SdkRecv_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->cur_joint_angles != other.cur_joint_angles) {
      return false;
    }
    if (this->cur_pos != other.cur_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const SdkRecv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SdkRecv_Response_

// alias to use template instance with default allocator
using SdkRecv_Response =
  robot_interfaces::srv::SdkRecv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct SdkRecv
{
  using Request = robot_interfaces::srv::SdkRecv_Request;
  using Response = robot_interfaces::srv::SdkRecv_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__SDK_RECV__STRUCT_HPP_
