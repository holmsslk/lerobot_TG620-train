// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/KeyPressedAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__KEY_PRESSED_ACTION__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__KEY_PRESSED_ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__KeyPressedAction __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__KeyPressedAction __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct KeyPressedAction_
{
  using Type = KeyPressedAction_<ContainerAllocator>;

  explicit KeyPressedAction_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key_code = 0;
      this->is_pressed = false;
    }
  }

  explicit KeyPressedAction_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key_code = 0;
      this->is_pressed = false;
    }
  }

  // field types and members
  using _key_code_type =
    uint8_t;
  _key_code_type key_code;
  using _is_pressed_type =
    bool;
  _is_pressed_type is_pressed;

  // setters for named parameter idiom
  Type & set__key_code(
    const uint8_t & _arg)
  {
    this->key_code = _arg;
    return *this;
  }
  Type & set__is_pressed(
    const bool & _arg)
  {
    this->is_pressed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::KeyPressedAction_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::KeyPressedAction_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::KeyPressedAction_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::KeyPressedAction_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::KeyPressedAction_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::KeyPressedAction_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::KeyPressedAction_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::KeyPressedAction_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::KeyPressedAction_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::KeyPressedAction_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__KeyPressedAction
    std::shared_ptr<robot_interfaces::msg::KeyPressedAction_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__KeyPressedAction
    std::shared_ptr<robot_interfaces::msg::KeyPressedAction_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KeyPressedAction_ & other) const
  {
    if (this->key_code != other.key_code) {
      return false;
    }
    if (this->is_pressed != other.is_pressed) {
      return false;
    }
    return true;
  }
  bool operator!=(const KeyPressedAction_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KeyPressedAction_

// alias to use template instance with default allocator
using KeyPressedAction =
  robot_interfaces::msg::KeyPressedAction_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__KEY_PRESSED_ACTION__STRUCT_HPP_
