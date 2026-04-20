// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robot_interfaces:msg/MotorFdb.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/motor_fdb__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robot_interfaces/msg/detail/motor_fdb__struct.h"
#include "robot_interfaces/msg/detail/motor_fdb__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // motor_angle_fdb, motor_effort_fdb, motor_enable_flag, motor_fdb_mode
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // motor_angle_fdb, motor_effort_fdb, motor_enable_flag, motor_fdb_mode

// forward declare type support functions


using _MotorFdb__ros_msg_type = robot_interfaces__msg__MotorFdb;

static bool _MotorFdb__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MotorFdb__ros_msg_type * ros_message = static_cast<const _MotorFdb__ros_msg_type *>(untyped_ros_message);
  // Field name: motor_enable_flag
  {
    size_t size = ros_message->motor_enable_flag.size;
    auto array_ptr = ros_message->motor_enable_flag.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: motor_fdb_mode
  {
    size_t size = ros_message->motor_fdb_mode.size;
    auto array_ptr = ros_message->motor_fdb_mode.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: motor_angle_fdb
  {
    size_t size = ros_message->motor_angle_fdb.size;
    auto array_ptr = ros_message->motor_angle_fdb.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: motor_effort_fdb
  {
    size_t size = ros_message->motor_effort_fdb.size;
    auto array_ptr = ros_message->motor_effort_fdb.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _MotorFdb__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MotorFdb__ros_msg_type * ros_message = static_cast<_MotorFdb__ros_msg_type *>(untyped_ros_message);
  // Field name: motor_enable_flag
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

    if (ros_message->motor_enable_flag.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->motor_enable_flag);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->motor_enable_flag, size)) {
      fprintf(stderr, "failed to create array for field 'motor_enable_flag'");
      return false;
    }
    auto array_ptr = ros_message->motor_enable_flag.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: motor_fdb_mode
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

    if (ros_message->motor_fdb_mode.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->motor_fdb_mode);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->motor_fdb_mode, size)) {
      fprintf(stderr, "failed to create array for field 'motor_fdb_mode'");
      return false;
    }
    auto array_ptr = ros_message->motor_fdb_mode.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: motor_angle_fdb
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

    if (ros_message->motor_angle_fdb.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->motor_angle_fdb);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->motor_angle_fdb, size)) {
      fprintf(stderr, "failed to create array for field 'motor_angle_fdb'");
      return false;
    }
    auto array_ptr = ros_message->motor_angle_fdb.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: motor_effort_fdb
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

    if (ros_message->motor_effort_fdb.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->motor_effort_fdb);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->motor_effort_fdb, size)) {
      fprintf(stderr, "failed to create array for field 'motor_effort_fdb'");
      return false;
    }
    auto array_ptr = ros_message->motor_effort_fdb.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__msg__MotorFdb(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MotorFdb__ros_msg_type * ros_message = static_cast<const _MotorFdb__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name motor_enable_flag
  {
    size_t array_size = ros_message->motor_enable_flag.size;
    auto array_ptr = ros_message->motor_enable_flag.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_fdb_mode
  {
    size_t array_size = ros_message->motor_fdb_mode.size;
    auto array_ptr = ros_message->motor_fdb_mode.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_angle_fdb
  {
    size_t array_size = ros_message->motor_angle_fdb.size;
    auto array_ptr = ros_message->motor_angle_fdb.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_effort_fdb
  {
    size_t array_size = ros_message->motor_effort_fdb.size;
    auto array_ptr = ros_message->motor_effort_fdb.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MotorFdb__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__msg__MotorFdb(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__msg__MotorFdb(
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

  // member: motor_enable_flag
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_fdb_mode
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_angle_fdb
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: motor_effort_fdb
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robot_interfaces__msg__MotorFdb;
    is_plain =
      (
      offsetof(DataType, motor_effort_fdb) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MotorFdb__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__msg__MotorFdb(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MotorFdb = {
  "robot_interfaces::msg",
  "MotorFdb",
  _MotorFdb__cdr_serialize,
  _MotorFdb__cdr_deserialize,
  _MotorFdb__get_serialized_size,
  _MotorFdb__max_serialized_size
};

static rosidl_message_type_support_t _MotorFdb__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MotorFdb,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, msg, MotorFdb)() {
  return &_MotorFdb__type_support;
}

#if defined(__cplusplus)
}
#endif
