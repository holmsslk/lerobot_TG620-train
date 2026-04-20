// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/MotorFdb.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__MotorFdb __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__MotorFdb __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorFdb_
{
  using Type = MotorFdb_<ContainerAllocator>;

  explicit MotorFdb_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MotorFdb_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _motor_enable_flag_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _motor_enable_flag_type motor_enable_flag;
  using _motor_fdb_mode_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _motor_fdb_mode_type motor_fdb_mode;
  using _motor_angle_fdb_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _motor_angle_fdb_type motor_angle_fdb;
  using _motor_effort_fdb_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _motor_effort_fdb_type motor_effort_fdb;

  // setters for named parameter idiom
  Type & set__motor_enable_flag(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->motor_enable_flag = _arg;
    return *this;
  }
  Type & set__motor_fdb_mode(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->motor_fdb_mode = _arg;
    return *this;
  }
  Type & set__motor_angle_fdb(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->motor_angle_fdb = _arg;
    return *this;
  }
  Type & set__motor_effort_fdb(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->motor_effort_fdb = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::MotorFdb_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::MotorFdb_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::MotorFdb_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::MotorFdb_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::MotorFdb_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::MotorFdb_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::MotorFdb_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::MotorFdb_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::MotorFdb_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::MotorFdb_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__MotorFdb
    std::shared_ptr<robot_interfaces::msg::MotorFdb_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__MotorFdb
    std::shared_ptr<robot_interfaces::msg::MotorFdb_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorFdb_ & other) const
  {
    if (this->motor_enable_flag != other.motor_enable_flag) {
      return false;
    }
    if (this->motor_fdb_mode != other.motor_fdb_mode) {
      return false;
    }
    if (this->motor_angle_fdb != other.motor_angle_fdb) {
      return false;
    }
    if (this->motor_effort_fdb != other.motor_effort_fdb) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorFdb_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorFdb_

// alias to use template instance with default allocator
using MotorFdb =
  robot_interfaces::msg::MotorFdb_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__MOTOR_FDB__STRUCT_HPP_
