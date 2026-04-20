# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:msg/StateAction.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_StateAction(type):
    """Metaclass of message 'StateAction'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'SAVE': 0,
        'DELETE': 1,
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
                'robot_interfaces.msg.StateAction')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__state_action
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__state_action
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__state_action
            cls._TYPE_SUPPORT = module.type_support_msg__msg__state_action
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__state_action

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'SAVE': cls.__constants['SAVE'],
            'DELETE': cls.__constants['DELETE'],
        }

    @property
    def SAVE(self):
        """Message constant 'SAVE'."""
        return Metaclass_StateAction.__constants['SAVE']

    @property
    def DELETE(self):
        """Message constant 'DELETE'."""
        return Metaclass_StateAction.__constants['DELETE']


class StateAction(metaclass=Metaclass_StateAction):
    """
    Message class 'StateAction'.

    Constants:
      SAVE
      DELETE
    """

    __slots__ = [
        '_state_name',
        '_operation_mode',
    ]

    _fields_and_field_types = {
        'state_name': 'string',
        'operation_mode': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.state_name = kwargs.get('state_name', str())
        self.operation_mode = kwargs.get('operation_mode', int())

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
        if self.state_name != other.state_name:
            return False
        if self.operation_mode != other.operation_mode:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def state_name(self):
        """Message field 'state_name'."""
        return self._state_name

    @state_name.setter
    def state_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'state_name' field must be of type 'str'"
        self._state_name = value

    @builtins.property
    def operation_mode(self):
        """Message field 'operation_mode'."""
        return self._operation_mode

    @operation_mode.setter
    def operation_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'operation_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'operation_mode' field must be an unsigned integer in [0, 255]"
        self._operation_mode = value
