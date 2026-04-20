// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_interfaces:srv/ComputeGravity.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_interfaces/srv/detail/compute_gravity__rosidl_typesupport_introspection_c.h"
#include "robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_interfaces/srv/detail/compute_gravity__functions.h"
#include "robot_interfaces/srv/detail/compute_gravity__struct.h"


// Include directives for member types
// Member `joint_trajectory`
#include "sensor_msgs/msg/joint_state.h"
// Member `joint_trajectory`
#include "sensor_msgs/msg/detail/joint_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_interfaces__srv__ComputeGravity_Request__init(message_memory);
}

void robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_fini_function(void * message_memory)
{
  robot_interfaces__srv__ComputeGravity_Request__fini(message_memory);
}

size_t robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__size_function__ComputeGravity_Request__joint_trajectory(
  const void * untyped_member)
{
  const sensor_msgs__msg__JointState__Sequence * member =
    (const sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__get_const_function__ComputeGravity_Request__joint_trajectory(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__JointState__Sequence * member =
    (const sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__get_function__ComputeGravity_Request__joint_trajectory(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__JointState__Sequence * member =
    (sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__fetch_function__ComputeGravity_Request__joint_trajectory(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__JointState * item =
    ((const sensor_msgs__msg__JointState *)
    robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__get_const_function__ComputeGravity_Request__joint_trajectory(untyped_member, index));
  sensor_msgs__msg__JointState * value =
    (sensor_msgs__msg__JointState *)(untyped_value);
  *value = *item;
}

void robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__assign_function__ComputeGravity_Request__joint_trajectory(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__JointState * item =
    ((sensor_msgs__msg__JointState *)
    robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__get_function__ComputeGravity_Request__joint_trajectory(untyped_member, index));
  const sensor_msgs__msg__JointState * value =
    (const sensor_msgs__msg__JointState *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__resize_function__ComputeGravity_Request__joint_trajectory(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__JointState__Sequence * member =
    (sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  sensor_msgs__msg__JointState__Sequence__fini(member);
  return sensor_msgs__msg__JointState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_message_member_array[1] = {
  {
    "joint_trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__srv__ComputeGravity_Request, joint_trajectory),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__size_function__ComputeGravity_Request__joint_trajectory,  // size() function pointer
    robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__get_const_function__ComputeGravity_Request__joint_trajectory,  // get_const(index) function pointer
    robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__get_function__ComputeGravity_Request__joint_trajectory,  // get(index) function pointer
    robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__fetch_function__ComputeGravity_Request__joint_trajectory,  // fetch(index, &value) function pointer
    robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__assign_function__ComputeGravity_Request__joint_trajectory,  // assign(index, value) function pointer
    robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__resize_function__ComputeGravity_Request__joint_trajectory  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_message_members = {
  "robot_interfaces__srv",  // message namespace
  "ComputeGravity_Request",  // message name
  1,  // number of fields
  sizeof(robot_interfaces__srv__ComputeGravity_Request),
  robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_message_member_array,  // message members
  robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_message_type_support_handle = {
  0,
  &robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_interfaces, srv, ComputeGravity_Request)() {
  robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, JointState)();
  if (!robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_message_type_support_handle.typesupport_identifier) {
    robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_interfaces__srv__ComputeGravity_Request__rosidl_typesupport_introspection_c__ComputeGravity_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robot_interfaces/srv/detail/compute_gravity__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robot_interfaces/srv/detail/compute_gravity__functions.h"
// already included above
// #include "robot_interfaces/srv/detail/compute_gravity__struct.h"


// Include directives for member types
// Member `efforts`
// already included above
// #include "sensor_msgs/msg/joint_state.h"
// Member `efforts`
// already included above
// #include "sensor_msgs/msg/detail/joint_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_interfaces__srv__ComputeGravity_Response__init(message_memory);
}

void robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_fini_function(void * message_memory)
{
  robot_interfaces__srv__ComputeGravity_Response__fini(message_memory);
}

size_t robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__size_function__ComputeGravity_Response__efforts(
  const void * untyped_member)
{
  const sensor_msgs__msg__JointState__Sequence * member =
    (const sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__get_const_function__ComputeGravity_Response__efforts(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__JointState__Sequence * member =
    (const sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__get_function__ComputeGravity_Response__efforts(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__JointState__Sequence * member =
    (sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__fetch_function__ComputeGravity_Response__efforts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__JointState * item =
    ((const sensor_msgs__msg__JointState *)
    robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__get_const_function__ComputeGravity_Response__efforts(untyped_member, index));
  sensor_msgs__msg__JointState * value =
    (sensor_msgs__msg__JointState *)(untyped_value);
  *value = *item;
}

void robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__assign_function__ComputeGravity_Response__efforts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__JointState * item =
    ((sensor_msgs__msg__JointState *)
    robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__get_function__ComputeGravity_Response__efforts(untyped_member, index));
  const sensor_msgs__msg__JointState * value =
    (const sensor_msgs__msg__JointState *)(untyped_value);
  *item = *value;
}

bool robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__resize_function__ComputeGravity_Response__efforts(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__JointState__Sequence * member =
    (sensor_msgs__msg__JointState__Sequence *)(untyped_member);
  sensor_msgs__msg__JointState__Sequence__fini(member);
  return sensor_msgs__msg__JointState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_message_member_array[1] = {
  {
    "efforts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_interfaces__srv__ComputeGravity_Response, efforts),  // bytes offset in struct
    NULL,  // default value
    robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__size_function__ComputeGravity_Response__efforts,  // size() function pointer
    robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__get_const_function__ComputeGravity_Response__efforts,  // get_const(index) function pointer
    robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__get_function__ComputeGravity_Response__efforts,  // get(index) function pointer
    robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__fetch_function__ComputeGravity_Response__efforts,  // fetch(index, &value) function pointer
    robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__assign_function__ComputeGravity_Response__efforts,  // assign(index, value) function pointer
    robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__resize_function__ComputeGravity_Response__efforts  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_message_members = {
  "robot_interfaces__srv",  // message namespace
  "ComputeGravity_Response",  // message name
  1,  // number of fields
  sizeof(robot_interfaces__srv__ComputeGravity_Response),
  robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_message_member_array,  // message members
  robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_message_type_support_handle = {
  0,
  &robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_interfaces, srv, ComputeGravity_Response)() {
  robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, JointState)();
  if (!robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_message_type_support_handle.typesupport_identifier) {
    robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_interfaces__srv__ComputeGravity_Response__rosidl_typesupport_introspection_c__ComputeGravity_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "robot_interfaces/srv/detail/compute_gravity__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers robot_interfaces__srv__detail__compute_gravity__rosidl_typesupport_introspection_c__ComputeGravity_service_members = {
  "robot_interfaces__srv",  // service namespace
  "ComputeGravity",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // robot_interfaces__srv__detail__compute_gravity__rosidl_typesupport_introspection_c__ComputeGravity_Request_message_type_support_handle,
  NULL  // response message
  // robot_interfaces__srv__detail__compute_gravity__rosidl_typesupport_introspection_c__ComputeGravity_Response_message_type_support_handle
};

static rosidl_service_type_support_t robot_interfaces__srv__detail__compute_gravity__rosidl_typesupport_introspection_c__ComputeGravity_service_type_support_handle = {
  0,
  &robot_interfaces__srv__detail__compute_gravity__rosidl_typesupport_introspection_c__ComputeGravity_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_interfaces, srv, ComputeGravity_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_interfaces, srv, ComputeGravity_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_interfaces, srv, ComputeGravity)() {
  if (!robot_interfaces__srv__detail__compute_gravity__rosidl_typesupport_introspection_c__ComputeGravity_service_type_support_handle.typesupport_identifier) {
    robot_interfaces__srv__detail__compute_gravity__rosidl_typesupport_introspection_c__ComputeGravity_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)robot_interfaces__srv__detail__compute_gravity__rosidl_typesupport_introspection_c__ComputeGravity_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_interfaces, srv, ComputeGravity_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_interfaces, srv, ComputeGravity_Response)()->data;
  }

  return &robot_interfaces__srv__detail__compute_gravity__rosidl_typesupport_introspection_c__ComputeGravity_service_type_support_handle;
}
