import os
import re

import xacro
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, OpaqueFunction, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def strip_xml_comments(xml_raw: str) -> str:
    return re.sub(r"<!--.*?-->", "", xml_raw, flags=re.S)


def launch_setup(context, *args, **kwargs):
    del args, kwargs

    package_name = "robot_gazebo"
    robot_model_name = LaunchConfiguration("robot_model_name").perform(context)
    entity_name = LaunchConfiguration("entity_name").perform(context)

    pkg_share = get_package_share_directory(package_name)
    urdf_model_path = os.path.join(pkg_share, "config", f"gazebo_{robot_model_name}_lerobot.urdf.xacro")

    if not os.path.exists(urdf_model_path):
        raise FileNotFoundError(f"URDF file not found: {urdf_model_path}")

    # Parse xacro -> robot_description
    with open(urdf_model_path) as model_file:
        doc = xacro.parse(model_file)
    xacro.process_doc(
        doc,
        mappings={
            # Use arm620 geometry from xacro, while ros2_control is defined in gazebo_arm620_lerobot.urdf.xacro
            "ros_profile": "none",
            "ros_hardware_interface": "position",
        },
    )
    xml_raw = doc.toxml()
    xml_clean = strip_xml_comments(xml_raw)
    params = {"robot_description": xml_clean}

    start_gazebo_cmd = ExecuteProcess(
        cmd=["gazebo", "--verbose", "-s", "libgazebo_ros_init.so", "-s", "libgazebo_ros_factory.so"],
        output="screen",
    )

    node_robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"use_sim_time": True}, params, {"publish_frequency": 30.0}],
        output="screen",
    )

    spawn_entity = Node(
        package="gazebo_ros",
        executable="spawn_entity.py",
        arguments=["-topic", "robot_description", "-entity", entity_name],
        output="screen",
    )

    load_joint_state_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "joint_state_broadcaster",
            "--controller-manager",
            "/controller_manager",
            "--controller-manager-timeout",
            "120",
        ],
        output="screen",
    )

    load_joint_position_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "arm_position_controller",
            "--controller-manager",
            "/controller_manager",
            "--controller-manager-timeout",
            "120",
        ],
        output="screen",
    )

    close_evt1 = RegisterEventHandler(
        event_handler=OnProcessExit(target_action=spawn_entity, on_exit=[load_joint_state_controller])
    )
    close_evt2 = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=load_joint_state_controller, on_exit=[load_joint_position_controller]
        )
    )

    return [
        start_gazebo_cmd,
        node_robot_state_publisher,
        spawn_entity,
        close_evt1,
        close_evt2,
    ]


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "robot_model_name",
                default_value="arm620",
                description="Robot model name, currently supports arm620",
            ),
            DeclareLaunchArgument(
                "entity_name",
                default_value="arm620_lerobot",
                description="Spawned model entity name in Gazebo",
            ),
            OpaqueFunction(function=launch_setup),
        ]
    )
