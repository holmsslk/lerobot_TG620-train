# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:msg/MotorFdb.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'motor_enable_flag'
# Member 'motor_fdb_mode'
# Member 'motor_angle_fdb'
# Member 'motor_effort_fdb'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MotorFdb(type):
    """Metaclass of message 'MotorFdb'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.msg.MotorFdb')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motor_fdb
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motor_fdb
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motor_fdb
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motor_fdb
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motor_fdb

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MotorFdb(metaclass=Metaclass_MotorFdb):
    """Message class 'MotorFdb'."""

    __slots__ = [
        '_motor_enable_flag',
        '_motor_fdb_mode',
        '_motor_angle_fdb',
        '_motor_effort_fdb',
    ]

    _fields_and_field_types = {
        'motor_enable_flag': 'sequence<uint8>',
        'motor_fdb_mode': 'sequence<uint8>',
        'motor_angle_fdb': 'sequence<float>',
        'motor_effort_fdb': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.motor_enable_flag = array.array('B', kwargs.get('motor_enable_flag', []))
        self.motor_fdb_mode = array.array('B', kwargs.get('motor_fdb_mode', []))
        self.motor_angle_fdb = array.array('f', kwargs.get('motor_angle_fdb', []))
        self.motor_effort_fdb = array.array('f', kwargs.get('motor_effort_fdb', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.motor_enable_flag != other.motor_enable_flag:
            return False
        if self.motor_fdb_mode != other.motor_fdb_mode:
            return False
        if self.motor_angle_fdb != other.motor_angle_fdb:
            return False
        if self.motor_effort_fdb != other.motor_effort_fdb:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def motor_enable_flag(self):
        """Message field 'motor_enable_flag'."""
        return self._motor_enable_flag

    @motor_enable_flag.setter
    def motor_enable_flag(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'motor_enable_flag' array.array() must have the type code of 'B'"
            self._motor_enable_flag = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'motor_enable_flag' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._motor_enable_flag = array.array('B', value)

    @builtins.property
    def motor_fdb_mode(self):
        """Message field 'motor_fdb_mode'."""
        return self._motor_fdb_mode

    @motor_fdb_mode.setter
    def motor_fdb_mode(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'motor_fdb_mode' array.array() must have the type code of 'B'"
            self._motor_fdb_mode = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'motor_fdb_mode' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._motor_fdb_mode = array.array('B', value)

    @builtins.property
    def motor_angle_fdb(self):
        """Message field 'motor_angle_fdb'."""
        return self._motor_angle_fdb

    @motor_angle_fdb.setter
    def motor_angle_fdb(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'motor_angle_fdb' array.array() must have the type code of 'f'"
            self._motor_angle_fdb = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'motor_angle_fdb' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._motor_angle_fdb = array.array('f', value)

    @builtins.property
    def motor_effort_fdb(self):
        """Message field 'motor_effort_fdb'."""
        return self._motor_effort_fdb

    @motor_effort_fdb.setter
    def motor_effort_fdb(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'motor_effort_fdb' array.array() must have the type code of 'f'"
            self._motor_effort_fdb = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'motor_effort_fdb' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._motor_effort_fdb = array.array('f', value)
