import os
from glob import glob

from setuptools import find_packages, setup

package_name = "tg_lerobot_bridge"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(),
    data_files=[
        ("share/ament_index/resource_index/packages", [f"resource/{package_name}"]),
        (f"share/{package_name}", ["package.xml"]),
        (os.path.join("share", package_name, "launch"), glob("launch/*.launch.py")),
    ],
    install_requires=["setuptools", "numpy", "pyzmq"],
    zip_safe=True,
    maintainer="holms",
    maintainer_email="holms@example.com",
    description="ROS2 to LeRobot ZMQ bridge for TG arm620",
    license="Apache-2.0",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "tg_arm620_control_bridge = tg_lerobot_bridge.control_bridge_node:main",
            "tg_arm620_sim_control_bridge = tg_lerobot_bridge.sim_control_bridge_node:main",
            "tg_arm620_gripper_scan = tg_lerobot_bridge.gripper_scan_node:main",
            "tg_camera_zmq_bridge = tg_lerobot_bridge.camera_bridge_node:main",
        ],
    },
)
