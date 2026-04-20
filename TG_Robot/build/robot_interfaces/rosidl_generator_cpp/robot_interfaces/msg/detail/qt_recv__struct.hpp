// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/QtRecv.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__QT_RECV__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__QT_RECV__STRUCT_HPP_

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
#include "std_msgs/msg/detail/float64_multi_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__QtRecv __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__QtRecv __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct QtRecv_
{
  using Type = QtRecv_<ContainerAllocator>;

  explicit QtRecv_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gripper_goal(_init),
    joint_angles_goal(_init),
    arm_pose_goal(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->working_mode = 0;
    }
  }

  explicit QtRecv_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gripper_goal(_alloc, _init),
    joint_angles_goal(_alloc, _init),
    arm_pose_goal(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->working_mode = 0;
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

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::QtRecv_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::QtRecv_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::QtRecv_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::QtRecv_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::QtRecv_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::QtRecv_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::QtRecv_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::QtRecv_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::QtRecv_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::QtRecv_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__QtRecv
    std::shared_ptr<robot_interfaces::msg::QtRecv_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__QtRecv
    std::shared_ptr<robot_interfaces::msg::QtRecv_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const QtRecv_ & other) const
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
    return true;
  }
  bool operator!=(const QtRecv_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct QtRecv_

// alias to use template instance with default allocator
using QtRecv =
  robot_interfaces::msg::QtRecv_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__QT_RECV__STRUCT_HPP_
