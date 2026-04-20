// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_interfaces:msg/LineMsg.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/line_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `initial_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
robot_interfaces__msg__LineMsg__init(robot_interfaces__msg__LineMsg * msg)
{
  if (!msg) {
    return false;
  }
  // type
  // initial_pose
  if (!geometry_msgs__msg__Pose__init(&msg->initial_pose)) {
    robot_interfaces__msg__LineMsg__fini(msg);
    return false;
  }
  // delta_x
  // delta_y
  // delta_z
  // radius
  return true;
}

void
robot_interfaces__msg__LineMsg__fini(robot_interfaces__msg__LineMsg * msg)
{
  if (!msg) {
    return;
  }
  // type
  // initial_pose
  geometry_msgs__msg__Pose__fini(&msg->initial_pose);
  // delta_x
  // delta_y
  // delta_z
  // radius
}

bool
robot_interfaces__msg__LineMsg__are_equal(const robot_interfaces__msg__LineMsg * lhs, const robot_interfaces__msg__LineMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // initial_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->initial_pose), &(rhs->initial_pose)))
  {
    return false;
  }
  // delta_x
  if (lhs->delta_x != rhs->delta_x) {
    return false;
  }
  // delta_y
  if (lhs->delta_y != rhs->delta_y) {
    return false;
  }
  // delta_z
  if (lhs->delta_z != rhs->delta_z) {
    return false;
  }
  // radius
  if (lhs->radius != rhs->radius) {
    return false;
  }
  return true;
}

bool
robot_interfaces__msg__LineMsg__copy(
  const robot_interfaces__msg__LineMsg * input,
  robot_interfaces__msg__LineMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  output->type = input->type;
  // initial_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->initial_pose), &(output->initial_pose)))
  {
    return false;
  }
  // delta_x
  output->delta_x = input->delta_x;
  // delta_y
  output->delta_y = input->delta_y;
  // delta_z
  output->delta_z = input->delta_z;
  // radius
  output->radius = input->radius;
  return true;
}

robot_interfaces__msg__LineMsg *
robot_interfaces__msg__LineMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__LineMsg * msg = (robot_interfaces__msg__LineMsg *)allocator.allocate(sizeof(robot_interfaces__msg__LineMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_interfaces__msg__LineMsg));
  bool success = robot_interfaces__msg__LineMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_interfaces__msg__LineMsg__destroy(robot_interfaces__msg__LineMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_interfaces__msg__LineMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_interfaces__msg__LineMsg__Sequence__init(robot_interfaces__msg__LineMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__LineMsg * data = NULL;

  if (size) {
    data = (robot_interfaces__msg__LineMsg *)allocator.zero_allocate(size, sizeof(robot_interfaces__msg__LineMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_interfaces__msg__LineMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_interfaces__msg__LineMsg__fini(&data[i - 1]);
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
robot_interfaces__msg__LineMsg__Sequence__fini(robot_interfaces__msg__LineMsg__Sequence * array)
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
      robot_interfaces__msg__LineMsg__fini(&array->data[i]);
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

robot_interfaces__msg__LineMsg__Sequence *
robot_interfaces__msg__LineMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__LineMsg__Sequence * array = (robot_interfaces__msg__LineMsg__Sequence *)allocator.allocate(sizeof(robot_interfaces__msg__LineMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_interfaces__msg__LineMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_interfaces__msg__LineMsg__Sequence__destroy(robot_interfaces__msg__LineMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_interfaces__msg__LineMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_interfaces__msg__LineMsg__Sequence__are_equal(const robot_interfaces__msg__LineMsg__Sequence * lhs, const robot_interfaces__msg__LineMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_interfaces__msg__LineMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_interfaces__msg__LineMsg__Sequence__copy(
  const robot_interfaces__msg__LineMsg__Sequence * input,
  robot_interfaces__msg__LineMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_interfaces__msg__LineMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_interfaces__msg__LineMsg * data =
      (robot_interfaces__msg__LineMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_interfaces__msg__LineMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_interfaces__msg__LineMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_interfaces__msg__LineMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
