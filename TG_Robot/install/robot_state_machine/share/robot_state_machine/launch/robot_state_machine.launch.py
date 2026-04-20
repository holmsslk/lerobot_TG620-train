from launch import LaunchDescription
from launch_ros.actions import Node
# from launch.actions import SetParameter

def generate_launch_description():
    ld = LaunchDescription()
    
    robot_state_machine_node = Node (
        package = 'robot_state_machine',
        executable ='robot_state_machine',
        parameters=[{
            'robot_model_name': 'arm620'
        }]
    )
    ld.add_action(robot_state_machine_node)
    return ld
