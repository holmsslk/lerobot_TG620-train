# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:msg/LineMsg.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LineMsg(type):
    """Metaclass of message 'LineMsg'."""

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
                'robot_interfaces.msg.LineMsg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__line_msg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__line_msg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__line_msg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__line_msg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__line_msg

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LineMsg(metaclass=Metaclass_LineMsg):
    """Message class 'LineMsg'."""

    __slots__ = [
        '_type',
        '_initial_pose',
        '_delta_x',
        '_delta_y',
        '_delta_z',
        '_radius',
    ]

    _fields_and_field_types = {
        'type': 'uint8',
        'initial_pose': 'geometry_msgs/Pose',
        'delta_x': 'float',
        'delta_y': 'float',
        'delta_z': 'float',
        'radius': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.type = kwargs.get('type', int())
        from geometry_msgs.msg import Pose
        self.initial_pose = kwargs.get('initial_pose', Pose())
        self.delta_x = kwargs.get('delta_x', float())
        self.delta_y = kwargs.get('delta_y', float())
        self.delta_z = kwargs.get('delta_z', float())
        self.radius = kwargs.get('radius', float())

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
        if self.type != other.type:
            return False
        if self.initial_pose != other.initial_pose:
            return False
        if self.delta_x != other.delta_x:
            return False
        if self.delta_y != other.delta_y:
            return False
        if self.delta_z != other.delta_z:
            return False
        if self.radius != other.radius:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'type' field must be an unsigned integer in [0, 255]"
        self._type = value

    @builtins.property
    def initial_pose(self):
        """Message field 'initial_pose'."""
        return self._initial_pose

    @initial_pose.setter
    def initial_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'initial_pose' field must be a sub message of type 'Pose'"
        self._initial_pose = value

    @builtins.property
    def delta_x(self):
        """Message field 'delta_x'."""
        return self._delta_x

    @delta_x.setter
    def delta_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delta_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'delta_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._delta_x = value

    @builtins.property
    def delta_y(self):
        """Message field 'delta_y'."""
        return self._delta_y

    @delta_y.setter
    def delta_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delta_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'delta_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._delta_y = value

    @builtins.property
    def delta_z(self):
        """Message field 'delta_z'."""
        return self._delta_z

    @delta_z.setter
    def delta_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delta_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'delta_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._delta_z = value

    @builtins.property
    def radius(self):
        """Message field 'radius'."""
        return self._radius

    @radius.setter
    def radius(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'radius' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'radius' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._radius = value
