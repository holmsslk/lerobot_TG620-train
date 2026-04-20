from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory
def generate_launch_description():
    urdf_path = os.path.join(
    get_package_share_directory('robot_description'),
    'urdf',
    'arm620.urdf'
    )

    with open(urdf_path, 'r') as urdf_file:
        urdf_str = urdf_file.read()
    print("Loaded URDF from:", urdf_path)
    return LaunchDescription([
        Node(
            package='robot_dynamics',
            executable='gravity_compensator',
            name='gravity_compensator',
            output='screen',
            parameters=[{
                'robot_description': urdf_str
            }]
        )
    ])

