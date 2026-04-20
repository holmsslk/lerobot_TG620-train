#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__srv__SdkRecv_Request() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__srv__SdkRecv_Request__init(msg: *mut SdkRecv_Request) -> bool;
    fn robot_interfaces__srv__SdkRecv_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SdkRecv_Request>, size: usize) -> bool;
    fn robot_interfaces__srv__SdkRecv_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SdkRecv_Request>);
    fn robot_interfaces__srv__SdkRecv_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SdkRecv_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SdkRecv_Request>) -> bool;
}

// Corresponds to robot_interfaces__srv__SdkRecv_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SdkRecv_Request {
    /// 机械臂工作模式
    pub working_mode: u8,

    /// 夹爪目标状态
    pub gripper_goal: std_msgs::msg::rmw::Float64MultiArray,

    /// 关节目标位置
    pub joint_angles_goal: std_msgs::msg::rmw::Float64MultiArray,

    /// 机械臂目标姿态
    pub arm_pose_goal: std_msgs::msg::rmw::Float64MultiArray,

    /// 夹爪原生数据
    pub gripper_data: rosidl_runtime_rs::Sequence<u8>,

    /// 夹爪类型
    pub gripper_type: u8,

    /// 关节序号
    pub joint_idx: u8,

    /// 转动方向
    pub vel_dir: u8,

    /// 用户配置参数
    pub usr_param: super::super::msg::rmw::GenericMotorParameter,

    /// 速度配置
    pub motion_config: std_msgs::msg::rmw::Float64MultiArray,

}



impl Default for SdkRecv_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__srv__SdkRecv_Request__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__srv__SdkRecv_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SdkRecv_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__SdkRecv_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__SdkRecv_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__SdkRecv_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SdkRecv_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SdkRecv_Request where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/srv/SdkRecv_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__srv__SdkRecv_Request() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__srv__SdkRecv_Response() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__srv__SdkRecv_Response__init(msg: *mut SdkRecv_Response) -> bool;
    fn robot_interfaces__srv__SdkRecv_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SdkRecv_Response>, size: usize) -> bool;
    fn robot_interfaces__srv__SdkRecv_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SdkRecv_Response>);
    fn robot_interfaces__srv__SdkRecv_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SdkRecv_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SdkRecv_Response>) -> bool;
}

// Corresponds to robot_interfaces__srv__SdkRecv_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SdkRecv_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

    /// 关节目标位置
    pub cur_joint_angles: std_msgs::msg::rmw::Float64MultiArray,

    /// 当前位姿
    pub cur_pos: std_msgs::msg::rmw::Float64MultiArray,

}



impl Default for SdkRecv_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__srv__SdkRecv_Response__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__srv__SdkRecv_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SdkRecv_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__SdkRecv_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__SdkRecv_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__SdkRecv_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SdkRecv_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SdkRecv_Response where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/srv/SdkRecv_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__srv__SdkRecv_Response() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__srv__ComputeGravity_Request() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__srv__ComputeGravity_Request__init(msg: *mut ComputeGravity_Request) -> bool;
    fn robot_interfaces__srv__ComputeGravity_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComputeGravity_Request>, size: usize) -> bool;
    fn robot_interfaces__srv__ComputeGravity_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComputeGravity_Request>);
    fn robot_interfaces__srv__ComputeGravity_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComputeGravity_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ComputeGravity_Request>) -> bool;
}

// Corresponds to robot_interfaces__srv__ComputeGravity_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComputeGravity_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_trajectory: rosidl_runtime_rs::Sequence<sensor_msgs::msg::rmw::JointState>,

}



impl Default for ComputeGravity_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__srv__ComputeGravity_Request__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__srv__ComputeGravity_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComputeGravity_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__ComputeGravity_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__ComputeGravity_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__ComputeGravity_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComputeGravity_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComputeGravity_Request where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/srv/ComputeGravity_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__srv__ComputeGravity_Request() }
  }
}


#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__srv__ComputeGravity_Response() -> *const std::ffi::c_void;
}

#[link(name = "robot_interfaces__rosidl_generator_c")]
extern "C" {
    fn robot_interfaces__srv__ComputeGravity_Response__init(msg: *mut ComputeGravity_Response) -> bool;
    fn robot_interfaces__srv__ComputeGravity_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ComputeGravity_Response>, size: usize) -> bool;
    fn robot_interfaces__srv__ComputeGravity_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ComputeGravity_Response>);
    fn robot_interfaces__srv__ComputeGravity_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ComputeGravity_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ComputeGravity_Response>) -> bool;
}

// Corresponds to robot_interfaces__srv__ComputeGravity_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComputeGravity_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub efforts: rosidl_runtime_rs::Sequence<sensor_msgs::msg::rmw::JointState>,

}



impl Default for ComputeGravity_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_interfaces__srv__ComputeGravity_Response__init(&mut msg as *mut _) {
        panic!("Call to robot_interfaces__srv__ComputeGravity_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ComputeGravity_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__ComputeGravity_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__ComputeGravity_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_interfaces__srv__ComputeGravity_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ComputeGravity_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ComputeGravity_Response where Self: Sized {
  const TYPE_NAME: &'static str = "robot_interfaces/srv/ComputeGravity_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_interfaces__srv__ComputeGravity_Response() }
  }
}






#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__robot_interfaces__srv__SdkRecv() -> *const std::ffi::c_void;
}

// Corresponds to robot_interfaces__srv__SdkRecv
#[allow(missing_docs, non_camel_case_types)]
pub struct SdkRecv;

impl rosidl_runtime_rs::Service for SdkRecv {
    type Request = SdkRecv_Request;
    type Response = SdkRecv_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__robot_interfaces__srv__SdkRecv() }
    }
}




#[link(name = "robot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__robot_interfaces__srv__ComputeGravity() -> *const std::ffi::c_void;
}

// Corresponds to robot_interfaces__srv__ComputeGravity
#[allow(missing_docs, non_camel_case_types)]
pub struct ComputeGravity;

impl rosidl_runtime_rs::Service for ComputeGravity {
    type Request = ComputeGravity_Request;
    type Response = ComputeGravity_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__robot_interfaces__srv__ComputeGravity() }
    }
}


