from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robot_state_machine',
            executable='robot_state_machine',
            name='robot_state_machine',
            parameters=[{'robot_model_name': 'arm380'}]
        )
    ])