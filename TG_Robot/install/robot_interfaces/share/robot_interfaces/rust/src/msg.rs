#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to robot_interfaces__msg__QtRecv

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct QtRecv {
    /// 机械臂工作模式
    pub working_mode: u8,

    /// 夹爪目标状态
    pub gripper_goal: std_msgs::msg::Float64MultiArray,

    /// 关节目标位置
    pub joint_angles_goal: std_msgs::msg::Float64MultiArray,

    /// 机械臂目标姿态
    pub arm_pose_goal: std_msgs::msg::Float64MultiArray,

}



impl Default for QtRecv {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::QtRecv::default())
  }
}

impl rosidl_runtime_rs::Message for QtRecv {
  type RmwMsg = super::msg::rmw::QtRecv;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        working_mode: msg.working_mode,
        gripper_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.gripper_goal)).into_owned(),
        joint_angles_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.joint_angles_goal)).into_owned(),
        arm_pose_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.arm_pose_goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      working_mode: msg.working_mode,
        gripper_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.gripper_goal)).into_owned(),
        joint_angles_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.joint_angles_goal)).into_owned(),
        arm_pose_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.arm_pose_goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      working_mode: msg.working_mode,
      gripper_goal: std_msgs::msg::Float64MultiArray::from_rmw_message(msg.gripper_goal),
      joint_angles_goal: std_msgs::msg::Float64MultiArray::from_rmw_message(msg.joint_angles_goal),
      arm_pose_goal: std_msgs::msg::Float64MultiArray::from_rmw_message(msg.arm_pose_goal),
    }
  }
}


// Corresponds to robot_interfaces__msg__LineMsg

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LineMsg {
    /// 0: line 1: circle
    pub type_: u8,

    /// 0: start line pose  1: start center pose
    pub initial_pose: geometry_msgs::msg::Pose,

    /// delta position with respect to the initial_pose
    pub delta_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub delta_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub delta_z: f32,

    /// 0: without any meaning  1: radius of the circle
    pub radius: f32,

}



impl Default for LineMsg {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::LineMsg::default())
  }
}

impl rosidl_runtime_rs::Message for LineMsg {
  type RmwMsg = super::msg::rmw::LineMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_: msg.type_,
        initial_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.initial_pose)).into_owned(),
        delta_x: msg.delta_x,
        delta_y: msg.delta_y,
        delta_z: msg.delta_z,
        radius: msg.radius,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      type_: msg.type_,
        initial_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.initial_pose)).into_owned(),
      delta_x: msg.delta_x,
      delta_y: msg.delta_y,
      delta_z: msg.delta_z,
      radius: msg.radius,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_: msg.type_,
      initial_pose: geometry_msgs::msg::Pose::from_rmw_message(msg.initial_pose),
      delta_x: msg.delta_x,
      delta_y: msg.delta_y,
      delta_z: msg.delta_z,
      radius: msg.radius,
    }
  }
}


// Corresponds to robot_interfaces__msg__ArmState
/// geometry_msgs/Quaternion end_effector_quat

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArmState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub end_effector_pose: geometry_msgs::msg::Pose,

}



impl Default for ArmState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ArmState::default())
  }
}

impl rosidl_runtime_rs::Message for ArmState {
  type RmwMsg = super::msg::rmw::ArmState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        end_effector_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.end_effector_pose)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        end_effector_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.end_effector_pose)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      end_effector_pose: geometry_msgs::msg::Pose::from_rmw_message(msg.end_effector_pose),
    }
  }
}


// Corresponds to robot_interfaces__msg__QtPub

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct QtPub {
    /// 机械臂工作模式
    pub working_mode: u8,

    /// enable or not
    pub enable_flag: bool,

    /// ---------------- Joint Space Planning ----------------
    /// 机械臂目标关节位置
    pub joint_group_positions: Vec<f64>,

    /// 夹爪信息
    pub gripper_msgs: Vec<u8>,

}



impl Default for QtPub {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::QtPub::default())
  }
}

impl rosidl_runtime_rs::Message for QtPub {
  type RmwMsg = super::msg::rmw::QtPub;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        working_mode: msg.working_mode,
        enable_flag: msg.enable_flag,
        joint_group_positions: msg.joint_group_positions.into(),
        gripper_msgs: msg.gripper_msgs.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      working_mode: msg.working_mode,
      enable_flag: msg.enable_flag,
        joint_group_positions: msg.joint_group_positions.as_slice().into(),
        gripper_msgs: msg.gripper_msgs.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      working_mode: msg.working_mode,
      enable_flag: msg.enable_flag,
      joint_group_positions: msg.joint_group_positions
          .into_iter()
          .collect(),
      gripper_msgs: msg.gripper_msgs
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to robot_interfaces__msg__MotorFdb

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MotorFdb {

    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_enable_flag: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_fdb_mode: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_angle_fdb: Vec<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_effort_fdb: Vec<f32>,

}



impl Default for MotorFdb {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MotorFdb::default())
  }
}

impl rosidl_runtime_rs::Message for MotorFdb {
  type RmwMsg = super::msg::rmw::MotorFdb;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        motor_enable_flag: msg.motor_enable_flag.into(),
        motor_fdb_mode: msg.motor_fdb_mode.into(),
        motor_angle_fdb: msg.motor_angle_fdb.into(),
        motor_effort_fdb: msg.motor_effort_fdb.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        motor_enable_flag: msg.motor_enable_flag.as_slice().into(),
        motor_fdb_mode: msg.motor_fdb_mode.as_slice().into(),
        motor_angle_fdb: msg.motor_angle_fdb.as_slice().into(),
        motor_effort_fdb: msg.motor_effort_fdb.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      motor_enable_flag: msg.motor_enable_flag
          .into_iter()
          .collect(),
      motor_fdb_mode: msg.motor_fdb_mode
          .into_iter()
          .collect(),
      motor_angle_fdb: msg.motor_angle_fdb
          .into_iter()
          .collect(),
      motor_effort_fdb: msg.motor_effort_fdb
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to robot_interfaces__msg__RobotControlMsg

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotControlMsg {
    /// 0-disable  1-enable
    pub motor_enable_flag: Vec<u8>,

    /// 04-velocity   05-position   02-effort
    pub motor_mode: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub effort: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub kp: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub kd: Vec<u8>,

}

impl RobotControlMsg {
    /// Constants
    pub const MOTOR_DISABLE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MOTOR_ENABLE: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CURRENT_MODE: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const EFFORT_POSITION_MODE: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPEED_MODE: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POSITION_ABS_MODE: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POSITION_INC_MODE: u8 = 6;

}


impl Default for RobotControlMsg {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RobotControlMsg::default())
  }
}

impl rosidl_runtime_rs::Message for RobotControlMsg {
  type RmwMsg = super::msg::rmw::RobotControlMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        motor_enable_flag: msg.motor_enable_flag.into(),
        motor_mode: msg.motor_mode.into(),
        position: msg.position.into(),
        velocity: msg.velocity.into(),
        effort: msg.effort.into(),
        kp: msg.kp.into(),
        kd: msg.kd.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        motor_enable_flag: msg.motor_enable_flag.as_slice().into(),
        motor_mode: msg.motor_mode.as_slice().into(),
        position: msg.position.as_slice().into(),
        velocity: msg.velocity.as_slice().into(),
        effort: msg.effort.as_slice().into(),
        kp: msg.kp.as_slice().into(),
        kd: msg.kd.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      motor_enable_flag: msg.motor_enable_flag
          .into_iter()
          .collect(),
      motor_mode: msg.motor_mode
          .into_iter()
          .collect(),
      position: msg.position
          .into_iter()
          .collect(),
      velocity: msg.velocity
          .into_iter()
          .collect(),
      effort: msg.effort
          .into_iter()
          .collect(),
      kp: msg.kp
          .into_iter()
          .collect(),
      kd: msg.kd
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to robot_interfaces__msg__MoveCAction

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveCAction {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pose_array: std_msgs::msg::Float64MultiArray,


    // This member is not documented.
    #[allow(missing_docs)]
    pub must_pass_through_middle: bool,

}



impl Default for MoveCAction {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MoveCAction::default())
  }
}

impl rosidl_runtime_rs::Message for MoveCAction {
  type RmwMsg = super::msg::rmw::MoveCAction;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pose_array: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.pose_array)).into_owned(),
        must_pass_through_middle: msg.must_pass_through_middle,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pose_array: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose_array)).into_owned(),
      must_pass_through_middle: msg.must_pass_through_middle,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pose_array: std_msgs::msg::Float64MultiArray::from_rmw_message(msg.pose_array),
      must_pass_through_middle: msg.must_pass_through_middle,
    }
  }
}


// Corresponds to robot_interfaces__msg__StateAction

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StateAction {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state_name: std::string::String,

    /// 0: save, 1: delete
    pub operation_mode: u8,

}

impl StateAction {
    /// Constants
    pub const SAVE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DELETE: u8 = 1;

}


impl Default for StateAction {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::StateAction::default())
  }
}

impl rosidl_runtime_rs::Message for StateAction {
  type RmwMsg = super::msg::rmw::StateAction;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state_name: msg.state_name.as_str().into(),
        operation_mode: msg.operation_mode,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state_name: msg.state_name.as_str().into(),
      operation_mode: msg.operation_mode,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      state_name: msg.state_name.to_string(),
      operation_mode: msg.operation_mode,
    }
  }
}


// Corresponds to robot_interfaces__msg__KeyPressedAction

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct KeyPressedAction {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key_code: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_pressed: bool,

}



impl Default for KeyPressedAction {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::KeyPressedAction::default())
  }
}

impl rosidl_runtime_rs::Message for KeyPressedAction {
  type RmwMsg = super::msg::rmw::KeyPressedAction;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key_code: msg.key_code,
        is_pressed: msg.is_pressed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      key_code: msg.key_code,
      is_pressed: msg.is_pressed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      key_code: msg.key_code,
      is_pressed: msg.is_pressed,
    }
  }
}


// Corresponds to robot_interfaces__msg__GenericMotorParameter

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GenericMotorParameter {

    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_id: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub command_type: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float_value: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int_value: i32,

}



impl Default for GenericMotorParameter {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GenericMotorParameter::default())
  }
}

impl rosidl_runtime_rs::Message for GenericMotorParameter {
  type RmwMsg = super::msg::rmw::GenericMotorParameter;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        motor_id: msg.motor_id,
        command_type: msg.command_type,
        float_value: msg.float_value,
        int_value: msg.int_value,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      motor_id: msg.motor_id,
      command_type: msg.command_type,
      float_value: msg.float_value,
      int_value: msg.int_value,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      motor_id: msg.motor_id,
      command_type: msg.command_type,
      float_value: msg.float_value,
      int_value: msg.int_value,
    }
  }
}


// Corresponds to robot_interfaces__msg__GenericMotorOperation

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GenericMotorOperation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_id: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub op_code: u8,

}



impl Default for GenericMotorOperation {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GenericMotorOperation::default())
  }
}

impl rosidl_runtime_rs::Message for GenericMotorOperation {
  type RmwMsg = super::msg::rmw::GenericMotorOperation;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        motor_id: msg.motor_id,
        op_code: msg.op_code,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      motor_id: msg.motor_id,
      op_code: msg.op_code,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      motor_id: msg.motor_id,
      op_code: msg.op_code,
    }
  }
}


// Corresponds to robot_interfaces__msg__GripperControl

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GripperControl {
    /// 0:智元 1：大寰 2：透传
    pub type_: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub effort: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub data: Vec<u8>,

}



impl Default for GripperControl {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GripperControl::default())
  }
}

impl rosidl_runtime_rs::Message for GripperControl {
  type RmwMsg = super::msg::rmw::GripperControl;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_: msg.type_,
        position: msg.position,
        velocity: msg.velocity,
        effort: msg.effort,
        data: msg.data.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      type_: msg.type_,
      position: msg.position,
      velocity: msg.velocity,
      effort: msg.effort,
        data: msg.data.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_: msg.type_,
      position: msg.position,
      velocity: msg.velocity,
      effort: msg.effort,
      data: msg.data
          .into_iter()
          .collect(),
    }
  }
}


