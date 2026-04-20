// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/MoveCAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose_array'
#include "std_msgs/msg/detail/float64_multi_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__MoveCAction __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__MoveCAction __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MoveCAction_
{
  using Type = MoveCAction_<ContainerAllocator>;

  explicit MoveCAction_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_array(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->must_pass_through_middle = false;
    }
  }

  explicit MoveCAction_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_array(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->must_pass_through_middle = false;
    }
  }

  // field types and members
  using _pose_array_type =
    std_msgs::msg::Float64MultiArray_<ContainerAllocator>;
  _pose_array_type pose_array;
  using _must_pass_through_middle_type =
    bool;
  _must_pass_through_middle_type must_pass_through_middle;

  // setters for named parameter idiom
  Type & set__pose_array(
    const std_msgs::msg::Float64MultiArray_<ContainerAllocator> & _arg)
  {
    this->pose_array = _arg;
    return *this;
  }
  Type & set__must_pass_through_middle(
    const bool & _arg)
  {
    this->must_pass_through_middle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::MoveCAction_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::MoveCAction_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::MoveCAction_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::MoveCAction_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::MoveCAction_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::MoveCAction_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::MoveCAction_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::MoveCAction_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::MoveCAction_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::MoveCAction_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__MoveCAction
    std::shared_ptr<robot_interfaces::msg::MoveCAction_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__MoveCAction
    std::shared_ptr<robot_interfaces::msg::MoveCAction_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveCAction_ & other) const
  {
    if (this->pose_array != other.pose_array) {
      return false;
    }
    if (this->must_pass_through_middle != other.must_pass_through_middle) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveCAction_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveCAction_

// alias to use template instance with default allocator
using MoveCAction =
  robot_interfaces::msg::MoveCAction_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__MOVE_C_ACTION__STRUCT_HPP_
