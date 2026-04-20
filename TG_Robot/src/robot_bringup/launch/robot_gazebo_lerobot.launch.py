import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    robot_model_name = LaunchConfiguration("robot_model_name")
    cmd_port = LaunchConfiguration("cmd_port")
    state_port = LaunchConfiguration("state_port")
    control_hz = LaunchConfiguration("control_hz")
    image_topic = LaunchConfiguration("image_topic")
    camera_name = LaunchConfiguration("camera_name")
    camera_port = LaunchConfiguration("camera_port")
    camera_fps = LaunchConfiguration("camera_fps")
    image_topic_2 = LaunchConfiguration("image_topic_2")
    camera_name_2 = LaunchConfiguration("camera_name_2")
    camera_port_2 = LaunchConfiguration("camera_port_2")
    camera_fps_2 = LaunchConfiguration("camera_fps_2")

    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("robot_gazebo"),
                "launch",
                "robot_gazebo_lerobot.launch.py",
            )
        ),
        launch_arguments={"robot_model_name": robot_model_name}.items(),
    )

    bridge_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("tg_lerobot_bridge"),
                "launch",
                "sim_bridges.launch.py",
            )
        ),
        launch_arguments={
            "cmd_port": cmd_port,
            "state_port": state_port,
            "control_hz": control_hz,
            "image_topic": image_topic,
            "camera_name": camera_name,
            "camera_port": camera_port,
            "camera_fps": camera_fps,
            "image_topic_2": image_topic_2,
            "camera_name_2": camera_name_2,
            "camera_port_2": camera_port_2,
            "camera_fps_2": camera_fps_2,
        }.items(),
    )

    return LaunchDescription(
        [
            DeclareLaunchArgument("robot_model_name", default_value="arm620"),
            DeclareLaunchArgument("cmd_port", default_value="6001"),
            DeclareLaunchArgument("state_port", default_value="6002"),
            DeclareLaunchArgument("control_hz", default_value="30.0"),
            DeclareLaunchArgument("image_topic", default_value="/front_camera/front_camera/image_raw"),
            DeclareLaunchArgument("camera_name", default_value="front_camera"),
            DeclareLaunchArgument("camera_port", default_value="5555"),
            DeclareLaunchArgument("camera_fps", default_value="30.0"),
            DeclareLaunchArgument(
                "image_topic_2", default_value="/side_front_camera/side_front_camera/image_raw"
            ),
            DeclareLaunchArgument("camera_name_2", default_value="side_front_camera"),
            DeclareLaunchArgument("camera_port_2", default_value="5556"),
            DeclareLaunchArgument("camera_fps_2", default_value="30.0"),
            gazebo_launch,
            bridge_launch,
        ]
    )
