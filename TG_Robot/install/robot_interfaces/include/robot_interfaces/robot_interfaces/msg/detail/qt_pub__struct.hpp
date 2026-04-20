// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/QtPub.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__QtPub __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__QtPub __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct QtPub_
{
  using Type = QtPub_<ContainerAllocator>;

  explicit QtPub_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->working_mode = 0;
      this->enable_flag = false;
    }
  }

  explicit QtPub_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->working_mode = 0;
      this->enable_flag = false;
    }
  }

  // field types and members
  using _working_mode_type =
    uint8_t;
  _working_mode_type working_mode;
  using _enable_flag_type =
    bool;
  _enable_flag_type enable_flag;
  using _joint_group_positions_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _joint_group_positions_type joint_group_positions;
  using _gripper_msgs_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _gripper_msgs_type gripper_msgs;

  // setters for named parameter idiom
  Type & set__working_mode(
    const uint8_t & _arg)
  {
    this->working_mode = _arg;
    return *this;
  }
  Type & set__enable_flag(
    const bool & _arg)
  {
    this->enable_flag = _arg;
    return *this;
  }
  Type & set__joint_group_positions(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->joint_group_positions = _arg;
    return *this;
  }
  Type & set__gripper_msgs(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->gripper_msgs = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::QtPub_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::QtPub_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::QtPub_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::QtPub_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::QtPub_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::QtPub_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::QtPub_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::QtPub_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::QtPub_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::QtPub_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__QtPub
    std::shared_ptr<robot_interfaces::msg::QtPub_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__QtPub
    std::shared_ptr<robot_interfaces::msg::QtPub_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const QtPub_ & other) const
  {
    if (this->working_mode != other.working_mode) {
      return false;
    }
    if (this->enable_flag != other.enable_flag) {
      return false;
    }
    if (this->joint_group_positions != other.joint_group_positions) {
      return false;
    }
    if (this->gripper_msgs != other.gripper_msgs) {
      return false;
    }
    return true;
  }
  bool operator!=(const QtPub_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct QtPub_

// alias to use template instance with default allocator
using QtPub =
  robot_interfaces::msg::QtPub_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__QT_PUB__STRUCT_HPP_
