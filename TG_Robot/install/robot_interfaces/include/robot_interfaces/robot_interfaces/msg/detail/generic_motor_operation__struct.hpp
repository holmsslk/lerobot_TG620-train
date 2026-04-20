// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/GenericMotorOperation.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_OPERATION__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_OPERATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__GenericMotorOperation __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__GenericMotorOperation __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GenericMotorOperation_
{
  using Type = GenericMotorOperation_<ContainerAllocator>;

  explicit GenericMotorOperation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->op_code = 0;
    }
  }

  explicit GenericMotorOperation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->op_code = 0;
    }
  }

  // field types and members
  using _motor_id_type =
    uint8_t;
  _motor_id_type motor_id;
  using _op_code_type =
    uint8_t;
  _op_code_type op_code;

  // setters for named parameter idiom
  Type & set__motor_id(
    const uint8_t & _arg)
  {
    this->motor_id = _arg;
    return *this;
  }
  Type & set__op_code(
    const uint8_t & _arg)
  {
    this->op_code = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__GenericMotorOperation
    std::shared_ptr<robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__GenericMotorOperation
    std::shared_ptr<robot_interfaces::msg::GenericMotorOperation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GenericMotorOperation_ & other) const
  {
    if (this->motor_id != other.motor_id) {
      return false;
    }
    if (this->op_code != other.op_code) {
      return false;
    }
    return true;
  }
  bool operator!=(const GenericMotorOperation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GenericMotorOperation_

// alias to use template instance with default allocator
using GenericMotorOperation =
  robot_interfaces::msg::GenericMotorOperation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_OPERATION__STRUCT_HPP_
