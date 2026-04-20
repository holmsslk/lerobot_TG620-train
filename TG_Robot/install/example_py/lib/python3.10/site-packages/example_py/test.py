import time
import numpy as np

from arm import Arm
import rclpy

def main():
    rclpy.init(args=None)
    self_arm = Arm()
    
    ####################################

    #disable
    array = np.array([0.5,0.5], dtype=np.float64)
    self_arm.SetMotionProfile(array) 
    time.sleep(3)
    #movj
    array = np.array([-29, 73, -82, -30, 43, 32], dtype=np.float64)
    self_arm.MoveWithJointAngle(array)
    time.sleep(4)
    array = np.array([8, -89, 82, 34, -16, -8], dtype=np.float64)
    self_arm.MoveWithJointAngle(array)
    time.sleep(4)
    rclpy.shutdown()
    
main()
