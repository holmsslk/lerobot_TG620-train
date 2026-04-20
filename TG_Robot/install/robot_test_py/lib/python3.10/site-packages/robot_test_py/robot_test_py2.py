import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
from std_msgs.msg import Bool
from rclpy.qos import QoSProfile, qos_profile_system_default
import sys

class RobotArmCmd(Node):
    def __init__(self):
        super().__init__('robot_arm_cmd')
        # 声明参数
        self.declare_parameter('answer_value', 1)
        # 获取参数值
        self.answer_value = self.get_parameter('answer_value').get_parameter_value().integer_value
        # 创建发布者
        self.publisher_ = self.create_publisher(Int32, 'answer_reply', 10)
        self.timer_ = self.create_timer(1.0, self.timer_callback)
        self.subscription_ = self.create_subscription(Int32, 'nod_begin_flag', self.listener_callback, 10)
        self.subscription_plan_result_ = self.create_subscription(Bool, "plan_state", self.listener_plan_state_callback, 10)
        self.subscription_


    def timer_callback(self):
        msg = Int32()
        msg.data = self.answer_value
        self.publisher_.publish(msg)
        self.get_logger().info('Published answer: %d' % msg.data)

    def listener_callback(self, msg):
        if msg.data == 1:
            self.timer_.cancel()
            assert 0
            self.destroy_node()
            rclpy.shutdown()

    def listener_plan_state_callback(self, msg):
        print("#######################################")
        if msg.data == True:
            assert 0
            self.destroy_node()
            rclpy.shutdown()


# class RobotArmCmd_planB(Node):
#     def __init__(self, args):
#         super().__init__('robot_arm_cmd_planb')
#         # 声明参数
#         # 获取参数值
#         # 创建发布者

#         self.resolve_args(args)
#         self.timer_ = self.create_timer(1.0, self.timer_callback)
#         self.subscription_plan_result_ = self.create_subscription(Bool, "plan_state", self.listener_plan_state_callback, 10)
#         self.subscription_plan_result_
#         self.subscription_ = self.create_subscription(Int32, 'nod_begin_flag', self.listener_callback, 10)
#         self.subscription_
    
#     def resolve_args(self, str_list):
#         self.cmd_mode = str_list[0].split('=')[-1]
#         self.cmd_data = self.get_cmd_data(str_list[1].split('=')[-1])
#         self.cmd_pos = self.get_cmd_position(str_list[2].split('=')[-1])
#         self.cmd_orientation = self.get_cmd_orientation(str_list[3].split('=')[-1])
        
#     @staticmethod
#     def get_cmd_data(data):
#         x = data.split(',')
#         return [int(tt) for tt in x]
    
#     @staticmethod
#     def get_cmd_position(data):
#         x = data.split(',')
#         position = {'x': float(x[0]), 'y': float(x[1]), 'z': float(x[2])}
#         return position
    
#     @staticmethod
#     def get_cmd_orientation(data):
#         x = data.split(',')
#         orientation = {'x': float(x[0]), 'y': float(x[1]), 'z': float(x[2]), 'w': float(x[3])}
#         return orientation
    
#     def timer_callback(self):

#         mode = 9           # working_mode 的值
#         data = [0, 25, 52, 0, 84, 0]  # data 的值
#         position = {"x": 0.5, "y": 0.2, "z": 0.3}  # position 的值
#         orientation = {"x": 0.0, "y": 0.0, "z": 0.0, "w": 1.0}  # orientation 的值

#         mode = self.cmd_mode           # working_mode 的值
#         data = self.cmd_data  # data 的值
#         position = self.cmd_pos  # position 的值
#         orientation = self.cmd_orientation  # orientation 的值
#         # 使用 f-string 动态生成字符串
#         x = f"""{{working_mode: {mode}, joint_angles_goal: {{layout: {{dim: [{{label: '', size: 6, stride: 6}}], data_offset: 0}}, data: {data}}}, arm_pose_goal: {{position: {position}, orientation: {orientation}}}}}"""

#         # 打印结果
#         print(x)


#         lets = 'cd /home/orin/Projects/orz_robot && source install/setup.bash &&  ros2 topic pub /qt_cmd robot_interfaces/msg/QtRecv "{}"'.format(x)

#         cmd = [
#             'bash', '-c',
#             lets
#             ]
#         import subprocess
#         subprocess.run(cmd, check=False)

#     def listener_plan_state_callback(self, msg):
#         print("#########################c##############")
#         if msg.data == True:
#             print("True received")
#             self.timer_.cancel()
#             assert 0
#             self.destroy_node()
#             rclpy.shutdown()
    
#     def listener_callback(self, msg):
#         print("##1111111111111111111111111111111111111111111111###")
        
#         if msg.data == 1:
#             self.timer_.cancel()
#             assert 0
#             self.destroy_node()
#             rclpy.shutdown()
            
                     
def main(args=None):
    # breakpoint()
    rclpy.init(args=args)
    node = RobotArmCmd()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
        

if __name__ == '__main__':
    # ros2 run robot_test_py robot_test_py --ros-args -p answer_value:=3 move=4 mode=9 data=0,25,52,0,84,0 pos=0.5,0.2,0.3 orien=0.0,0.0,0.0,1.0
    main()
