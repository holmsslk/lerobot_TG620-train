import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
from std_msgs.msg import Bool
from std_msgs.msg import Int32MultiArray
from geometry_msgs.msg import Pose
import rcl_interfaces
from rcl_interfaces.msg import SetParametersResult
from rclpy.qos import QoSProfile, qos_profile_system_default
import sys
from robot_interfaces.msg import QtRecv
# ros2 run robot_test_py robot_test_py --ros-args -p working_mode:=9 -p joint_angles_goal.data[0]:=0 -p joint_angles_goal.data[1]:=0 -p joint_angles_goal.data[2]:=0 -p joint_angles_goal.data[3]:=0 -p joint_angles_goal.data[4]:=0 -p joint_angles_goal.data[5]:=0
# -p arm_pose_goal.position.x:=0.0 -p arm_pose_goal.position.y:=0.0 -p arm_pose_goal.position.z:=0.0 
# -p arm_pose_goal.orientation.x:=0.0 -p arm_pose_goal.orientation.y:=0.0 -p arm_pose_goal.orientation.z:=0.0 
# -p arm_pose_goal.orientation.w:=1.0

# ros2 run robot_test_py robot_test_py --ros-args -p working_mode:=9 -p joint_angles_goal.data0:=0 
# -p joint_angles_goal.data1:=0 -p joint_angles_goal.data2:=0 -p joint_angles_goal.data3:=0 
# -p joint_angles_goal.data4:=0 -p joint_angles_goal.data5:=0 -p arm_pose_goal.position.x:=0.0 
# -p arm_pose_goal.position.y:=0.0 -p arm_pose_goal.position.z:=0.0 
# -p arm_pose_goal.orientation.x:=0.0 -p arm_pose_goal.orientation.y:=0.0 
# -p arm_pose_goal.orientation.z:=0.0 -p arm_pose_goal.orientation.w:=1.0
class RobotArmCmd(Node):
    def __init__(self):
        super().__init__('robot_arm_cmd')

        self.declare_parameter('working_mode', 0)

        self.declare_parameter('joint_angles_goal.data0', 0)
        self.declare_parameter('joint_angles_goal.data1', 0)
        self.declare_parameter('joint_angles_goal.data2', 0)
        self.declare_parameter('joint_angles_goal.data3', 0)
        self.declare_parameter('joint_angles_goal.data4', 0)
        self.declare_parameter('joint_angles_goal.data5', 0)

        self.declare_parameter('arm_pose_goal.position.x', 0.0)
        self.declare_parameter('arm_pose_goal.position.y', 0.0)
        self.declare_parameter('arm_pose_goal.position.z', 0.0)
        self.declare_parameter('arm_pose_goal.orientation.x', 0.0)
        self.declare_parameter('arm_pose_goal.orientation.y', 0.0)
        self.declare_parameter('arm_pose_goal.orientation.z', 0.0)
        self.declare_parameter('arm_pose_goal.orientation.w', 1.0)

        self.arm_ctrl_msg = self.get_qtrecv_msg_from_params()

        self.get_logger().info(f"Initial arm ctrl msg: working_mode={self.arm_ctrl_msg.working_mode}")

        self.subscription_ = self.create_subscription(Bool, "plan_state", self.listener_callback, 10)
        self.publisher_ = self.create_publisher(QtRecv, 'qt_cmd', 10)
        self.timer_ = self.create_timer(1.0, self.timer_callback)
        self.subscription_

    def get_qtrecv_msg_from_params(self):
        arm_ctrl_msg = QtRecv()
        arm_ctrl_msg.working_mode = self.get_parameter('working_mode').get_parameter_value().integer_value

        joint_angles = Int32MultiArray()
        joint_angles.data = [0] * 6
        joint_angles.data[0] = self.get_parameter('joint_angles_goal.data0').get_parameter_value().integer_value
        joint_angles.data[1] = self.get_parameter('joint_angles_goal.data1').get_parameter_value().integer_value
        joint_angles.data[2] = self.get_parameter('joint_angles_goal.data2').get_parameter_value().integer_value
        joint_angles.data[3] = self.get_parameter('joint_angles_goal.data3').get_parameter_value().integer_value
        joint_angles.data[4] = self.get_parameter('joint_angles_goal.data4').get_parameter_value().integer_value
        joint_angles.data[5] = self.get_parameter('joint_angles_goal.data5').get_parameter_value().integer_value
        arm_ctrl_msg.joint_angles_goal.data = joint_angles.data
        
        arm_pose = Pose()
        arm_pose.position.x = self.get_parameter('arm_pose_goal.position.x').get_parameter_value().double_value
        arm_pose.position.y = self.get_parameter('arm_pose_goal.position.y').get_parameter_value().double_value
        arm_pose.position.z = self.get_parameter('arm_pose_goal.position.z').get_parameter_value().double_value
        arm_pose.orientation.x = self.get_parameter('arm_pose_goal.orientation.x').get_parameter_value().double_value
        arm_pose.orientation.y = self.get_parameter('arm_pose_goal.orientation.y').get_parameter_value().double_value
        arm_pose.orientation.z = self.get_parameter('arm_pose_goal.orientation.z').get_parameter_value().double_value
        arm_pose.orientation.w = self.get_parameter('arm_pose_goal.orientation.w').get_parameter_value().double_value
        arm_ctrl_msg.arm_pose_goal = arm_pose

        return arm_ctrl_msg

    def timer_callback(self):
        msg = QtRecv()
        msg = self.arm_ctrl_msg
        self.publisher_.publish(msg)
        self.get_logger().info("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")

    # def parameter_callback(self, params):
    #     for param in params:
    #         if param.name.startswith('working_mode') or \
    #             param.name.startswith('joint_angles_goal') or \
    #                 param.name.startswith('arm_pose_goal'):
    #             self.arm_ctrl_msg = self.get_qtrecv_msg_from_params()
    #             self.get_logger().info(f"Update arm ctrl msg: working_mode={self.arm_ctrl_msg.working_mode}, "
    #                            f"joint_angles_goal={self.arm_ctrl_msg.joint_angles_goal},"
    #                            f"arm_pose_goal={self.arm_ctrl_msg.arm_pose_goal}")

    #     return SetParametersResult(successful=True)

    def listener_callback(self, msg):
        self.get_logger().info(msg.data)
        self.timer_.cancel()
        assert 0
        self.destroy_node()
        rclpy.shutdown()

def main(args = None):
    rclpy.init(args=args)
    node = RobotArmCmd()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
