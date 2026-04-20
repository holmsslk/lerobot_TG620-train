import time
from enum import IntEnum

import numpy as np

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from robot_interfaces.srv import SdkRecv
from geometry_msgs.msg import Pose
from std_msgs.msg import Int32MultiArray, UInt8MultiArray, MultiArrayLayout, Float64MultiArray

class WorkMode(IntEnum):
    BACKTOSTART             = 0
    DISABLE                 = 1
    JOINTCONTROL            = 2
    CARTESIAN               = 3
    MOVEJ                   = 4
    MOVEL                   = 5
    MOVEC                   = 6
    TEACH                   = 7
    TEACHREPEAT             = 8
    STATEOPERATION          = 9
    LOADSTATE               = 10
    BACKTOINITIAL           = 11
    MOTORZEROPOSITIONSET    = 12
    GRIPPERCONTROL          = 13
    USERPARAMSET            = 14
    USERPARAMGET            = 15
    TEACHSTOP               = 16
    JOINT_PRINT             = 17
    JOINT_STOP              = 18
    SPEED_CONFIG            = 19
    

class Arm(Node):
    def __init__(self):
        super().__init__('arm_qt_cmd')
        self.cli = self.create_client(SdkRecv, '/sdk_cmd', qos_profile=QoSProfile(depth=10))
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service...')
        self.req = SdkRecv.Request()
        self.res = SdkRecv.Response()
        
    def ResetArm(self):
        self.req.working_mode = WorkMode.BACKTOSTART
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
        
    def DisableArm(self):
        self.req.working_mode = WorkMode.DISABLE
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)

    def JointCtrlArm(self,joint_idx: np.ndarray):
        self.req.working_mode = WorkMode.JOINTCONTROL
        self.req.joint_idx = joint_idx[0]
        self.req.vel_dir = joint_idx[1]   
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
 
    def JointStop(self):
        self.req.working_mode = WorkMode.JOINT_STOP 
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)

    def MoveWithJointAngle(self, joint_angles : np.ndarray):
        if joint_angles.size != 6:
            print("joint_angles length invalid")
        self.req.working_mode = WorkMode.MOVEJ
        self.req.joint_angles_goal.data = joint_angles.tolist()
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
        
    def MoveWithPoseGoal(self, pose : np.ndarray):
        if pose.size != 6:
            print("poision command invalid")
        self.req.working_mode = WorkMode.MOVEL
        self.req.arm_pose_goal.data = pose.tolist()
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)

    def Teach(self): 
        self.req.working_mode = WorkMode.TEACH
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)

    def TeachStop(self): 
        self.req.working_mode = WorkMode.TEACHSTOP
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)

    def TeachRepeat(self): 
        self.req.working_mode = WorkMode.TEACHREPEAT
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
        
    def GripperControl(self, gripper_cmd: np.ndarray):
        if gripper_cmd[0] != 2 and gripper_cmd.size != 4:
            print("gripper_cmd length invalid")
            return
        self.req.gripper_type = int(gripper_cmd[0])
        self.req.working_mode = WorkMode.GRIPPERCONTROL
        if gripper_cmd[0] == 2:
           self.req.gripper_data = gripper_cmd[1:].tolist()
        else:
           self.req.gripper_goal.data = gripper_cmd[1:].tolist()

        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)

    def ZeroPositionSet(self): 
        self.req.working_mode = WorkMode.MOTORZEROPOSITIONSET
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)

    def BackToInitial(self): 
        self.req.working_mode = WorkMode.BACKTOINITIAL
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)          
        
    def UsrParamSet(self, param : np.ndarray):
        self.req.working_mode = WorkMode.USERPARAMSET
        self.req.usr_param.motor_id     = param[0]
        self.req.usr_param.command_type = param[1]
        if isinstance(param[2], float):
            self.req.usr_param.float_value = param[2]
            self.req.usr_param.int_value = (int)(param[2])
        elif isinstance(param[2], int):
            self.req.usr_param.int_value = param[2]
            self.req.usr_param.float_value = (float)(param[2])
        else:
            print("不支持的类型")
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
       
    def UsrParamGet(self, joint_idx : np.uint8):
        self.req.working_mode = WorkMode.USERPARAMGET
        self.req.joint_idx = joint_idx
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)

    def SetMotionProfile(self, motion_config : np.ndarray): 
        if  motion_config.size != 2                             : 
            print("config data length invalid")
        self.req.working_mode = WorkMode.SPEED_CONFIG
        self.req.motion_config.data = motion_config.tolist()
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
    def JOINTPrint(self):
        self.req.working_mode = WorkMode.JOINT_PRINT
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
        
        if future.result() is not None:
            response = future.result()
            self.get_logger().info(f"服务调用成功: success = {response.success}")
        
            joint_angles = response.cur_joint_angles.data
            joint_str = ", ".join([f"{x:.3f}" for x in joint_angles])
            self.get_logger().info(f"当前关节角度: [{joint_str}]")
            
            x, y, z, roll, pitch, yaw = response.cur_pos.data[:6]
            self.get_logger().info(
                f'当前位姿 - x: {x:.3f}, y: {y:.3f}, z: {z:.3f}, '
                f'roll: {roll:.3f}, pitch: {pitch:.3f}, yaw: {yaw:.3f}'
            )
        else:
            self.get_logger().error("服务调用失败，future 无结果")          

    def SwitchWorkMode(work_mode : WorkMode):
        pass
