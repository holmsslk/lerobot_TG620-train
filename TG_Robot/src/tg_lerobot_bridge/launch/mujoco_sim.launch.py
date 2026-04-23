from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


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
    gripper_max_delta_rad = LaunchConfiguration("gripper_max_delta_rad")

    front_camera_name = LaunchConfiguration("front_camera_name")
    front_camera_port = LaunchConfiguration("front_camera_port")
    front_camera_fps = LaunchConfiguration("front_camera_fps")
    front_camera_width = LaunchConfiguration("front_camera_width")
    front_camera_height = LaunchConfiguration("front_camera_height")
    front_camera_jpeg_quality = LaunchConfiguration("front_camera_jpeg_quality")

    side_camera_name = LaunchConfiguration("side_camera_name")
    side_camera_port = LaunchConfiguration("side_camera_port")
    side_camera_fps = LaunchConfiguration("side_camera_fps")
    side_camera_width = LaunchConfiguration("side_camera_width")
    side_camera_height = LaunchConfiguration("side_camera_height")
    side_camera_jpeg_quality = LaunchConfiguration("side_camera_jpeg_quality")

    mujoco_sim = Node(
        package="tg_lerobot_bridge",
        executable="tg_arm620_mujoco_sim",
        arguments=[
            "--model-path",
            model_path,
            "--mujoco-home",
            mujoco_home,
            "--mujoco-gl",
            mujoco_gl,
            "--viewer",
            viewer,
            "--cmd-port",
            cmd_port,
            "--state-port",
            state_port,
            "--control-hz",
            control_hz,
            "--max-vel-rad-s",
            max_vel_rad_s,
            "--max-acc-rad-s2",
            max_acc_rad_s2,
            "--gripper-open-joint-1",
            gripper_open_joint_1,
            "--gripper-close-joint-1",
            gripper_close_joint_1,
            "--gripper-open-joint-2",
            gripper_open_joint_2,
            "--gripper-close-joint-2",
            gripper_close_joint_2,
            "--gripper-max-delta-rad",
            gripper_max_delta_rad,
            "--front-camera-name",
            front_camera_name,
            "--front-camera-port",
            front_camera_port,
            "--front-camera-fps",
            front_camera_fps,
            "--front-camera-width",
            front_camera_width,
            "--front-camera-height",
            front_camera_height,
            "--front-camera-jpeg-quality",
            front_camera_jpeg_quality,
            "--side-camera-name",
            side_camera_name,
            "--side-camera-port",
            side_camera_port,
            "--side-camera-fps",
            side_camera_fps,
            "--side-camera-width",
            side_camera_width,
            "--side-camera-height",
            side_camera_height,
            "--side-camera-jpeg-quality",
            side_camera_jpeg_quality,
        ],
        output="screen",
    )

    return LaunchDescription(
        [
            DeclareLaunchArgument("cmd_port", default_value="6001"),
            DeclareLaunchArgument("state_port", default_value="6002"),
            DeclareLaunchArgument("control_hz", default_value="30.0"),
            DeclareLaunchArgument("model_path", default_value=""),
            DeclareLaunchArgument("mujoco_home", default_value="/home/holms/Projects/mujoco/mujoco-3.3.0"),
            DeclareLaunchArgument("mujoco_gl", default_value="egl"),
            DeclareLaunchArgument("viewer", default_value="false"),
            DeclareLaunchArgument("max_vel_rad_s", default_value="2.61799"),
            DeclareLaunchArgument("max_acc_rad_s2", default_value="2.61799"),
            DeclareLaunchArgument("gripper_open_joint_1", default_value="0.025"),
            DeclareLaunchArgument("gripper_close_joint_1", default_value="0.0"),
            DeclareLaunchArgument("gripper_open_joint_2", default_value="0.025"),
            DeclareLaunchArgument("gripper_close_joint_2", default_value="0.0"),
            DeclareLaunchArgument("gripper_max_delta_rad", default_value="0.08"),
            DeclareLaunchArgument("front_camera_name", default_value="front_camera"),
            DeclareLaunchArgument("front_camera_port", default_value="5555"),
            DeclareLaunchArgument("front_camera_fps", default_value="30.0"),
            DeclareLaunchArgument("front_camera_width", default_value="640"),
            DeclareLaunchArgument("front_camera_height", default_value="480"),
            DeclareLaunchArgument("front_camera_jpeg_quality", default_value="80"),
            DeclareLaunchArgument("side_camera_name", default_value="side_front_camera"),
            DeclareLaunchArgument("side_camera_port", default_value="5556"),
            DeclareLaunchArgument("side_camera_fps", default_value="30.0"),
            DeclareLaunchArgument("side_camera_width", default_value="640"),
            DeclareLaunchArgument("side_camera_height", default_value="480"),
            DeclareLaunchArgument("side_camera_jpeg_quality", default_value="80"),
            mujoco_sim,
        ]
    )
