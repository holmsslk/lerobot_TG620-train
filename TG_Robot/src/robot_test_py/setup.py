from setuptools import find_packages, setup

package_name = 'robot_test_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dky',
    maintainer_email='D570737261@163.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "robot_test_py = robot_test_py.robot_test_py:main",
            "robot_test_py2 = robot_test_py.robot_test_py2:main"
        ],
    },
)
