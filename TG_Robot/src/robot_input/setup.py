from setuptools import find_packages, setup

package_name = 'robot_input'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dyk',
    maintainer_email='d570737261@163.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest', 'ament_pytest_ros', 'rclpy'],
    entry_points={
        'console_scripts': [
            'robot_input_keyboard = keyboard.keyboard_controller:main',
            'robot_input_tcp = tcp.tcp_controller:main'
        ],
    },
)
