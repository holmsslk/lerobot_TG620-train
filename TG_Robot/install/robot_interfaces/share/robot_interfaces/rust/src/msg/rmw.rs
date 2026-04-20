#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__QtRecv() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__QtRecv__init(msg: *mut QtRecv) -> bool;
    fn robot_interfaces__msg__QtRecv__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<QtRecv>, size: usize) -> bool;
    fn robot_interfaces__msg__QtRecv__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<QtRecv>);
    fn robot_interfaces__msg__QtRecv__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<QtRecv>, out_seq: *mut rosidl_runtime_rs::Sequence<QtRecv>) -> bool;
}

// Corresponds to robot_interfaces__msg__QtRecv
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct QtRecv {
    /// 机械臂工作模式
    pub working_mode: u8,

    /// 夹爪目标状态
    pub gripper_goal: std_msgs::msg::rmw::Float64MultiArray,

    /// 关节目标位置
    pub joint_angles_goal: std_msgs::msg::rmw::Float64MultiArray,

    /// 机械臂目标姿态
    pub arm_pose_goal: std_msgs::msg::rmw::Float64MultiArray,

}



impl Default for QtRecv {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__QtRecv__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__QtRecv__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for QtRecv {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__QtRecv__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__QtRecv__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__QtRecv__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for QtRecv {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for QtRecv where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/QtRecv";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__QtRecv() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__LineMsg() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__LineMsg__init(msg: *mut LineMsg) -> bool;
    fn robot_interfaces__msg__LineMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LineMsg>, size: usize) -> bool;
    fn robot_interfaces__msg__LineMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LineMsg>);
    fn robot_interfaces__msg__LineMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LineMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<LineMsg>) -> bool;
}

// Corresponds to robot_interfaces__msg__LineMsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LineMsg {
    /// 0: line 1: circle
    pub type_: u8,

    /// 0: start line pose  1: start center pose
    pub initial_pose: geometry_msgs::msg::rmw::Pose,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__LineMsg__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__LineMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LineMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__LineMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__LineMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__LineMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LineMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LineMsg where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/LineMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__LineMsg() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__ArmState() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__ArmState__init(msg: *mut ArmState) -> bool;
    fn robot_interfaces__msg__ArmState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ArmState>, size: usize) -> bool;
    fn robot_interfaces__msg__ArmState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ArmState>);
    fn robot_interfaces__msg__ArmState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ArmState>, out_seq: *mut rosidl_runtime_rs::Sequence<ArmState>) -> bool;
}

// Corresponds to robot_interfaces__msg__ArmState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// geometry_msgs/Quaternion end_effector_quat

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArmState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub end_effector_pose: geometry_msgs::msg::rmw::Pose,

}



impl Default for ArmState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__ArmState__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__ArmState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ArmState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__ArmState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__ArmState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__ArmState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ArmState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ArmState where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/ArmState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__ArmState() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__QtPub() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__QtPub__init(msg: *mut QtPub) -> bool;
    fn robot_interfaces__msg__QtPub__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<QtPub>, size: usize) -> bool;
    fn robot_interfaces__msg__QtPub__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<QtPub>);
    fn robot_interfaces__msg__QtPub__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<QtPub>, out_seq: *mut rosidl_runtime_rs::Sequence<QtPub>) -> bool;
}

// Corresponds to robot_interfaces__msg__QtPub
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct QtPub {
    /// 机械臂工作模式
    pub working_mode: u8,

    /// enable or not
    pub enable_flag: bool,

    /// ---------------- Joint Space Planning ----------------
    /// 机械臂目标关节位置
    pub joint_group_positions: rosidl_runtime_rs::Sequence<f64>,

    /// 夹爪信息
    pub gripper_msgs: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for QtPub {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__QtPub__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__QtPub__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for QtPub {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__QtPub__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__QtPub__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__QtPub__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for QtPub {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for QtPub where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/QtPub";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__QtPub() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__MotorFdb() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__MotorFdb__init(msg: *mut MotorFdb) -> bool;
    fn robot_interfaces__msg__MotorFdb__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MotorFdb>, size: usize) -> bool;
    fn robot_interfaces__msg__MotorFdb__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MotorFdb>);
    fn robot_interfaces__msg__MotorFdb__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MotorFdb>, out_seq: *mut rosidl_runtime_rs::Sequence<MotorFdb>) -> bool;
}

// Corresponds to robot_interfaces__msg__MotorFdb
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MotorFdb {

    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_enable_flag: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_fdb_mode: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_angle_fdb: rosidl_runtime_rs::Sequence<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_effort_fdb: rosidl_runtime_rs::Sequence<f32>,

}



impl Default for MotorFdb {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__MotorFdb__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__MotorFdb__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MotorFdb {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__MotorFdb__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__MotorFdb__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__MotorFdb__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MotorFdb {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MotorFdb where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/MotorFdb";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__MotorFdb() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__RobotControlMsg() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__RobotControlMsg__init(msg: *mut RobotControlMsg) -> bool;
    fn robot_interfaces__msg__RobotControlMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotControlMsg>, size: usize) -> bool;
    fn robot_interfaces__msg__RobotControlMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotControlMsg>);
    fn robot_interfaces__msg__RobotControlMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotControlMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotControlMsg>) -> bool;
}

// Corresponds to robot_interfaces__msg__RobotControlMsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotControlMsg {
    /// 0-disable  1-enable
    pub motor_enable_flag: rosidl_runtime_rs::Sequence<u8>,

    /// 04-velocity   05-position   02-effort
    pub motor_mode: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub effort: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub kp: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub kd: rosidl_runtime_rs::Sequence<u8>,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__RobotControlMsg__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__RobotControlMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotControlMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__RobotControlMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__RobotControlMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__RobotControlMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotControlMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotControlMsg where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/RobotControlMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__RobotControlMsg() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__MoveCAction() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__MoveCAction__init(msg: *mut MoveCAction) -> bool;
    fn robot_interfaces__msg__MoveCAction__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveCAction>, size: usize) -> bool;
    fn robot_interfaces__msg__MoveCAction__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveCAction>);
    fn robot_interfaces__msg__MoveCAction__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveCAction>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveCAction>) -> bool;
}

// Corresponds to robot_interfaces__msg__MoveCAction
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveCAction {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pose_array: std_msgs::msg::rmw::Float64MultiArray,


    // This member is not documented.
    #[allow(missing_docs)]
    pub must_pass_through_middle: bool,

}



impl Default for MoveCAction {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__MoveCAction__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__MoveCAction__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveCAction {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__MoveCAction__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__MoveCAction__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__MoveCAction__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveCAction {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveCAction where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/MoveCAction";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__MoveCAction() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__StateAction() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__StateAction__init(msg: *mut StateAction) -> bool;
    fn robot_interfaces__msg__StateAction__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StateAction>, size: usize) -> bool;
    fn robot_interfaces__msg__StateAction__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StateAction>);
    fn robot_interfaces__msg__StateAction__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StateAction>, out_seq: *mut rosidl_runtime_rs::Sequence<StateAction>) -> bool;
}

// Corresponds to robot_interfaces__msg__StateAction
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StateAction {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state_name: rosidl_runtime_rs::String,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__StateAction__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__StateAction__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StateAction {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__StateAction__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__StateAction__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__StateAction__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StateAction {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StateAction where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/StateAction";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__StateAction() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__KeyPressedAction() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__KeyPressedAction__init(msg: *mut KeyPressedAction) -> bool;
    fn robot_interfaces__msg__KeyPressedAction__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<KeyPressedAction>, size: usize) -> bool;
    fn robot_interfaces__msg__KeyPressedAction__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<KeyPressedAction>);
    fn robot_interfaces__msg__KeyPressedAction__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<KeyPressedAction>, out_seq: *mut rosidl_runtime_rs::Sequence<KeyPressedAction>) -> bool;
}

// Corresponds to robot_interfaces__msg__KeyPressedAction
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__KeyPressedAction__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__KeyPressedAction__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for KeyPressedAction {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__KeyPressedAction__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__KeyPressedAction__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__KeyPressedAction__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for KeyPressedAction {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for KeyPressedAction where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/KeyPressedAction";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__KeyPressedAction() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__GenericMotorParameter() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__GenericMotorParameter__init(msg: *mut GenericMotorParameter) -> bool;
    fn robot_interfaces__msg__GenericMotorParameter__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GenericMotorParameter>, size: usize) -> bool;
    fn robot_interfaces__msg__GenericMotorParameter__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GenericMotorParameter>);
    fn robot_interfaces__msg__GenericMotorParameter__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GenericMotorParameter>, out_seq: *mut rosidl_runtime_rs::Sequence<GenericMotorParameter>) -> bool;
}

// Corresponds to robot_interfaces__msg__GenericMotorParameter
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__GenericMotorParameter__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__GenericMotorParameter__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GenericMotorParameter {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__GenericMotorParameter__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__GenericMotorParameter__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__GenericMotorParameter__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GenericMotorParameter {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GenericMotorParameter where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/GenericMotorParameter";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__GenericMotorParameter() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__GenericMotorOperation() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__GenericMotorOperation__init(msg: *mut GenericMotorOperation) -> bool;
    fn robot_interfaces__msg__GenericMotorOperation__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GenericMotorOperation>, size: usize) -> bool;
    fn robot_interfaces__msg__GenericMotorOperation__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GenericMotorOperation>);
    fn robot_interfaces__msg__GenericMotorOperation__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GenericMotorOperation>, out_seq: *mut rosidl_runtime_rs::Sequence<GenericMotorOperation>) -> bool;
}

// Corresponds to robot_interfaces__msg__GenericMotorOperation
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__GenericMotorOperation__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__GenericMotorOperation__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GenericMotorOperation {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__GenericMotorOperation__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__GenericMotorOperation__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__GenericMotorOperation__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GenericMotorOperation {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GenericMotorOperation where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/GenericMotorOperation";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__GenericMotorOperation() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__GripperControl() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__msg__GripperControl__init(msg: *mut GripperControl) -> bool;
    fn robot_interfaces__msg__GripperControl__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GripperControl>, size: usize) -> bool;
    fn robot_interfaces__msg__GripperControl__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GripperControl>);
    fn robot_interfaces__msg__GripperControl__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GripperControl>, out_seq: *mut rosidl_runtime_rs::Sequence<GripperControl>) -> bool;
}

// Corresponds to robot_interfaces__msg__GripperControl
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    pub data: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for GripperControl {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__msg__GripperControl__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__msg__GripperControl__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GripperControl {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__GripperControl__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__GripperControl__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__msg__GripperControl__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GripperControl {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GripperControl where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/msg/GripperControl";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__msg__GripperControl() }
  }
}


