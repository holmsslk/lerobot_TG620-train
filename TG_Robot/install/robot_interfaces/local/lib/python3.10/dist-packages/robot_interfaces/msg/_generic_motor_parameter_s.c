// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robot_interfaces:msg/GenericMotorParameter.idl
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
#include "robot_interfaces/msg/detail/generic_motor_parameter__struct.h"
#include "robot_interfaces/msg/detail/generic_motor_parameter__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robot_interfaces__msg__generic_motor_parameter__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[68];
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
    assert(strncmp("robot_interfaces.msg._generic_motor_parameter.GenericMotorParameter", full_classname_dest, 67) == 0);
  }
  robot_interfaces__msg__GenericMotorParameter * ros_message = _ros_message;
  {  // motor_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->motor_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // command_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "command_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->command_type = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // float_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "float_value");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->float_value = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // int_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "int_value");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->int_value = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robot_interfaces__msg__generic_motor_parameter__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GenericMotorParameter */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robot_interfaces.msg._generic_motor_parameter");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GenericMotorParameter");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robot_interfaces__msg__GenericMotorParameter * ros_message = (robot_interfaces__msg__GenericMotorParameter *)raw_ros_message;
  {  // motor_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->motor_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // command_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->command_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "command_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // float_value
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->float_value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "float_value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // int_value
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->int_value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "int_value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
