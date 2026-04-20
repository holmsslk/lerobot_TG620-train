#!/bin/bash
# 提示用户是否要进入运行模式
read -p "是否要进入运行模式？(y/n): " choice
if [ "$choice" = "y" ] || [ "$choice" = "Y" ]; then
sudo ip link set can0 down
sudo ip link set can0 txqueuelen 1000
sudo ip link set can0 up type can bitrate 1000000 sample-point 0.8 dbitrate 5000000 dsample-point 0.75 fd on loopback off restart-ms 100
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
fi
