from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'use_canfd',
            default_value='true',
            description='Whether to use CAN FD'
        ),

        Node(
            package='robot_driver',
            executable='robot_driver_node',
            name='robot_driver_node',
            parameters=[{
                'use_canfd': LaunchConfiguration('use_canfd')
            }]
        )
    ])