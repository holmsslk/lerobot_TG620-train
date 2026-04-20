// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robot_interfaces:msg/QtRecv.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/qt_recv__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robot_interfaces/msg/detail/qt_recv__struct.h"
#include "robot_interfaces/msg/detail/qt_recv__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/float64_multi_array__functions.h"  // arm_pose_goal, gripper_goal, joint_angles_goal

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robot_interfaces
size_t get_serialized_size_std_msgs__msg__Float64MultiArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robot_interfaces
size_t max_serialized_size_std_msgs__msg__Float64MultiArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robot_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray)();


using _QtRecv__ros_msg_type = robot_interfaces__msg__QtRecv;

static bool _QtRecv__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _QtRecv__ros_msg_type * ros_message = static_cast<const _QtRecv__ros_msg_type *>(untyped_ros_message);
  // Field name: working_mode
  {
    cdr << ros_message->working_mode;
  }

  // Field name: gripper_goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->gripper_goal, cdr))
    {
      return false;
    }
  }

  // Field name: joint_angles_goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_angles_goal, cdr))
    {
      return false;
    }
  }

  // Field name: arm_pose_goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->arm_pose_goal, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _QtRecv__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _QtRecv__ros_msg_type * ros_message = static_cast<_QtRecv__ros_msg_type *>(untyped_ros_message);
  // Field name: working_mode
  {
    cdr >> ros_message->working_mode;
  }

  // Field name: gripper_goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->gripper_goal))
    {
      return false;
    }
  }

  // Field name: joint_angles_goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_angles_goal))
    {
      return false;
    }
  }

  // Field name: arm_pose_goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->arm_pose_goal))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__msg__QtRecv(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _QtRecv__ros_msg_type * ros_message = static_cast<const _QtRecv__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name working_mode
  {
    size_t item_size = sizeof(ros_message->working_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gripper_goal

  current_alignment += get_serialized_size_std_msgs__msg__Float64MultiArray(
    &(ros_message->gripper_goal), current_alignment);
  // field.name joint_angles_goal

  current_alignment += get_serialized_size_std_msgs__msg__Float64MultiArray(
    &(ros_message->joint_angles_goal), current_alignment);
  // field.name arm_pose_goal

  current_alignment += get_serialized_size_std_msgs__msg__Float64MultiArray(
    &(ros_message->arm_pose_goal), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _QtRecv__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__msg__QtRecv(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__msg__QtRecv(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: working_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: gripper_goal
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Float64MultiArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: joint_angles_goal
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Float64MultiArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: arm_pose_goal
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Float64MultiArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robot_interfaces__msg__QtRecv;
    is_plain =
      (
      offsetof(DataType, arm_pose_goal) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _QtRecv__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__msg__QtRecv(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_QtRecv = {
  "robot_interfaces::msg",
  "QtRecv",
  _QtRecv__cdr_serialize,
  _QtRecv__cdr_deserialize,
  _QtRecv__get_serialized_size,
  _QtRecv__max_serialized_size
};

static rosidl_message_type_support_t _QtRecv__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_QtRecv,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, msg, QtRecv)() {
  return &_QtRecv__type_support;
}

#if defined(__cplusplus)
}
#endif
