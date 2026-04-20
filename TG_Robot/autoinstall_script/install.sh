#!/bin/bash
wget http://fishros.com/install  -O fishros && /bin/bash fishros

# 安装必备的包
sudo apt install ros-humble-ament-cmake ros-humble-can* ros-humble-control-msgs ros-humble-moveit -y
sudo apt install iproute2 -y
# 清理缓存
sudo apt-get clean && sudo apt autoclean 

# 编译软件包
source /opt/ros/humble/setup.bash
cd ..
colcon build --packages-select ros2_socketcan_msgs
colcon build --packages-select ros2_socketcan
colcon build --packages-select robot_interfaces
source install/setup.bash
colcon build 

# 将软件包目录添加到用户目录
echo "source $(dirname "$(realpath "$0")")/install/setup.bash" >> ~/.bashrc
source $(dirname "$(realpath "$0")")/install/setup.bash

# 获取当前用户名
USERNAME=$USER

# 定义要追加的内容
SUDOERS_ENTRY="$USERNAME ALL=(ALL) NOPASSWD: /sbin/ip link set can0 up type can bitrate 1000000, /sbin/ip link set can0 down"

# 使用 'echo' 和 'tee' 命令将内容追加到 sudoers 文件中
echo "$SUDOERS_ENTRY" | sudo tee -a /etc/sudoers > /dev/null

# 检查是否追加成功
if sudo grep -q "$SUDOERS_ENTRY" /etc/sudoers; then
  echo "Entry successfully added to sudoers file."
else
  echo "Failed to add entry to sudoers file."
fi

# 提示用户是否要进入运行模式
read -p "是否要进入运行模式？(y/n): " choice
if [ "$choice" = "y" ] || [ "$choice" = "Y" ]; then
sudo ip link set can0 up type can bitrate 1000000
	echo -e "机械臂型号: \n (1) arm380 \n (2) arm620" 
	 read -p "请输入机械臂规格：" choice1
	if [ "$choice1" = "1" ] || [ "$choice1" = "atm380" ]; then
		ros2 launch robot_bringup arm380_real.launch.py
	else 
		if [ "$choice1" = "2" ] || [ "$choice1" = "atm620" ]; then
			ros2 launch robot_bringup arm620_real.launch.py
		fi
	fi
    echo "运行模式已启动。"
else
    echo "安装完成。未进入运行模式。"
fi
