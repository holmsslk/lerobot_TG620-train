// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_interfaces:msg/StateAction.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/state_action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `state_name`
#include "rosidl_runtime_c/string_functions.h"

bool
robot_interfaces__msg__StateAction__init(robot_interfaces__msg__StateAction * msg)
{
  if (!msg) {
    return false;
  }
  // state_name
  if (!rosidl_runtime_c__String__init(&msg->state_name)) {
    robot_interfaces__msg__StateAction__fini(msg);
    return false;
  }
  // operation_mode
  return true;
}

void
robot_interfaces__msg__StateAction__fini(robot_interfaces__msg__StateAction * msg)
{
  if (!msg) {
    return;
  }
  // state_name
  rosidl_runtime_c__String__fini(&msg->state_name);
  // operation_mode
}

bool
robot_interfaces__msg__StateAction__are_equal(const robot_interfaces__msg__StateAction * lhs, const robot_interfaces__msg__StateAction * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->state_name), &(rhs->state_name)))
  {
    return false;
  }
  // operation_mode
  if (lhs->operation_mode != rhs->operation_mode) {
    return false;
  }
  return true;
}

bool
robot_interfaces__msg__StateAction__copy(
  const robot_interfaces__msg__StateAction * input,
  robot_interfaces__msg__StateAction * output)
{
  if (!input || !output) {
    return false;
  }
  // state_name
  if (!rosidl_runtime_c__String__copy(
      &(input->state_name), &(output->state_name)))
  {
    return false;
  }
  // operation_mode
  output->operation_mode = input->operation_mode;
  return true;
}

robot_interfaces__msg__StateAction *
robot_interfaces__msg__StateAction__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__StateAction * msg = (robot_interfaces__msg__StateAction *)allocator.allocate(sizeof(robot_interfaces__msg__StateAction), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_interfaces__msg__StateAction));
  bool success = robot_interfaces__msg__StateAction__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_interfaces__msg__StateAction__destroy(robot_interfaces__msg__StateAction * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_interfaces__msg__StateAction__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_interfaces__msg__StateAction__Sequence__init(robot_interfaces__msg__StateAction__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__StateAction * data = NULL;

  if (size) {
    data = (robot_interfaces__msg__StateAction *)allocator.zero_allocate(size, sizeof(robot_interfaces__msg__StateAction), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_interfaces__msg__StateAction__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_interfaces__msg__StateAction__fini(&data[i - 1]);
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
robot_interfaces__msg__StateAction__Sequence__fini(robot_interfaces__msg__StateAction__Sequence * array)
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
      robot_interfaces__msg__StateAction__fini(&array->data[i]);
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

robot_interfaces__msg__StateAction__Sequence *
robot_interfaces__msg__StateAction__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__StateAction__Sequence * array = (robot_interfaces__msg__StateAction__Sequence *)allocator.allocate(sizeof(robot_interfaces__msg__StateAction__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_interfaces__msg__StateAction__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_interfaces__msg__StateAction__Sequence__destroy(robot_interfaces__msg__StateAction__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_interfaces__msg__StateAction__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_interfaces__msg__StateAction__Sequence__are_equal(const robot_interfaces__msg__StateAction__Sequence * lhs, const robot_interfaces__msg__StateAction__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_interfaces__msg__StateAction__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_interfaces__msg__StateAction__Sequence__copy(
  const robot_interfaces__msg__StateAction__Sequence * input,
  robot_interfaces__msg__StateAction__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_interfaces__msg__StateAction);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_interfaces__msg__StateAction * data =
      (robot_interfaces__msg__StateAction *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_interfaces__msg__StateAction__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_interfaces__msg__StateAction__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_interfaces__msg__StateAction__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
