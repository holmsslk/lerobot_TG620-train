// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/LineMsg.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'initial_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__LineMsg __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__LineMsg __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LineMsg_
{
  using Type = LineMsg_<ContainerAllocator>;

  explicit LineMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : initial_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->delta_x = 0.0f;
      this->delta_y = 0.0f;
      this->delta_z = 0.0f;
      this->radius = 0.0f;
    }
  }

  explicit LineMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : initial_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->delta_x = 0.0f;
      this->delta_y = 0.0f;
      this->delta_z = 0.0f;
      this->radius = 0.0f;
    }
  }

  // field types and members
  using _type_type =
    uint8_t;
  _type_type type;
  using _initial_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _initial_pose_type initial_pose;
  using _delta_x_type =
    float;
  _delta_x_type delta_x;
  using _delta_y_type =
    float;
  _delta_y_type delta_y;
  using _delta_z_type =
    float;
  _delta_z_type delta_z;
  using _radius_type =
    float;
  _radius_type radius;

  // setters for named parameter idiom
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__initial_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->initial_pose = _arg;
    return *this;
  }
  Type & set__delta_x(
    const float & _arg)
  {
    this->delta_x = _arg;
    return *this;
  }
  Type & set__delta_y(
    const float & _arg)
  {
    this->delta_y = _arg;
    return *this;
  }
  Type & set__delta_z(
    const float & _arg)
  {
    this->delta_z = _arg;
    return *this;
  }
  Type & set__radius(
    const float & _arg)
  {
    this->radius = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::LineMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::LineMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::LineMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::LineMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::LineMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::LineMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::LineMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::LineMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::LineMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::LineMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__LineMsg
    std::shared_ptr<robot_interfaces::msg::LineMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__LineMsg
    std::shared_ptr<robot_interfaces::msg::LineMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LineMsg_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->initial_pose != other.initial_pose) {
      return false;
    }
    if (this->delta_x != other.delta_x) {
      return false;
    }
    if (this->delta_y != other.delta_y) {
      return false;
    }
    if (this->delta_z != other.delta_z) {
      return false;
    }
    if (this->radius != other.radius) {
      return false;
    }
    return true;
  }
  bool operator!=(const LineMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LineMsg_

// alias to use template instance with default allocator
using LineMsg =
  robot_interfaces::msg::LineMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__LINE_MSG__STRUCT_HPP_
