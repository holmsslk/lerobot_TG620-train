# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:msg/QtRecv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_QtRecv(type):
    """Metaclass of message 'QtRecv'."""

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
                'robot_interfaces.msg.QtRecv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__qt_recv
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__qt_recv
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__qt_recv
            cls._TYPE_SUPPORT = module.type_support_msg__msg__qt_recv
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__qt_recv

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


class QtRecv(metaclass=Metaclass_QtRecv):
    """Message class 'QtRecv'."""

    __slots__ = [
        '_working_mode',
        '_gripper_goal',
        '_joint_angles_goal',
        '_arm_pose_goal',
    ]

    _fields_and_field_types = {
        'working_mode': 'uint8',
        'gripper_goal': 'std_msgs/Float64MultiArray',
        'joint_angles_goal': 'std_msgs/Float64MultiArray',
        'arm_pose_goal': 'std_msgs/Float64MultiArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.working_mode = kwargs.get('working_mode', int())
        from std_msgs.msg import Float64MultiArray
        self.gripper_goal = kwargs.get('gripper_goal', Float64MultiArray())
        from std_msgs.msg import Float64MultiArray
        self.joint_angles_goal = kwargs.get('joint_angles_goal', Float64MultiArray())
        from std_msgs.msg import Float64MultiArray
        self.arm_pose_goal = kwargs.get('arm_pose_goal', Float64MultiArray())

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
        if self.working_mode != other.working_mode:
            return False
        if self.gripper_goal != other.gripper_goal:
            return False
        if self.joint_angles_goal != other.joint_angles_goal:
            return False
        if self.arm_pose_goal != other.arm_pose_goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def working_mode(self):
        """Message field 'working_mode'."""
        return self._working_mode

    @working_mode.setter
    def working_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'working_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'working_mode' field must be an unsigned integer in [0, 255]"
        self._working_mode = value

    @builtins.property
    def gripper_goal(self):
        """Message field 'gripper_goal'."""
        return self._gripper_goal

    @gripper_goal.setter
    def gripper_goal(self, value):
        if __debug__:
            from std_msgs.msg import Float64MultiArray
            assert \
                isinstance(value, Float64MultiArray), \
                "The 'gripper_goal' field must be a sub message of type 'Float64MultiArray'"
        self._gripper_goal = value

    @builtins.property
    def joint_angles_goal(self):
        """Message field 'joint_angles_goal'."""
        return self._joint_angles_goal

    @joint_angles_goal.setter
    def joint_angles_goal(self, value):
        if __debug__:
            from std_msgs.msg import Float64MultiArray
            assert \
                isinstance(value, Float64MultiArray), \
                "The 'joint_angles_goal' field must be a sub message of type 'Float64MultiArray'"
        self._joint_angles_goal = value

    @builtins.property
    def arm_pose_goal(self):
        """Message field 'arm_pose_goal'."""
        return self._arm_pose_goal

    @arm_pose_goal.setter
    def arm_pose_goal(self, value):
        if __debug__:
            from std_msgs.msg import Float64MultiArray
            assert \
                isinstance(value, Float64MultiArray), \
                "The 'arm_pose_goal' field must be a sub message of type 'Float64MultiArray'"
        self._arm_pose_goal = value
