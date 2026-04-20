#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from csaps import csaps
import numpy as np

class TrajectorySmoother(Node):
    def __init__(self):
        super().__init__('trajectory_smoother')

        self.sub = self.create_subscription(
            JointTrajectory,
            '/raw_joint_trajectory',
            self.traj_callback,
            10)
        self.pub = self.create_publisher(JointTrajectory, '/joint_trajectory', 10)
        # 可调参数
        self.static_vel_threshold = 0.01   # 判断静止的速度阈值
        self.base_smooth = 0.01            # 基础平滑系数比例
        self.get_logger().info('Trajectory smoother node started.')

        self.base_smooth = 0.01            # 基础平滑系数比例
        self.get_logger().info('Trajectory smoother node started.')



    def traj_callback(self, msg):
        self.get_logger().info(f'Received trajectory with {len(msg.points)} points.')
        if len(msg.points) < 5:
            self.get_logger().warn('Too few points, skipping smoothing.')
            self.pub.publish(msg)
            return

        t = np.array([p.time_from_start.sec + p.time_from_start.nanosec * 1e-9 for p in msg.points])
        n_joints = len(msg.joint_names)
        smoothed = JointTrajectory()
        smoothed.joint_names = msg.joint_names
        smoothed.header = msg.header
        smooth = 0.95
        all_pos = []
        all_vel = []
        for i in range(n_joints):
            pos = np.array([p.positions[i] for p in msg.points])
            # 直接输出平滑后的结果（Python 版 csaps）
            spline_func = csaps(t, pos, smooth=0.95)

            # 计算平滑位置
            sm_pos = spline_func(t)

            # 计算一阶导（速度）
            sm_vel = spline_func(t, nu=1)   # nu=1 表示求一阶导
            all_pos.append(sm_pos)
            all_vel.append(sm_vel)

        all_pos = np.array(all_pos).T  # shape: (N, n_joints)
        all_vel = np.array(all_vel).T

        for idx, ti in enumerate(t):
            pt = JointTrajectoryPoint()
            pt.positions = all_pos[idx, :].tolist()
            pt.velocities = all_vel[idx, :].tolist()
            pt.effort = [0.0] * n_joints
            pt.time_from_start.sec = int(ti)
            pt.time_from_start.nanosec = int((ti - int(ti)) * 1e9)
            smoothed.points.append(pt)

        self.get_logger().info(f'Publishing smoothed trajectory ({len(smoothed.points)} points)')
        self.pub.publish(smoothed)


def main():
    rclpy.init()
    node = TrajectorySmoother()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

