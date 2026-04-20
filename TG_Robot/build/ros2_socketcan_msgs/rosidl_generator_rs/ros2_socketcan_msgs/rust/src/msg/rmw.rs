#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "ros2_socketcan_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_socketcan_msgs__msg__FdFrame() -> *const std::ffi::c_void;
}

#[link(name = "ros2_socketcan_msgs__rosidl_generator_c")]
extern "C" {
    fn ros2_socketcan_msgs__msg__FdFrame__init(msg: *mut FdFrame) -> bool;
    fn ros2_socketcan_msgs__msg__FdFrame__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FdFrame>, size: usize) -> bool;
    fn ros2_socketcan_msgs__msg__FdFrame__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FdFrame>);
    fn ros2_socketcan_msgs__msg__FdFrame__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FdFrame>, out_seq: *mut rosidl_runtime_rs::Sequence<FdFrame>) -> bool;
}

// Corresponds to ros2_socketcan_msgs__msg__FdFrame
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FdFrame {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub id: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_extended: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_error: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub len: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub data: rosidl_runtime_rs::BoundedSequence<u8, 64>,

}



impl Default for FdFrame {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_socketcan_msgs__msg__FdFrame__init(&mut msg as *mut _) {
        panic!("Call to ros2_socketcan_msgs__msg__FdFrame__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FdFrame {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_socketcan_msgs__msg__FdFrame__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_socketcan_msgs__msg__FdFrame__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_socketcan_msgs__msg__FdFrame__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FdFrame {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FdFrame where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_socketcan_msgs/msg/FdFrame";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_socketcan_msgs__msg__FdFrame() }
  }
}


