from setuptools import find_packages, setup
import os
from glob import glob
package_name = 'traj_smoother_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', 'traj_smoother_py', 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools', 'scipy', 'rclpy', 'trajectory-msgs'],
    zip_safe=True,
    maintainer='orin',
    maintainer_email='1959711225@qq.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
    'console_scripts': [
        'traj_smoother = traj_smoother_py.smoother_node:main',
    ],
    },
)
