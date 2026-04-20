# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:msg/MoveCAction.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MoveCAction(type):
    """Metaclass of message 'MoveCAction'."""

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
                'robot_interfaces.msg.MoveCAction')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__move_c_action
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__move_c_action
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__move_c_action
            cls._TYPE_SUPPORT = module.type_support_msg__msg__move_c_action
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__move_c_action

            from std_msgs.msg import Float64MultiArray
            if Float64MultiArray.__class__._TYPE_SUPPORT is None:
                Float64MultiArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveCAction(metaclass=Metaclass_MoveCAction):
    """Message class 'MoveCAction'."""

    __slots__ = [
        '_pose_array',
        '_must_pass_through_middle',
    ]

    _fields_and_field_types = {
        'pose_array': 'std_msgs/Float64MultiArray',
        'must_pass_through_middle': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Float64MultiArray
        self.pose_array = kwargs.get('pose_array', Float64MultiArray())
        self.must_pass_through_middle = kwargs.get('must_pass_through_middle', bool())

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
        if self.pose_array != other.pose_array:
            return False
        if self.must_pass_through_middle != other.must_pass_through_middle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pose_array(self):
        """Message field 'pose_array'."""
        return self._pose_array

    @pose_array.setter
    def pose_array(self, value):
        if __debug__:
            from std_msgs.msg import Float64MultiArray
            assert \
                isinstance(value, Float64MultiArray), \
                "The 'pose_array' field must be a sub message of type 'Float64MultiArray'"
        self._pose_array = value

    @builtins.property
    def must_pass_through_middle(self):
        """Message field 'must_pass_through_middle'."""
        return self._must_pass_through_middle

    @must_pass_through_middle.setter
    def must_pass_through_middle(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'must_pass_through_middle' field must be of type 'bool'"
        self._must_pass_through_middle = value
