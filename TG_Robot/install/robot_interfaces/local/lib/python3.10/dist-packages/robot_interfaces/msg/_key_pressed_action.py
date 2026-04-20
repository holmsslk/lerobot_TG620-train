# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:msg/KeyPressedAction.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_KeyPressedAction(type):
    """Metaclass of message 'KeyPressedAction'."""

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
                'robot_interfaces.msg.KeyPressedAction')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__key_pressed_action
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__key_pressed_action
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__key_pressed_action
            cls._TYPE_SUPPORT = module.type_support_msg__msg__key_pressed_action
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__key_pressed_action

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class KeyPressedAction(metaclass=Metaclass_KeyPressedAction):
    """Message class 'KeyPressedAction'."""

    __slots__ = [
        '_key_code',
        '_is_pressed',
    ]

    _fields_and_field_types = {
        'key_code': 'uint8',
        'is_pressed': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.key_code = kwargs.get('key_code', int())
        self.is_pressed = kwargs.get('is_pressed', bool())

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
        if self.key_code != other.key_code:
            return False
        if self.is_pressed != other.is_pressed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def key_code(self):
        """Message field 'key_code'."""
        return self._key_code

    @key_code.setter
    def key_code(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'key_code' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'key_code' field must be an unsigned integer in [0, 255]"
        self._key_code = value

    @builtins.property
    def is_pressed(self):
        """Message field 'is_pressed'."""
        return self._is_pressed

    @is_pressed.setter
    def is_pressed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_pressed' field must be of type 'bool'"
        self._is_pressed = value
