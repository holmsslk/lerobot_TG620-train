import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    cmd_port = LaunchConfiguration("cmd_port")
    state_port = LaunchConfiguration("state_port")
    control_hz = LaunchConfiguration("control_hz")

    model_path = LaunchConfiguration("model_path")
    mujoco_home = LaunchConfiguration("mujoco_home")
    mujoco_gl = LaunchConfiguration("mujoco_gl")
    viewer = LaunchConfiguration("viewer")

    max_vel_rad_s = LaunchConfiguration("max_vel_rad_s")
    max_acc_rad_s2 = LaunchConfiguration("max_acc_rad_s2")

    gripper_open_joint_1 = LaunchConfiguration("gripper_open_joint_1")
    gripper_close_joint_1 = LaunchConfiguration("gripper_close_joint_1")
    gripper_open_joint_2 = LaunchConfiguration("gripper_open_joint_2")
    gripper_close_joint_2 = LaunchConfiguration("gripper_close_joint_2")

    front_camera_name = LaunchConfiguration("front_camera_name")
    front_camera_port = LaunchConfiguration("front_camera_port")
    front_camera_fps = LaunchConfiguration("front_camera_fps")
    front_camera_width = LaunchConfiguration("front_camera_width")
    front_camera_height = LaunchConfiguration("front_camera_height")

    side_camera_name = LaunchConfiguration("side_camera_name")
    side_camera_port = LaunchConfiguration("side_camera_port")
    side_camera_fps = LaunchConfiguration("side_camera_fps")
    side_camera_width = LaunchConfiguration("side_camera_width")
    side_camera_height = LaunchConfiguration("side_camera_height")

    mujoco_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("tg_lerobot_bridge"),
                "launch",
                "mujoco_sim.launch.py",
            )
        ),
        launch_arguments={
            "cmd_port": cmd_port,
            "state_port": state_port,
            "control_hz": control_hz,
            "model_path": model_path,
            "mujoco_home": mujoco_home,
            "mujoco_gl": mujoco_gl,
            "viewer": viewer,
            "max_vel_rad_s": max_vel_rad_s,
            "max_acc_rad_s2": max_acc_rad_s2,
            "gripper_open_joint_1": gripper_open_joint_1,
            "gripper_close_joint_1": gripper_close_joint_1,
            "gripper_open_joint_2": gripper_open_joint_2,
            "gripper_close_joint_2": gripper_close_joint_2,
            "front_camera_name": front_camera_name,
            "front_camera_port": front_camera_port,
            "front_camera_fps": front_camera_fps,
            "front_camera_width": front_camera_width,
            "front_camera_height": front_camera_height,
            "side_camera_name": side_camera_name,
            "side_camera_port": side_camera_port,
            "side_camera_fps": side_camera_fps,
            "side_camera_width": side_camera_width,
            "side_camera_height": side_camera_height,
        }.items(),
    )

    default_model_path = os.path.join(
        get_package_share_directory("tg_lerobot_bridge"),
        "models",
        "arm620_omnipicker_mujoco.xml",
    )

    return LaunchDescription(
        [
            DeclareLaunchArgument("cmd_port", default_value="6001"),
            DeclareLaunchArgument("state_port", default_value="6002"),
            DeclareLaunchArgument("control_hz", default_value="30.0"),
            DeclareLaunchArgument("model_path", default_value=default_model_path),
            DeclareLaunchArgument("mujoco_home", default_value="/home/holms/Projects/mujoco/mujoco-3.3.0"),
            DeclareLaunchArgument("mujoco_gl", default_value="egl"),
            DeclareLaunchArgument("viewer", default_value="false"),
            DeclareLaunchArgument("max_vel_rad_s", default_value="2.61799"),
            DeclareLaunchArgument("max_acc_rad_s2", default_value="2.61799"),
            DeclareLaunchArgument("gripper_open_joint_1", default_value="0.025"),
            DeclareLaunchArgument("gripper_close_joint_1", default_value="0.0"),
            DeclareLaunchArgument("gripper_open_joint_2", default_value="0.025"),
            DeclareLaunchArgument("gripper_close_joint_2", default_value="0.0"),
            DeclareLaunchArgument("front_camera_name", default_value="front_camera"),
            DeclareLaunchArgument("front_camera_port", default_value="5555"),
            DeclareLaunchArgument("front_camera_fps", default_value="30.0"),
            DeclareLaunchArgument("front_camera_width", default_value="640"),
            DeclareLaunchArgument("front_camera_height", default_value="480"),
            DeclareLaunchArgument("side_camera_name", default_value="side_front_camera"),
            DeclareLaunchArgument("side_camera_port", default_value="5556"),
            DeclareLaunchArgument("side_camera_fps", default_value="30.0"),
            DeclareLaunchArgument("side_camera_width", default_value="640"),
            DeclareLaunchArgument("side_camera_height", default_value="480"),
            mujoco_launch,
        ]
    )
