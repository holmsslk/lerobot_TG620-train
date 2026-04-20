#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to robot_interfaces__srv__SdkRecv_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SdkRecv_Request {
    /// 机械臂工作模式
    pub working_mode: u8,

    /// 夹爪目标状态
    pub gripper_goal: std_msgs::msg::Float64MultiArray,

    /// 关节目标位置
    pub joint_angles_goal: std_msgs::msg::Float64MultiArray,

    /// 机械臂目标姿态
    pub arm_pose_goal: std_msgs::msg::Float64MultiArray,

    /// 夹爪原生数据
    pub gripper_data: Vec<u8>,

    /// 夹爪类型
    pub gripper_type: u8,

    /// 关节序号
    pub joint_idx: u8,

    /// 转动方向
    pub vel_dir: u8,

    /// 用户配置参数
    pub usr_param: super::msg::GenericMotorParameter,

    /// 速度配置
    pub motion_config: std_msgs::msg::Float64MultiArray,

}



impl Default for SdkRecv_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SdkRecv_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SdkRecv_Request {
  type RmwMsg = super::srv::rmw::SdkRecv_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        working_mode: msg.working_mode,
        gripper_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.gripper_goal)).into_owned(),
        joint_angles_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.joint_angles_goal)).into_owned(),
        arm_pose_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.arm_pose_goal)).into_owned(),
        gripper_data: msg.gripper_data.into(),
        gripper_type: msg.gripper_type,
        joint_idx: msg.joint_idx,
        vel_dir: msg.vel_dir,
        usr_param: super::msg::GenericMotorParameter::into_rmw_message(std::borrow::Cow::Owned(msg.usr_param)).into_owned(),
        motion_config: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.motion_config)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      working_mode: msg.working_mode,
        gripper_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.gripper_goal)).into_owned(),
        joint_angles_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.joint_angles_goal)).into_owned(),
        arm_pose_goal: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.arm_pose_goal)).into_owned(),
        gripper_data: msg.gripper_data.as_slice().into(),
      gripper_type: msg.gripper_type,
      joint_idx: msg.joint_idx,
      vel_dir: msg.vel_dir,
        usr_param: super::msg::GenericMotorParameter::into_rmw_message(std::borrow::Cow::Borrowed(&msg.usr_param)).into_owned(),
        motion_config: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.motion_config)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      working_mode: msg.working_mode,
      gripper_goal: std_msgs::msg::Float64MultiArray::from_rmw_message(msg.gripper_goal),
      joint_angles_goal: std_msgs::msg::Float64MultiArray::from_rmw_message(msg.joint_angles_goal),
      arm_pose_goal: std_msgs::msg::Float64MultiArray::from_rmw_message(msg.arm_pose_goal),
      gripper_data: msg.gripper_data
          .into_iter()
          .collect(),
      gripper_type: msg.gripper_type,
      joint_idx: msg.joint_idx,
      vel_dir: msg.vel_dir,
      usr_param: super::msg::GenericMotorParameter::from_rmw_message(msg.usr_param),
      motion_config: std_msgs::msg::Float64MultiArray::from_rmw_message(msg.motion_config),
    }
  }
}


// Corresponds to robot_interfaces__srv__SdkRecv_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SdkRecv_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

    /// 关节目标位置
    pub cur_joint_angles: std_msgs::msg::Float64MultiArray,

    /// 当前位姿
    pub cur_pos: std_msgs::msg::Float64MultiArray,

}



impl Default for SdkRecv_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SdkRecv_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SdkRecv_Response {
  type RmwMsg = super::srv::rmw::SdkRecv_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        cur_joint_angles: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.cur_joint_angles)).into_owned(),
        cur_pos: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.cur_pos)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        cur_joint_angles: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.cur_joint_angles)).into_owned(),
        cur_pos: std_msgs::msg::Float64MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.cur_pos)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      cur_joint_angles: std_msgs::msg::Float64MultiArray::from_rmw_message(msg.cur_joint_angles),
      cur_pos: std_msgs::msg::Float64MultiArray::from_rmw_message(msg.cur_pos),
    }
  }
}


// Corresponds to robot_interfaces__srv__ComputeGravity_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComputeGravity_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_trajectory: Vec<sensor_msgs::msg::JointState>,

}



impl Default for ComputeGravity_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ComputeGravity_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ComputeGravity_Request {
  type RmwMsg = super::srv::rmw::ComputeGravity_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        joint_trajectory: msg.joint_trajectory
          .into_iter()
          .map(|elem| sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        joint_trajectory: msg.joint_trajectory
          .iter()
          .map(|elem| sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      joint_trajectory: msg.joint_trajectory
          .into_iter()
          .map(sensor_msgs::msg::JointState::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to robot_interfaces__srv__ComputeGravity_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComputeGravity_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub efforts: Vec<sensor_msgs::msg::JointState>,

}



impl Default for ComputeGravity_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ComputeGravity_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ComputeGravity_Response {
  type RmwMsg = super::srv::rmw::ComputeGravity_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        efforts: msg.efforts
          .into_iter()
          .map(|elem| sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        efforts: msg.efforts
          .iter()
          .map(|elem| sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      efforts: msg.efforts
          .into_iter()
          .map(sensor_msgs::msg::JointState::from_rmw_message)
          .collect(),
    }
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


