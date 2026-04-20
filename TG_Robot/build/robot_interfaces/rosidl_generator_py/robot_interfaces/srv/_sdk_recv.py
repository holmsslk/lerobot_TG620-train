# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:srv/SdkRecv.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'gripper_data'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SdkRecv_Request(type):
    """Metaclass of message 'SdkRecv_Request'."""

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
                'robot_interfaces.srv.SdkRecv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__sdk_recv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__sdk_recv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__sdk_recv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__sdk_recv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__sdk_recv__request

            from robot_interfaces.msg import GenericMotorParameter
            if GenericMotorParameter.__class__._TYPE_SUPPORT is None:
                GenericMotorParameter.__class__.__import_type_support__()

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


class SdkRecv_Request(metaclass=Metaclass_SdkRecv_Request):
    """Message class 'SdkRecv_Request'."""

    __slots__ = [
        '_working_mode',
        '_gripper_goal',
        '_joint_angles_goal',
        '_arm_pose_goal',
        '_gripper_data',
        '_gripper_type',
        '_joint_idx',
        '_vel_dir',
        '_usr_param',
        '_motion_config',
    ]

    _fields_and_field_types = {
        'working_mode': 'uint8',
        'gripper_goal': 'std_msgs/Float64MultiArray',
        'joint_angles_goal': 'std_msgs/Float64MultiArray',
        'arm_pose_goal': 'std_msgs/Float64MultiArray',
        'gripper_data': 'sequence<uint8>',
        'gripper_type': 'uint8',
        'joint_idx': 'uint8',
        'vel_dir': 'uint8',
        'usr_param': 'robot_interfaces/GenericMotorParameter',
        'motion_config': 'std_msgs/Float64MultiArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['robot_interfaces', 'msg'], 'GenericMotorParameter'),  # noqa: E501
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
        self.gripper_data = array.array('B', kwargs.get('gripper_data', []))
        self.gripper_type = kwargs.get('gripper_type', int())
        self.joint_idx = kwargs.get('joint_idx', int())
        self.vel_dir = kwargs.get('vel_dir', int())
        from robot_interfaces.msg import GenericMotorParameter
        self.usr_param = kwargs.get('usr_param', GenericMotorParameter())
        from std_msgs.msg import Float64MultiArray
        self.motion_config = kwargs.get('motion_config', Float64MultiArray())

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
        if self.gripper_data != other.gripper_data:
            return False
        if self.gripper_type != other.gripper_type:
            return False
        if self.joint_idx != other.joint_idx:
            return False
        if self.vel_dir != other.vel_dir:
            return False
        if self.usr_param != other.usr_param:
            return False
        if self.motion_config != other.motion_config:
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

    @builtins.property
    def gripper_data(self):
        """Message field 'gripper_data'."""
        return self._gripper_data

    @gripper_data.setter
    def gripper_data(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'gripper_data' array.array() must have the type code of 'B'"
            self._gripper_data = value
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
                "The 'gripper_data' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._gripper_data = array.array('B', value)

    @builtins.property
    def gripper_type(self):
        """Message field 'gripper_type'."""
        return self._gripper_type

    @gripper_type.setter
    def gripper_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gripper_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gripper_type' field must be an unsigned integer in [0, 255]"
        self._gripper_type = value

    @builtins.property
    def joint_idx(self):
        """Message field 'joint_idx'."""
        return self._joint_idx

    @joint_idx.setter
    def joint_idx(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'joint_idx' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'joint_idx' field must be an unsigned integer in [0, 255]"
        self._joint_idx = value

    @builtins.property
    def vel_dir(self):
        """Message field 'vel_dir'."""
        return self._vel_dir

    @vel_dir.setter
    def vel_dir(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel_dir' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'vel_dir' field must be an unsigned integer in [0, 255]"
        self._vel_dir = value

    @builtins.property
    def usr_param(self):
        """Message field 'usr_param'."""
        return self._usr_param

    @usr_param.setter
    def usr_param(self, value):
        if __debug__:
            from robot_interfaces.msg import GenericMotorParameter
            assert \
                isinstance(value, GenericMotorParameter), \
                "The 'usr_param' field must be a sub message of type 'GenericMotorParameter'"
        self._usr_param = value

    @builtins.property
    def motion_config(self):
        """Message field 'motion_config'."""
        return self._motion_config

    @motion_config.setter
    def motion_config(self, value):
        if __debug__:
            from std_msgs.msg import Float64MultiArray
            assert \
                isinstance(value, Float64MultiArray), \
                "The 'motion_config' field must be a sub message of type 'Float64MultiArray'"
        self._motion_config = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SdkRecv_Response(type):
    """Metaclass of message 'SdkRecv_Response'."""

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
                'robot_interfaces.srv.SdkRecv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__sdk_recv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__sdk_recv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__sdk_recv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__sdk_recv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__sdk_recv__response

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


class SdkRecv_Response(metaclass=Metaclass_SdkRecv_Response):
    """Message class 'SdkRecv_Response'."""

    __slots__ = [
        '_success',
        '_cur_joint_angles',
        '_cur_pos',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'cur_joint_angles': 'std_msgs/Float64MultiArray',
        'cur_pos': 'std_msgs/Float64MultiArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        from std_msgs.msg import Float64MultiArray
        self.cur_joint_angles = kwargs.get('cur_joint_angles', Float64MultiArray())
        from std_msgs.msg import Float64MultiArray
        self.cur_pos = kwargs.get('cur_pos', Float64MultiArray())

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
        if self.success != other.success:
            return False
        if self.cur_joint_angles != other.cur_joint_angles:
            return False
        if self.cur_pos != other.cur_pos:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def cur_joint_angles(self):
        """Message field 'cur_joint_angles'."""
        return self._cur_joint_angles

    @cur_joint_angles.setter
    def cur_joint_angles(self, value):
        if __debug__:
            from std_msgs.msg import Float64MultiArray
            assert \
                isinstance(value, Float64MultiArray), \
                "The 'cur_joint_angles' field must be a sub message of type 'Float64MultiArray'"
        self._cur_joint_angles = value

    @builtins.property
    def cur_pos(self):
        """Message field 'cur_pos'."""
        return self._cur_pos

    @cur_pos.setter
    def cur_pos(self, value):
        if __debug__:
            from std_msgs.msg import Float64MultiArray
            assert \
                isinstance(value, Float64MultiArray), \
                "The 'cur_pos' field must be a sub message of type 'Float64MultiArray'"
        self._cur_pos = value


class Metaclass_SdkRecv(type):
    """Metaclass of service 'SdkRecv'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.srv.SdkRecv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__sdk_recv

            from robot_interfaces.srv import _sdk_recv
            if _sdk_recv.Metaclass_SdkRecv_Request._TYPE_SUPPORT is None:
                _sdk_recv.Metaclass_SdkRecv_Request.__import_type_support__()
            if _sdk_recv.Metaclass_SdkRecv_Response._TYPE_SUPPORT is None:
                _sdk_recv.Metaclass_SdkRecv_Response.__import_type_support__()


class SdkRecv(metaclass=Metaclass_SdkRecv):
    from robot_interfaces.srv._sdk_recv import SdkRecv_Request as Request
    from robot_interfaces.srv._sdk_recv import SdkRecv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
