# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:msg/RobotControlMsg.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'motor_enable_flag'
# Member 'motor_mode'
# Member 'position'
# Member 'velocity'
# Member 'effort'
# Member 'kp'
# Member 'kd'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotControlMsg(type):
    """Metaclass of message 'RobotControlMsg'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'MOTOR_DISABLE': 0,
        'MOTOR_ENABLE': 1,
        'CURRENT_MODE': 2,
        'EFFORT_POSITION_MODE': 3,
        'SPEED_MODE': 4,
        'POSITION_ABS_MODE': 5,
        'POSITION_INC_MODE': 6,
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
                'robot_interfaces.msg.RobotControlMsg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_control_msg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_control_msg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_control_msg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_control_msg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_control_msg

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'MOTOR_DISABLE': cls.__constants['MOTOR_DISABLE'],
            'MOTOR_ENABLE': cls.__constants['MOTOR_ENABLE'],
            'CURRENT_MODE': cls.__constants['CURRENT_MODE'],
            'EFFORT_POSITION_MODE': cls.__constants['EFFORT_POSITION_MODE'],
            'SPEED_MODE': cls.__constants['SPEED_MODE'],
            'POSITION_ABS_MODE': cls.__constants['POSITION_ABS_MODE'],
            'POSITION_INC_MODE': cls.__constants['POSITION_INC_MODE'],
        }

    @property
    def MOTOR_DISABLE(self):
        """Message constant 'MOTOR_DISABLE'."""
        return Metaclass_RobotControlMsg.__constants['MOTOR_DISABLE']

    @property
    def MOTOR_ENABLE(self):
        """Message constant 'MOTOR_ENABLE'."""
        return Metaclass_RobotControlMsg.__constants['MOTOR_ENABLE']

    @property
    def CURRENT_MODE(self):
        """Message constant 'CURRENT_MODE'."""
        return Metaclass_RobotControlMsg.__constants['CURRENT_MODE']

    @property
    def EFFORT_POSITION_MODE(self):
        """Message constant 'EFFORT_POSITION_MODE'."""
        return Metaclass_RobotControlMsg.__constants['EFFORT_POSITION_MODE']

    @property
    def SPEED_MODE(self):
        """Message constant 'SPEED_MODE'."""
        return Metaclass_RobotControlMsg.__constants['SPEED_MODE']

    @property
    def POSITION_ABS_MODE(self):
        """Message constant 'POSITION_ABS_MODE'."""
        return Metaclass_RobotControlMsg.__constants['POSITION_ABS_MODE']

    @property
    def POSITION_INC_MODE(self):
        """Message constant 'POSITION_INC_MODE'."""
        return Metaclass_RobotControlMsg.__constants['POSITION_INC_MODE']


class RobotControlMsg(metaclass=Metaclass_RobotControlMsg):
    """
    Message class 'RobotControlMsg'.

    Constants:
      MOTOR_DISABLE
      MOTOR_ENABLE
      CURRENT_MODE
      EFFORT_POSITION_MODE
      SPEED_MODE
      POSITION_ABS_MODE
      POSITION_INC_MODE
    """

    __slots__ = [
        '_motor_enable_flag',
        '_motor_mode',
        '_position',
        '_velocity',
        '_effort',
        '_kp',
        '_kd',
    ]

    _fields_and_field_types = {
        'motor_enable_flag': 'sequence<uint8>',
        'motor_mode': 'sequence<uint8>',
        'position': 'sequence<double>',
        'velocity': 'sequence<double>',
        'effort': 'sequence<double>',
        'kp': 'sequence<uint8>',
        'kd': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.motor_enable_flag = array.array('B', kwargs.get('motor_enable_flag', []))
        self.motor_mode = array.array('B', kwargs.get('motor_mode', []))
        self.position = array.array('d', kwargs.get('position', []))
        self.velocity = array.array('d', kwargs.get('velocity', []))
        self.effort = array.array('d', kwargs.get('effort', []))
        self.kp = array.array('B', kwargs.get('kp', []))
        self.kd = array.array('B', kwargs.get('kd', []))

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
        if self.motor_mode != other.motor_mode:
            return False
        if self.position != other.position:
            return False
        if self.velocity != other.velocity:
            return False
        if self.effort != other.effort:
            return False
        if self.kp != other.kp:
            return False
        if self.kd != other.kd:
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
    def motor_mode(self):
        """Message field 'motor_mode'."""
        return self._motor_mode

    @motor_mode.setter
    def motor_mode(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'motor_mode' array.array() must have the type code of 'B'"
            self._motor_mode = value
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
                "The 'motor_mode' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._motor_mode = array.array('B', value)

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'position' array.array() must have the type code of 'd'"
            self._position = value
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
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'position' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._position = array.array('d', value)

    @builtins.property
    def velocity(self):
        """Message field 'velocity'."""
        return self._velocity

    @velocity.setter
    def velocity(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'velocity' array.array() must have the type code of 'd'"
            self._velocity = value
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
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'velocity' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._velocity = array.array('d', value)

    @builtins.property
    def effort(self):
        """Message field 'effort'."""
        return self._effort

    @effort.setter
    def effort(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'effort' array.array() must have the type code of 'd'"
            self._effort = value
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
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'effort' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._effort = array.array('d', value)

    @builtins.property
    def kp(self):
        """Message field 'kp'."""
        return self._kp

    @kp.setter
    def kp(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'kp' array.array() must have the type code of 'B'"
            self._kp = value
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
                "The 'kp' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._kp = array.array('B', value)

    @builtins.property
    def kd(self):
        """Message field 'kd'."""
        return self._kd

    @kd.setter
    def kd(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'kd' array.array() must have the type code of 'B'"
            self._kd = value
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
                "The 'kd' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._kd = array.array('B', value)
