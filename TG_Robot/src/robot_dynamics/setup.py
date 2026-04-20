from setuptools import setup
import os
from glob import glob

package_name = 'robot_dynamics'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]), 
        ('share/' + package_name, ['package.xml']),                                    
        (os.path.join('share', 'robot_dynamics', 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='zwh',
    maintainer_email='18392676225@163.com',
    description='Gravity compensation with Pinocchio',
    license='MIT',
    entry_points={
        'console_scripts': [
            'gravity_compensator = robot_dynamics.gravity_compensator:main',
        ],
    },
)
