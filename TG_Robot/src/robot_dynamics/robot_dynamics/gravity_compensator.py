import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import String
from robot_interfaces.srv import ComputeGravity
from std_msgs.msg import Float64MultiArray
import pinocchio as pin
from pinocchio.robot_wrapper import RobotWrapper
from geometry_msgs.msg import Twist

import numpy as np
import os
import tempfile

class GravityCompensator(Node):
    def __init__(self):
        super().__init__('gravity_compensator')

        # === 从参数服务器读取 robot_description（URDF 字符串）===
        self.declare_parameter('robot_description', '')
        urdf_string = self.get_parameter('robot_description').get_parameter_value().string_value
        
        if not urdf_string:
            self.get_logger().error(" 参数 'robot_description' 未设置！")
            return

        try:
            self.model = pin.buildModelFromXML(urdf_string)
            self.data = self.model.createData()
            
            # 获取关节名称
            self.joint_names = [
                name for idx, name in enumerate(self.model.names)
                if idx > 0 and self.model.joints[idx].nq > 0
            ]
            
            self.get_logger().info(f"成功加载模型，关节数量: {len(self.joint_names)}")
            
        except Exception as e:
            self.get_logger().error(f"模型构建失败: {str(e)}")
            return
        self.q = np.zeros(self.model.nq) 
        self.dq_max = 2.0 
        # === 订阅与发布 ===
        self.create_subscription(JointState, '/joint_states', self.joint_callback, 10)
        self.torque_pub = self.create_publisher(JointState, '/gravity_torque', 10)
        
        self.srv   = self.create_service(
            ComputeGravity,
            'compute_gravity',
            self.handle_compute_gravity
        )

        # 订阅笛卡尔速度
        self.create_subscription(Twist, '/cartesian_velocity_cmd', self.velocity_callback, 10)

        # 发布关节速度
        self.joint_velocity_pub = self.create_publisher(Float64MultiArray, '/joint_velocity', 10)

        self.get_logger().info("Gravity compensator node started with robot_description.")

    def joint_callback(self, msg: JointState):
        try:
            q = np.zeros(self.model.nq)

            for i, name in enumerate(self.joint_names):
                if name in msg.name:
                    idx = msg.name.index(name)
                    q[i] = msg.position[idx]
            self.q = q 
            g = pin.computeGeneralizedGravity(self.model, self.data, q)

            torque_msg = JointState()
            torque_msg.header.stamp = self.get_clock().now().to_msg()
            torque_msg.name = self.joint_names
            torque_msg.effort = g.tolist()
            self.torque_pub.publish(torque_msg)

        except Exception as e:
            self.get_logger().error(f"关节状态处理失败: {e}")
            
    def handle_compute_gravity(self, request, response): 
        N  = len(request.joint_trajectory)
        nq = self.model.nq

        q_matrix = np.zeros((N, nq))
        names    = request.joint_trajectory[0].name

        for i, js in enumerate(request.joint_trajectory): 
            q_matrix[i, :] = np.array(js.position)

        # 逐点计算
        tau_matrix = np.zeros((N, nq))
        for i in range(N): 
            tau_matrix[i, :] = pin.computeGeneralizedGravity(self.model, self.data, q_matrix[i])

        # 返回一批力矩
        for i in range(N):
            eff = JointState()
            eff.name = names
            eff.position = q_matrix[i, :].tolist()
            eff.effort = tau_matrix[i, :].tolist()
            response.efforts.append(eff)
        last_pos = q_matrix[-1, 1]
        last_tau = tau_matrix[-1, 1]
        self.get_logger().info(f"终点第2轴位置: {last_pos:.6f}, 力矩: {last_tau:.6f}")

        self.get_logger().info(f"Batch gravity computed for {N} points")
        return response
    
    def velocity_callback(self, msg: Twist): 
        try:
            v_ee = np.array([
                msg.linear.x,
                msg.linear.y,
                msg.linear.z,
                msg.angular.x,
                msg.angular.y,
                msg.angular.z
            ])
            if len(v_ee) != 6:
                self.get_logger().error("输入笛卡尔速度不是六维向量！")
                return

            # 使用Pinocchio计算雅可比矩阵
            ee_frame = self.model.njoints - 1
            J        = pin.computeJointJacobian(self.model, self.data, self.q, ee_frame)  # 6xN
            # 伪逆求关节速度
            dq = np.linalg.pinv(J) @ v_ee
            # 限幅
            dq = np.clip(dq, -self.dq_max, self.dq_max)

            # 发布关节速度
            out_msg      = Float64MultiArray()
            out_msg.data = dq.tolist()
            self.joint_velocity_pub.publish(out_msg)

        except Exception as e: 
            self.get_logger().error(f"计算关节速度失败: {e}")

def main(args=None): 
    rclpy.init(args=args)
    node = GravityCompensator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

