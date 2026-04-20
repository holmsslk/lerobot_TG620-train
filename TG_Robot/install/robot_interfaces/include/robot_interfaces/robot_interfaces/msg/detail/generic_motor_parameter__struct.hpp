// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/GenericMotorParameter.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__GenericMotorParameter __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__GenericMotorParameter __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GenericMotorParameter_
{
  using Type = GenericMotorParameter_<ContainerAllocator>;

  explicit GenericMotorParameter_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->command_type = 0;
      this->float_value = 0.0f;
      this->int_value = 0l;
    }
  }

  explicit GenericMotorParameter_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->command_type = 0;
      this->float_value = 0.0f;
      this->int_value = 0l;
    }
  }

  // field types and members
  using _motor_id_type =
    uint8_t;
  _motor_id_type motor_id;
  using _command_type_type =
    uint16_t;
  _command_type_type command_type;
  using _float_value_type =
    float;
  _float_value_type float_value;
  using _int_value_type =
    int32_t;
  _int_value_type int_value;

  // setters for named parameter idiom
  Type & set__motor_id(
    const uint8_t & _arg)
  {
    this->motor_id = _arg;
    return *this;
  }
  Type & set__command_type(
    const uint16_t & _arg)
  {
    this->command_type = _arg;
    return *this;
  }
  Type & set__float_value(
    const float & _arg)
  {
    this->float_value = _arg;
    return *this;
  }
  Type & set__int_value(
    const int32_t & _arg)
  {
    this->int_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__GenericMotorParameter
    std::shared_ptr<robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__GenericMotorParameter
    std::shared_ptr<robot_interfaces::msg::GenericMotorParameter_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GenericMotorParameter_ & other) const
  {
    if (this->motor_id != other.motor_id) {
      return false;
    }
    if (this->command_type != other.command_type) {
      return false;
    }
    if (this->float_value != other.float_value) {
      return false;
    }
    if (this->int_value != other.int_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const GenericMotorParameter_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GenericMotorParameter_

// alias to use template instance with default allocator
using GenericMotorParameter =
  robot_interfaces::msg::GenericMotorParameter_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__GENERIC_MOTOR_PARAMETER__STRUCT_HPP_
