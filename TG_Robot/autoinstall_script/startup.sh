#!/bin/bash

# 关闭并重新设置网络接口
/usr/bin/sudo /sbin/ip link set can0 down
/usr/bin/sudo /sbin/ip link set can0 up type can bitrate 1000000

# 设置 ROS 环境
source /opt/ros/humble/setup.bash
source /home/orin/.bashrc

# 切换到包含 robot_bringup 包的工作空间
source /home/orin/auto_install/orz_robot/install/setup.bash

# 启动 ROS2 节点
ros2 launch robot_bringup robot_real.launch.py
