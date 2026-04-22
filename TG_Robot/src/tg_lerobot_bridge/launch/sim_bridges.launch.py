from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    cmd_port = LaunchConfiguration("cmd_port")
    state_port = LaunchConfiguration("state_port")
    control_hz = LaunchConfiguration("control_hz")
    gripper_open_joint_1 = LaunchConfiguration("gripper_open_joint_1")
    gripper_close_joint_1 = LaunchConfiguration("gripper_close_joint_1")
    gripper_open_joint_2 = LaunchConfiguration("gripper_open_joint_2")
    gripper_close_joint_2 = LaunchConfiguration("gripper_close_joint_2")

    image_topic = LaunchConfiguration("image_topic")
    camera_name = LaunchConfiguration("camera_name")
    camera_port = LaunchConfiguration("camera_port")
    camera_fps = LaunchConfiguration("camera_fps")
    jpeg_quality = LaunchConfiguration("jpeg_quality")
    image_topic_2 = LaunchConfiguration("image_topic_2")
    camera_name_2 = LaunchConfiguration("camera_name_2")
    camera_port_2 = LaunchConfiguration("camera_port_2")
    camera_fps_2 = LaunchConfiguration("camera_fps_2")
    jpeg_quality_2 = LaunchConfiguration("jpeg_quality_2")

    sim_control_bridge = Node(
        package="tg_lerobot_bridge",
        executable="tg_arm620_sim_control_bridge",
        output="screen",
        parameters=[
            {
                "cmd_port": cmd_port,
                "state_port": state_port,
                "control_hz": control_hz,
                "gripper_open_joint_1": gripper_open_joint_1,
                "gripper_close_joint_1": gripper_close_joint_1,
                "gripper_open_joint_2": gripper_open_joint_2,
                "gripper_close_joint_2": gripper_close_joint_2,
            }
        ],
    )

    camera_bridge = Node(
        package="tg_lerobot_bridge",
        executable="tg_camera_zmq_bridge",
        output="screen",
        parameters=[
            {
                "image_topic": image_topic,
                "camera_name": camera_name,
                "port": camera_port,
                "fps": camera_fps,
                "jpeg_quality": jpeg_quality,
            }
        ],
    )

    camera_bridge_2 = Node(
        package="tg_lerobot_bridge",
        executable="tg_camera_zmq_bridge",
        output="screen",
        parameters=[
            {
                "image_topic": image_topic_2,
                "camera_name": camera_name_2,
                "port": camera_port_2,
                "fps": camera_fps_2,
                "jpeg_quality": jpeg_quality_2,
            }
        ],
    )

    return LaunchDescription(
        [
            DeclareLaunchArgument("cmd_port", default_value="6001"),
            DeclareLaunchArgument("state_port", default_value="6002"),
            DeclareLaunchArgument("control_hz", default_value="30.0"),
            DeclareLaunchArgument("gripper_open_joint_1", default_value="-0.75"),
            DeclareLaunchArgument("gripper_close_joint_1", default_value="0.15"),
            DeclareLaunchArgument("gripper_open_joint_2", default_value="0.75"),
            DeclareLaunchArgument("gripper_close_joint_2", default_value="-0.15"),
            DeclareLaunchArgument("image_topic", default_value="/front_camera/front_camera/image_raw"),
            DeclareLaunchArgument("camera_name", default_value="front_camera"),
            DeclareLaunchArgument("camera_port", default_value="5555"),
            DeclareLaunchArgument("camera_fps", default_value="30.0"),
            DeclareLaunchArgument("jpeg_quality", default_value="80"),
            DeclareLaunchArgument(
                "image_topic_2", default_value="/side_front_camera/side_front_camera/image_raw"
            ),
            DeclareLaunchArgument("camera_name_2", default_value="side_front_camera"),
            DeclareLaunchArgument("camera_port_2", default_value="5556"),
            DeclareLaunchArgument("camera_fps_2", default_value="30.0"),
            DeclareLaunchArgument("jpeg_quality_2", default_value="80"),
            sim_control_bridge,
            camera_bridge,
            camera_bridge_2,
        ]
    )
