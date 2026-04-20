// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/ComputeGravity.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint_trajectory'
#include "sensor_msgs/msg/detail/joint_state__struct.h"

/// Struct defined in srv/ComputeGravity in the package robot_interfaces.
typedef struct robot_interfaces__srv__ComputeGravity_Request
{
  sensor_msgs__msg__JointState__Sequence joint_trajectory;
} robot_interfaces__srv__ComputeGravity_Request;

// Struct for a sequence of robot_interfaces__srv__ComputeGravity_Request.
typedef struct robot_interfaces__srv__ComputeGravity_Request__Sequence
{
  robot_interfaces__srv__ComputeGravity_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__ComputeGravity_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'efforts'
// already included above
// #include "sensor_msgs/msg/detail/joint_state__struct.h"

/// Struct defined in srv/ComputeGravity in the package robot_interfaces.
typedef struct robot_interfaces__srv__ComputeGravity_Response
{
  sensor_msgs__msg__JointState__Sequence efforts;
} robot_interfaces__srv__ComputeGravity_Response;

// Struct for a sequence of robot_interfaces__srv__ComputeGravity_Response.
typedef struct robot_interfaces__srv__ComputeGravity_Response__Sequence
{
  robot_interfaces__srv__ComputeGravity_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__ComputeGravity_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__COMPUTE_GRAVITY__STRUCT_H_
