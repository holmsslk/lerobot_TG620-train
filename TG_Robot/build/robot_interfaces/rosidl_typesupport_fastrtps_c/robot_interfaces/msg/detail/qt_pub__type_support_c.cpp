// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robot_interfaces:msg/QtPub.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/qt_pub__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robot_interfaces/msg/detail/qt_pub__struct.h"
#include "robot_interfaces/msg/detail/qt_pub__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // gripper_msgs, joint_group_positions
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // gripper_msgs, joint_group_positions

// forward declare type support functions


using _QtPub__ros_msg_type = robot_interfaces__msg__QtPub;

static bool _QtPub__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _QtPub__ros_msg_type * ros_message = static_cast<const _QtPub__ros_msg_type *>(untyped_ros_message);
  // Field name: working_mode
  {
    cdr << ros_message->working_mode;
  }

  // Field name: enable_flag
  {
    cdr << (ros_message->enable_flag ? true : false);
  }

  // Field name: joint_group_positions
  {
    size_t size = ros_message->joint_group_positions.size;
    auto array_ptr = ros_message->joint_group_positions.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: gripper_msgs
  {
    size_t size = ros_message->gripper_msgs.size;
    auto array_ptr = ros_message->gripper_msgs.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _QtPub__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _QtPub__ros_msg_type * ros_message = static_cast<_QtPub__ros_msg_type *>(untyped_ros_message);
  // Field name: working_mode
  {
    cdr >> ros_message->working_mode;
  }

  // Field name: enable_flag
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->enable_flag = tmp ? true : false;
  }

  // Field name: joint_group_positions
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->joint_group_positions.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->joint_group_positions);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->joint_group_positions, size)) {
      fprintf(stderr, "failed to create array for field 'joint_group_positions'");
      return false;
    }
    auto array_ptr = ros_message->joint_group_positions.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: gripper_msgs
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->gripper_msgs.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->gripper_msgs);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->gripper_msgs, size)) {
      fprintf(stderr, "failed to create array for field 'gripper_msgs'");
      return false;
    }
    auto array_ptr = ros_message->gripper_msgs.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__msg__QtPub(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _QtPub__ros_msg_type * ros_message = static_cast<const _QtPub__ros_msg_type *>(untyped_ros_message);
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
  // field.name enable_flag
  {
    size_t item_size = sizeof(ros_message->enable_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_group_positions
  {
    size_t array_size = ros_message->joint_group_positions.size;
    auto array_ptr = ros_message->joint_group_positions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gripper_msgs
  {
    size_t array_size = ros_message->gripper_msgs.size;
    auto array_ptr = ros_message->gripper_msgs.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _QtPub__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__msg__QtPub(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__msg__QtPub(
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
  // member: enable_flag
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: joint_group_positions
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gripper_msgs
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robot_interfaces__msg__QtPub;
    is_plain =
      (
      offsetof(DataType, gripper_msgs) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _QtPub__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__msg__QtPub(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_QtPub = {
  "robot_interfaces::msg",
  "QtPub",
  _QtPub__cdr_serialize,
  _QtPub__cdr_deserialize,
  _QtPub__get_serialized_size,
  _QtPub__max_serialized_size
};

static rosidl_message_type_support_t _QtPub__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_QtPub,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, msg, QtPub)() {
  return &_QtPub__type_support;
}

#if defined(__cplusplus)
}
#endif
