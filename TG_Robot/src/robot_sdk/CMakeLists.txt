cmake_minimum_required(VERSION 3.8)
project(robot_sdk)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_ros_move_group REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(rosbag2_cpp REQUIRED)
find_package(rosbag2_storage REQUIRED)
find_package(rosbag2_transport REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(actionlib_msgs REQUIRED)
find_package(control_msgs REQUIRED)
find_package(robot_interfaces REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(SQLite3 REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}
)

# 1. 生成 robot_sdk 库（核心逻辑）
add_library(robot_sdk_lib SHARED
    src/robot_sdk.cpp
)
ament_target_dependencies(robot_sdk_lib 
    geometry_msgs
    std_msgs 
    rclcpp 
    moveit_ros_planning_interface 
    moveit_ros_move_group 
    rclcpp_action 
    actionlib_msgs 
    sensor_msgs 
    trajectory_msgs
    control_msgs
    robot_interfaces
    tf2_ros 
)

# 2. 生成 robot_sdk 可执行文件（调用库）
add_executable(robot_sdk src/robot_sdk.cpp)  # 入口文件
target_link_libraries(robot_sdk robot_sdk_lib)


# 4. 安装库 & 可执行文件 & 头文件
install(TARGETS
    robot_sdk_lib
    robot_sdk
    DESTINATION lib/${PROJECT_NAME}
)

install(
    DIRECTORY include/
    DESTINATION include/
)

install(
    DIRECTORY launch
    DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

