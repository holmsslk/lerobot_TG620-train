import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import Command, FindExecutable, LaunchConfiguration

import xacro

def generate_launch_description():

    robot_xacro_file = os.path.join(get_package_share_directory('robot_description'), 'urdf', 'arm620.urdf')

    robot_description = Command(
        [FindExecutable(name='xacro'), ' ', robot_xacro_file])
    
    return LaunchDescription([
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            respawn=True,
            parameters=[{'robot_description': robot_description}],
            output='screen'
        )
    ])