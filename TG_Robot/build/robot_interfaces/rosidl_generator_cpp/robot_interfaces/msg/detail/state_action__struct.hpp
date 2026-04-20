// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/StateAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__StateAction __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__StateAction __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StateAction_
{
  using Type = StateAction_<ContainerAllocator>;

  explicit StateAction_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state_name = "";
      this->operation_mode = 0;
    }
  }

  explicit StateAction_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state_name = "";
      this->operation_mode = 0;
    }
  }

  // field types and members
  using _state_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _state_name_type state_name;
  using _operation_mode_type =
    uint8_t;
  _operation_mode_type operation_mode;

  // setters for named parameter idiom
  Type & set__state_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->state_name = _arg;
    return *this;
  }
  Type & set__operation_mode(
    const uint8_t & _arg)
  {
    this->operation_mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t SAVE =
    0u;
  // guard against 'DELETE' being predefined by MSVC by temporarily undefining it
#if defined(_WIN32)
#  if defined(DELETE)
#    pragma push_macro("DELETE")
#    undef DELETE
#  endif
#endif
  static constexpr uint8_t DELETE =
    1u;
#if defined(_WIN32)
#  pragma warning(suppress : 4602)
#  pragma pop_macro("DELETE")
#endif

  // pointer types
  using RawPtr =
    robot_interfaces::msg::StateAction_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::StateAction_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::StateAction_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::StateAction_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::StateAction_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::StateAction_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::StateAction_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::StateAction_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::StateAction_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::StateAction_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__StateAction
    std::shared_ptr<robot_interfaces::msg::StateAction_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__StateAction
    std::shared_ptr<robot_interfaces::msg::StateAction_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateAction_ & other) const
  {
    if (this->state_name != other.state_name) {
      return false;
    }
    if (this->operation_mode != other.operation_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateAction_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateAction_

// alias to use template instance with default allocator
using StateAction =
  robot_interfaces::msg::StateAction_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateAction_<ContainerAllocator>::SAVE;
#endif  // __cplusplus < 201703L
// guard against 'DELETE' being predefined by MSVC by temporarily undefining it
#if defined(_WIN32)
#  if defined(DELETE)
#    pragma push_macro("DELETE")
#    undef DELETE
#  endif
#endif
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateAction_<ContainerAllocator>::DELETE;
#endif  // __cplusplus < 201703L
#if defined(_WIN32)
#  pragma warning(suppress : 4602)
#  pragma pop_macro("DELETE")
#endif

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__STATE_ACTION__STRUCT_HPP_
