// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_interfaces:msg/QtRecv.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/qt_recv__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `gripper_goal`
// Member `joint_angles_goal`
// Member `arm_pose_goal`
#include "std_msgs/msg/detail/float64_multi_array__functions.h"

bool
robot_interfaces__msg__QtRecv__init(robot_interfaces__msg__QtRecv * msg)
{
  if (!msg) {
    return false;
  }
  // working_mode
  // gripper_goal
  if (!std_msgs__msg__Float64MultiArray__init(&msg->gripper_goal)) {
    robot_interfaces__msg__QtRecv__fini(msg);
    return false;
  }
  // joint_angles_goal
  if (!std_msgs__msg__Float64MultiArray__init(&msg->joint_angles_goal)) {
    robot_interfaces__msg__QtRecv__fini(msg);
    return false;
  }
  // arm_pose_goal
  if (!std_msgs__msg__Float64MultiArray__init(&msg->arm_pose_goal)) {
    robot_interfaces__msg__QtRecv__fini(msg);
    return false;
  }
  return true;
}

void
robot_interfaces__msg__QtRecv__fini(robot_interfaces__msg__QtRecv * msg)
{
  if (!msg) {
    return;
  }
  // working_mode
  // gripper_goal
  std_msgs__msg__Float64MultiArray__fini(&msg->gripper_goal);
  // joint_angles_goal
  std_msgs__msg__Float64MultiArray__fini(&msg->joint_angles_goal);
  // arm_pose_goal
  std_msgs__msg__Float64MultiArray__fini(&msg->arm_pose_goal);
}

bool
robot_interfaces__msg__QtRecv__are_equal(const robot_interfaces__msg__QtRecv * lhs, const robot_interfaces__msg__QtRecv * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // working_mode
  if (lhs->working_mode != rhs->working_mode) {
    return false;
  }
  // gripper_goal
  if (!std_msgs__msg__Float64MultiArray__are_equal(
      &(lhs->gripper_goal), &(rhs->gripper_goal)))
  {
    return false;
  }
  // joint_angles_goal
  if (!std_msgs__msg__Float64MultiArray__are_equal(
      &(lhs->joint_angles_goal), &(rhs->joint_angles_goal)))
  {
    return false;
  }
  // arm_pose_goal
  if (!std_msgs__msg__Float64MultiArray__are_equal(
      &(lhs->arm_pose_goal), &(rhs->arm_pose_goal)))
  {
    return false;
  }
  return true;
}

bool
robot_interfaces__msg__QtRecv__copy(
  const robot_interfaces__msg__QtRecv * input,
  robot_interfaces__msg__QtRecv * output)
{
  if (!input || !output) {
    return false;
  }
  // working_mode
  output->working_mode = input->working_mode;
  // gripper_goal
  if (!std_msgs__msg__Float64MultiArray__copy(
      &(input->gripper_goal), &(output->gripper_goal)))
  {
    return false;
  }
  // joint_angles_goal
  if (!std_msgs__msg__Float64MultiArray__copy(
      &(input->joint_angles_goal), &(output->joint_angles_goal)))
  {
    return false;
  }
  // arm_pose_goal
  if (!std_msgs__msg__Float64MultiArray__copy(
      &(input->arm_pose_goal), &(output->arm_pose_goal)))
  {
    return false;
  }
  return true;
}

robot_interfaces__msg__QtRecv *
robot_interfaces__msg__QtRecv__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__QtRecv * msg = (robot_interfaces__msg__QtRecv *)allocator.allocate(sizeof(robot_interfaces__msg__QtRecv), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_interfaces__msg__QtRecv));
  bool success = robot_interfaces__msg__QtRecv__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_interfaces__msg__QtRecv__destroy(robot_interfaces__msg__QtRecv * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_interfaces__msg__QtRecv__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_interfaces__msg__QtRecv__Sequence__init(robot_interfaces__msg__QtRecv__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__QtRecv * data = NULL;

  if (size) {
    data = (robot_interfaces__msg__QtRecv *)allocator.zero_allocate(size, sizeof(robot_interfaces__msg__QtRecv), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_interfaces__msg__QtRecv__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_interfaces__msg__QtRecv__fini(&data[i - 1]);
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
robot_interfaces__msg__QtRecv__Sequence__fini(robot_interfaces__msg__QtRecv__Sequence * array)
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
      robot_interfaces__msg__QtRecv__fini(&array->data[i]);
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

robot_interfaces__msg__QtRecv__Sequence *
robot_interfaces__msg__QtRecv__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__QtRecv__Sequence * array = (robot_interfaces__msg__QtRecv__Sequence *)allocator.allocate(sizeof(robot_interfaces__msg__QtRecv__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_interfaces__msg__QtRecv__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_interfaces__msg__QtRecv__Sequence__destroy(robot_interfaces__msg__QtRecv__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_interfaces__msg__QtRecv__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_interfaces__msg__QtRecv__Sequence__are_equal(const robot_interfaces__msg__QtRecv__Sequence * lhs, const robot_interfaces__msg__QtRecv__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_interfaces__msg__QtRecv__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_interfaces__msg__QtRecv__Sequence__copy(
  const robot_interfaces__msg__QtRecv__Sequence * input,
  robot_interfaces__msg__QtRecv__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_interfaces__msg__QtRecv);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_interfaces__msg__QtRecv * data =
      (robot_interfaces__msg__QtRecv *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_interfaces__msg__QtRecv__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_interfaces__msg__QtRecv__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_interfaces__msg__QtRecv__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
