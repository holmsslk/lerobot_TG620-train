// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/ComputeGravity.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'joint_trajectory'
#include "sensor_msgs/msg/detail/joint_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__ComputeGravity_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__ComputeGravity_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ComputeGravity_Request_
{
  using Type = ComputeGravity_Request_<ContainerAllocator>;

  explicit ComputeGravity_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ComputeGravity_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _joint_trajectory_type =
    std::vector<sensor_msgs::msg::JointState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::JointState_<ContainerAllocator>>>;
  _joint_trajectory_type joint_trajectory;

  // setters for named parameter idiom
  Type & set__joint_trajectory(
    const std::vector<sensor_msgs::msg::JointState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::JointState_<ContainerAllocator>>> & _arg)
  {
    this->joint_trajectory = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__ComputeGravity_Request
    std::shared_ptr<robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__ComputeGravity_Request
    std::shared_ptr<robot_interfaces::srv::ComputeGravity_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeGravity_Request_ & other) const
  {
    if (this->joint_trajectory != other.joint_trajectory) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeGravity_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeGravity_Request_

// alias to use template instance with default allocator
using ComputeGravity_Request =
  robot_interfaces::srv::ComputeGravity_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


// Include directives for member types
// Member 'efforts'
// already included above
// #include "sensor_msgs/msg/detail/joint_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__ComputeGravity_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__ComputeGravity_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ComputeGravity_Response_
{
  using Type = ComputeGravity_Response_<ContainerAllocator>;

  explicit ComputeGravity_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ComputeGravity_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _efforts_type =
    std::vector<sensor_msgs::msg::JointState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::JointState_<ContainerAllocator>>>;
  _efforts_type efforts;

  // setters for named parameter idiom
  Type & set__efforts(
    const std::vector<sensor_msgs::msg::JointState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::JointState_<ContainerAllocator>>> & _arg)
  {
    this->efforts = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__ComputeGravity_Response
    std::shared_ptr<robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__ComputeGravity_Response
    std::shared_ptr<robot_interfaces::srv::ComputeGravity_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeGravity_Response_ & other) const
  {
    if (this->efforts != other.efforts) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeGravity_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeGravity_Response_

// alias to use template instance with default allocator
using ComputeGravity_Response =
  robot_interfaces::srv::ComputeGravity_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct ComputeGravity
{
  using Request = robot_interfaces::srv::ComputeGravity_Request;
  using Response = robot_interfaces::srv::ComputeGravity_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__STRUCT_HPP_
