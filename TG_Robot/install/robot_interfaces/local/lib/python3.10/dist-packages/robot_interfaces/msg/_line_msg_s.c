// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robot_interfaces:msg/LineMsg.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "robot_interfaces/msg/detail/line_msg__struct.h"
#include "robot_interfaces/msg/detail/line_msg__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool robot_interfaces__msg__line_msg__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("robot_interfaces.msg._line_msg.LineMsg", full_classname_dest, 38) == 0);
  }
  robot_interfaces__msg__LineMsg * ros_message = _ros_message;
  {  // type
    PyObject * field = PyObject_GetAttrString(_pymsg, "type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // initial_pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "initial_pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->initial_pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // delta_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->delta_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // delta_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->delta_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // delta_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->delta_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // radius
    PyObject * field = PyObject_GetAttrString(_pymsg, "radius");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->radius = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robot_interfaces__msg__line_msg__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LineMsg */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robot_interfaces.msg._line_msg");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LineMsg");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robot_interfaces__msg__LineMsg * ros_message = (robot_interfaces__msg__LineMsg *)raw_ros_message;
  {  // type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // initial_pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->initial_pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "initial_pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // delta_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->delta_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // delta_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->delta_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // delta_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->delta_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // radius
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->radius);
    {
      int rc = PyObject_SetAttrString(_pymessage, "radius", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
