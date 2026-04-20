cmake_minimum_required(VERSION 3.8)
project(robot_state_machine)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(control_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(rosbag2_cpp REQUIRED)
find_package(rosbag2_storage REQUIRED)
find_package(rosbag2_transport REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(robot_interfaces REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(orocos_kdl REQUIRED)
find_package(kdl_parser REQUIRED)
find_package(robot_driver REQUIRED)
#find_package(Eigen3 REQUIRED)
#find_package(OsqpEigen REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}
)

# --- robot_kinematics as a library ---
add_library(robot_kinematics
  src/robot_kinematics.cpp
)
target_include_directories(robot_kinematics PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(robot_kinematics
  rclcpp
  robot_interfaces
  orocos_kdl
  kdl_parser
  #Eigen3
  #OsqpEigen
  moveit_ros_planning_interface
)

#target_link_libraries(robot_kinematics
# OsqpEigen::OsqpEigen  # ✅ 显式链接 OsqpEigen
#)

# --- robot_state_machine executable ---
add_executable(robot_state_machine
  src/robot_state_machine.cpp
  src/robot_joint_recorder.cpp
)
ament_target_dependencies(robot_state_machine
  rclcpp
  moveit_ros_planning_interface
  geometry_msgs
  std_msgs
  trajectory_msgs
  robot_interfaces
  sensor_msgs
  control_msgs
  tf2_ros
  tf2_geometry_msgs
  rosbag2_cpp
  rosbag2_storage
  rosbag2_transport
  ament_index_cpp
  SQLite3
  orocos_kdl
  kdl_parser
  robot_driver
  #Eigen3
  #OsqpEigen
)

target_link_libraries(robot_state_machine
  #OsqpEigen::OsqpEigen
  robot_kinematics
)

# --- Installation ---
install(TARGETS
  robot_state_machine
  robot_kinematics
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# --- Unit Testing ---
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  find_package(ament_cmake_gtest REQUIRED)

  ament_add_gtest(test_generate_joint_velocity_command
    test/test_generate_joint_velocity_command.cpp
  )
  target_link_libraries(test_generate_joint_velocity_command
    robot_kinematics
  )
  ament_target_dependencies(test_generate_joint_velocity_command
    rclcpp
    robot_interfaces
  )

  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
