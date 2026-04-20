// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_interfaces:msg/MotorFdb.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/motor_fdb__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `motor_enable_flag`
// Member `motor_fdb_mode`
// Member `motor_angle_fdb`
// Member `motor_effort_fdb`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
robot_interfaces__msg__MotorFdb__init(robot_interfaces__msg__MotorFdb * msg)
{
  if (!msg) {
    return false;
  }
  // motor_enable_flag
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->motor_enable_flag, 0)) {
    robot_interfaces__msg__MotorFdb__fini(msg);
    return false;
  }
  // motor_fdb_mode
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->motor_fdb_mode, 0)) {
    robot_interfaces__msg__MotorFdb__fini(msg);
    return false;
  }
  // motor_angle_fdb
  if (!rosidl_runtime_c__float__Sequence__init(&msg->motor_angle_fdb, 0)) {
    robot_interfaces__msg__MotorFdb__fini(msg);
    return false;
  }
  // motor_effort_fdb
  if (!rosidl_runtime_c__float__Sequence__init(&msg->motor_effort_fdb, 0)) {
    robot_interfaces__msg__MotorFdb__fini(msg);
    return false;
  }
  return true;
}

void
robot_interfaces__msg__MotorFdb__fini(robot_interfaces__msg__MotorFdb * msg)
{
  if (!msg) {
    return;
  }
  // motor_enable_flag
  rosidl_runtime_c__uint8__Sequence__fini(&msg->motor_enable_flag);
  // motor_fdb_mode
  rosidl_runtime_c__uint8__Sequence__fini(&msg->motor_fdb_mode);
  // motor_angle_fdb
  rosidl_runtime_c__float__Sequence__fini(&msg->motor_angle_fdb);
  // motor_effort_fdb
  rosidl_runtime_c__float__Sequence__fini(&msg->motor_effort_fdb);
}

bool
robot_interfaces__msg__MotorFdb__are_equal(const robot_interfaces__msg__MotorFdb * lhs, const robot_interfaces__msg__MotorFdb * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor_enable_flag
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->motor_enable_flag), &(rhs->motor_enable_flag)))
  {
    return false;
  }
  // motor_fdb_mode
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->motor_fdb_mode), &(rhs->motor_fdb_mode)))
  {
    return false;
  }
  // motor_angle_fdb
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->motor_angle_fdb), &(rhs->motor_angle_fdb)))
  {
    return false;
  }
  // motor_effort_fdb
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->motor_effort_fdb), &(rhs->motor_effort_fdb)))
  {
    return false;
  }
  return true;
}

bool
robot_interfaces__msg__MotorFdb__copy(
  const robot_interfaces__msg__MotorFdb * input,
  robot_interfaces__msg__MotorFdb * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_enable_flag
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->motor_enable_flag), &(output->motor_enable_flag)))
  {
    return false;
  }
  // motor_fdb_mode
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->motor_fdb_mode), &(output->motor_fdb_mode)))
  {
    return false;
  }
  // motor_angle_fdb
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->motor_angle_fdb), &(output->motor_angle_fdb)))
  {
    return false;
  }
  // motor_effort_fdb
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->motor_effort_fdb), &(output->motor_effort_fdb)))
  {
    return false;
  }
  return true;
}

robot_interfaces__msg__MotorFdb *
robot_interfaces__msg__MotorFdb__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__MotorFdb * msg = (robot_interfaces__msg__MotorFdb *)allocator.allocate(sizeof(robot_interfaces__msg__MotorFdb), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_interfaces__msg__MotorFdb));
  bool success = robot_interfaces__msg__MotorFdb__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_interfaces__msg__MotorFdb__destroy(robot_interfaces__msg__MotorFdb * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_interfaces__msg__MotorFdb__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_interfaces__msg__MotorFdb__Sequence__init(robot_interfaces__msg__MotorFdb__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__MotorFdb * data = NULL;

  if (size) {
    data = (robot_interfaces__msg__MotorFdb *)allocator.zero_allocate(size, sizeof(robot_interfaces__msg__MotorFdb), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_interfaces__msg__MotorFdb__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_interfaces__msg__MotorFdb__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robot_interfaces__msg__MotorFdb__Sequence__fini(robot_interfaces__msg__MotorFdb__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robot_interfaces__msg__MotorFdb__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robot_interfaces__msg__MotorFdb__Sequence *
robot_interfaces__msg__MotorFdb__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__MotorFdb__Sequence * array = (robot_interfaces__msg__MotorFdb__Sequence *)allocator.allocate(sizeof(robot_interfaces__msg__MotorFdb__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_interfaces__msg__MotorFdb__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_interfaces__msg__MotorFdb__Sequence__destroy(robot_interfaces__msg__MotorFdb__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_interfaces__msg__MotorFdb__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_interfaces__msg__MotorFdb__Sequence__are_equal(const robot_interfaces__msg__MotorFdb__Sequence * lhs, const robot_interfaces__msg__MotorFdb__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_interfaces__msg__MotorFdb__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_interfaces__msg__MotorFdb__Sequence__copy(
  const robot_interfaces__msg__MotorFdb__Sequence * input,
  robot_interfaces__msg__MotorFdb__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_interfaces__msg__MotorFdb);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_interfaces__msg__MotorFdb * data =
      (robot_interfaces__msg__MotorFdb *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_interfaces__msg__MotorFdb__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_interfaces__msg__MotorFdb__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_interfaces__msg__MotorFdb__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
