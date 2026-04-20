import time
import numpy as np

from arm import Arm
import rclpy

def main():
    rclpy.init(args=None)
    self_arm = Arm()
    
    ####################################
    
    #reset
    #self_arm.ResetArm()
    #time.sleep(3)
    
    #disable
    self_arm.DisableArm()
    time.sleep(3)
    
    #joint_control
    # self_arm.JointCtrlArm([4,1]) #0反转 1正转
    # time.sleep(1)
    
    #joint_stop
    # self_arm.JointStop()
    
    #movj  
    # array = np.array([160.78, 32.23, 61.13, 32.51, -87.63, 0], dtype=np.float64)
    # self_arm.MoveWithJointAngle(array)
    
    #movl
    # pose = np.array([-0.2, 0.0, 0.4, 0, 0, 0], dtype=np.float64)  
    # self_arm.MoveWithPoseGoal(pose)
    
    #teach
    # self_arm.Teach()
    
    #teach_stop
    # self_arm.TeachStop()
    
    #teach_repeat
    # self_arm.TeachRepeat()
    
    #gripper
    # self_arm.GripperControl(np.array([1,100.0,40.0,100.0]))
    # self_arm.GripperControl(np.array([2] + [0x01, 0x06, 0x01, 0x03, 0x01, 0xF4, 0x78, 0x21], dtype=np.uint8))

    #zero_pos_set
    #self_arm.ZeroPositionSet()
    #time.sleep(3)

    #back_to_initial
    #self_arm.BackToInitial()

    #usr_param_set
    # usr_param =[1, 8, 170] 
    # self_arm.UsrParamSet(usr_param)

    #param_get
    # self_arm.UsrParamGet(4)

    #print
    #self_arm.JOINTPrint()
    
    #array = np.array([0.3,0.3], dtype=np.float64)
    #self_arm.SetMotionProfile(array) 
    ####################################

    rclpy.shutdown()
    
main()
