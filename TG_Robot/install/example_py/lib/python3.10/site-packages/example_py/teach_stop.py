import time
import numpy as np

from arm import Arm
import rclpy

def main():
    rclpy.init(args=None)
    self_arm = Arm()
    
    ####################################
    #gripper
    # self_arm.GripperControl(np.array([1,100,40,100]))
    
    #joint_control
    #self_arm.JointCtrlArm([1,1]) #0反转 1正转
    #time.sleep(1)
    #self_arm.JointStop()

    #param_get
    #self_arm.UsrParamGet(4)

    #print
    #self_arm.JOINTPrint()
    
    #disable
    # self_arm.DisableArm()
    # time.sleep(3)
    
    #enable
    # self_arm.EnableArm()
    # time.sleep(3)
    
    #reset
    # self_arm.ResetArm()
    # time.sleep(3)
    
    #movl
    # pose = np.array([-0.2, 0.0, 0.4, 0, 0, 0], dtype=np.float64)  
    # self_arm.MoveWithPoseGoal(pose)

    #gripper_control
    # self_arm.GripperControl(np.array([1,100,40,100]))
    # self_arm.GripperControl(np.array([2] + [0x01, 0x06, 0x01, 0x03, 0x01, 0xF4, 0x78, 0x21], dtype=np.uint8))

    #usr_param_set
    # usr_param =[1, 8, 170] 
    # self_arm.UsrParamSet(usr_param)

    #teach
    self_arm.TeachStop()
    
    ####################################

    rclpy.shutdown()
    
main()
