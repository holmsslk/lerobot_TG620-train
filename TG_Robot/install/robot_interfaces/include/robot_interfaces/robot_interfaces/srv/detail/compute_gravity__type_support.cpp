// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robot_interfaces:srv/ComputeGravity.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robot_interfaces/srv/detail/compute_gravity__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robot_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ComputeGravity_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robot_interfaces::srv::ComputeGravity_Request(_init);
}

void ComputeGravity_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robot_interfaces::srv::ComputeGravity_Request *>(message_memory);
  typed_message->~ComputeGravity_Request();
}

size_t size_function__ComputeGravity_Request__joint_trajectory(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::JointState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ComputeGravity_Request__joint_trajectory(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::JointState> *>(untyped_member);
  return &member[index];
}

void * get_function__ComputeGravity_Request__joint_trajectory(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::JointState> *>(untyped_member);
  return &member[index];
}

void fetch_function__ComputeGravity_Request__joint_trajectory(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sensor_msgs::msg::JointState *>(
    get_const_function__ComputeGravity_Request__joint_trajectory(untyped_member, index));
  auto & value = *reinterpret_cast<sensor_msgs::msg::JointState *>(untyped_value);
  value = item;
}

void assign_function__ComputeGravity_Request__joint_trajectory(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sensor_msgs::msg::JointState *>(
    get_function__ComputeGravity_Request__joint_trajectory(untyped_member, index));
  const auto & value = *reinterpret_cast<const sensor_msgs::msg::JointState *>(untyped_value);
  item = value;
}

void resize_function__ComputeGravity_Request__joint_trajectory(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::JointState> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ComputeGravity_Request_message_member_array[1] = {
  {
    "joint_trajectory",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::JointState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::srv::ComputeGravity_Request, joint_trajectory),  // bytes offset in struct
    nullptr,  // default value
    size_function__ComputeGravity_Request__joint_trajectory,  // size() function pointer
    get_const_function__ComputeGravity_Request__joint_trajectory,  // get_const(index) function pointer
    get_function__ComputeGravity_Request__joint_trajectory,  // get(index) function pointer
    fetch_function__ComputeGravity_Request__joint_trajectory,  // fetch(index, &value) function pointer
    assign_function__ComputeGravity_Request__joint_trajectory,  // assign(index, value) function pointer
    resize_function__ComputeGravity_Request__joint_trajectory  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ComputeGravity_Request_message_members = {
  "robot_interfaces::srv",  // message namespace
  "ComputeGravity_Request",  // message name
  1,  // number of fields
  sizeof(robot_interfaces::srv::ComputeGravity_Request),
  ComputeGravity_Request_message_member_array,  // message members
  ComputeGravity_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ComputeGravity_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ComputeGravity_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ComputeGravity_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_interfaces::srv::ComputeGravity_Request>()
{
  return &::robot_interfaces::srv::rosidl_typesupport_introspection_cpp::ComputeGravity_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_interfaces, srv, ComputeGravity_Request)() {
  return &::robot_interfaces::srv::rosidl_typesupport_introspection_cpp::ComputeGravity_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "robot_interfaces/srv/detail/compute_gravity__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robot_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ComputeGravity_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robot_interfaces::srv::ComputeGravity_Response(_init);
}

void ComputeGravity_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robot_interfaces::srv::ComputeGravity_Response *>(message_memory);
  typed_message->~ComputeGravity_Response();
}

size_t size_function__ComputeGravity_Response__efforts(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::JointState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ComputeGravity_Response__efforts(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::JointState> *>(untyped_member);
  return &member[index];
}

void * get_function__ComputeGravity_Response__efforts(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::JointState> *>(untyped_member);
  return &member[index];
}

void fetch_function__ComputeGravity_Response__efforts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sensor_msgs::msg::JointState *>(
    get_const_function__ComputeGravity_Response__efforts(untyped_member, index));
  auto & value = *reinterpret_cast<sensor_msgs::msg::JointState *>(untyped_value);
  value = item;
}

void assign_function__ComputeGravity_Response__efforts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sensor_msgs::msg::JointState *>(
    get_function__ComputeGravity_Response__efforts(untyped_member, index));
  const auto & value = *reinterpret_cast<const sensor_msgs::msg::JointState *>(untyped_value);
  item = value;
}

void resize_function__ComputeGravity_Response__efforts(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::JointState> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ComputeGravity_Response_message_member_array[1] = {
  {
    "efforts",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::JointState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces::srv::ComputeGravity_Response, efforts),  // bytes offset in struct
    nullptr,  // default value
    size_function__ComputeGravity_Response__efforts,  // size() function pointer
    get_const_function__ComputeGravity_Response__efforts,  // get_const(index) function pointer
    get_function__ComputeGravity_Response__efforts,  // get(index) function pointer
    fetch_function__ComputeGravity_Response__efforts,  // fetch(index, &value) function pointer
    assign_function__ComputeGravity_Response__efforts,  // assign(index, value) function pointer
    resize_function__ComputeGravity_Response__efforts  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ComputeGravity_Response_message_members = {
  "robot_interfaces::srv",  // message namespace
  "ComputeGravity_Response",  // message name
  1,  // number of fields
  sizeof(robot_interfaces::srv::ComputeGravity_Response),
  ComputeGravity_Response_message_member_array,  // message members
  ComputeGravity_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ComputeGravity_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ComputeGravity_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ComputeGravity_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_interfaces::srv::ComputeGravity_Response>()
{
  return &::robot_interfaces::srv::rosidl_typesupport_introspection_cpp::ComputeGravity_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_interfaces, srv, ComputeGravity_Response)() {
  return &::robot_interfaces::srv::rosidl_typesupport_introspection_cpp::ComputeGravity_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "robot_interfaces/srv/detail/compute_gravity__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace robot_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers ComputeGravity_service_members = {
  "robot_interfaces::srv",  // service namespace
  "ComputeGravity",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<robot_interfaces::srv::ComputeGravity>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t ComputeGravity_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ComputeGravity_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robot_interfaces::srv::ComputeGravity>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::robot_interfaces::srv::rosidl_typesupport_introspection_cpp::ComputeGravity_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robot_interfaces::srv::ComputeGravity_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robot_interfaces::srv::ComputeGravity_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_interfaces, srv, ComputeGravity)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<robot_interfaces::srv::ComputeGravity>();
}

#ifdef __cplusplus
}
#endif
