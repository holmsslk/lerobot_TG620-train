// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/ArmState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'end_effector_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__ArmState __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__ArmState __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmState_
{
  using Type = ArmState_<ContainerAllocator>;

  explicit ArmState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : end_effector_pose(_init)
  {
    (void)_init;
  }

  explicit ArmState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : end_effector_pose(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _end_effector_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _end_effector_pose_type end_effector_pose;

  // setters for named parameter idiom
  Type & set__end_effector_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->end_effector_pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::ArmState_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::ArmState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::ArmState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::ArmState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::ArmState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::ArmState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::ArmState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::ArmState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::ArmState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::ArmState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__ArmState
    std::shared_ptr<robot_interfaces::msg::ArmState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__ArmState
    std::shared_ptr<robot_interfaces::msg::ArmState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmState_ & other) const
  {
    if (this->end_effector_pose != other.end_effector_pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmState_

// alias to use template instance with default allocator
using ArmState =
  robot_interfaces::msg::ArmState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ARM_STATE__STRUCT_HPP_
