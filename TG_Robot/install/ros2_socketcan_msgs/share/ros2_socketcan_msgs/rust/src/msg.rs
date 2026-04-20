#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to ros2_socketcan_msgs__msg__FdFrame

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FdFrame {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FdFrame::default())
  }
}

impl rosidl_runtime_rs::Message for FdFrame {
  type RmwMsg = super::msg::rmw::FdFrame;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        id: msg.id,
        is_extended: msg.is_extended,
        is_error: msg.is_error,
        len: msg.len,
        data: msg.data,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      id: msg.id,
      is_extended: msg.is_extended,
      is_error: msg.is_error,
      len: msg.len,
        data: msg.data.clone(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      id: msg.id,
      is_extended: msg.is_extended,
      is_error: msg.is_error,
      len: msg.len,
      data: msg.data,
    }
  }
}


