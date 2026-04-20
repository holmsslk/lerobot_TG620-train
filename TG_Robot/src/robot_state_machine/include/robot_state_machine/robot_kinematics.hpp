#ifndef __ROBOT_KINEMATICS_HPP__
#define __ROBOT_KINEMATICS_HPP__

#include "rclcpp/rclcpp.hpp"
#include <moveit/move_group_interface/move_group_interface.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"
#include "robot_interfaces/msg/robot_control_msg.hpp"
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <mutex>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <Eigen/Dense>
#include <Eigen/Sparse>
// #include <OsqpEigen/OsqpEigen.h>
#include <kdl_parser/kdl_parser.hpp>
#include <urdf/model.h>
#include <kdl/chain.hpp>
#include <kdl/tree.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/jntarray.hpp>
#include <kdl/jacobian.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
enum class Direction
{
    NONE = 0,
    FORWARD = 55,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ROLL_CW,
    ROLL_CCW,
    PITCH_UP,
    PITCH_DOWN,
    YAW_LEFT,
    YAW_RIGHT,
};

#define MOTOR_NUM 6

class RobotKinematics
{
public:
    enum class IKMethod
    {
        PSEUDO_INVERSE,
        DAMPED_LEAST_SQUARES,
        QP,
    };

    RobotKinematics();

    /**
     * @brief 初始化机器人运动学，绑定ROS节点和MoveIt接口
     * @param node rclcpp::Node::SharedPtr ROS节点智能指针
     */
    void initialize(const rclcpp::Node::SharedPtr &node);

    /**
     * @brief 设置逆运动学求解方法
     * @param method IKMethod 枚举类型
     */
    void setIKMmethod(IKMethod method);

    /**
     * @brief 根据给定末端速度计算关节速度（逆运动学）
     * @param twist 末端速度，geometry_msgs::msg::Twist
     * @param currentJointPositions 当前关节位置，vector<double>
     * @return 计算得到的关节速度，Eigen::VectorXd
     */
    Eigen::VectorXd computeVelocityIK(
        const geometry_msgs::msg::Twist &twist,
        const std::vector<double> &current_joint_positions);

    /**
     * @brief 根据方向生成对应的末端速度指令
     * @param direction 运动方向
     * @param linearSpeed 线速度（默认0.01 m/s）
     * @param angularSpeed 角速度（默认约1度/s）
     * @return geometry_msgs::msg::Twist 速度消息
     */
    geometry_msgs::msg::Twist generateTwist(
        Direction direction,
        double linearSpeed = 0.01,
        double angularSpeed = 5.0 * M_PI / 180.0);

    // ----------------- Basic movement functions -----------------

    /**
     * @brief 移动机械臂到指定位姿（阻塞执行）
     * @param targetPose 目标位姿
     * @return true 如果规划及执行成功，否则false
     */
    bool moveToPose(const geometry_msgs::msg::Pose &targetPose);

    /**
     * @brief 移动机械臂到指定关节角度（阻塞执行）
     * @param targetJointPositions 目标关节角度数组
     * @return true 如果规划及执行成功，否则false
     */
    bool moveToJointPositions(const std::vector<double> &target_joint_positions);

    /**
     * @brief 生成指定关节速度的指令
     * @param joint_index 关节索引
     * @param velocity 速度
     * @return robot_interfaces::msg::RobotControlMsg 指令消息
     */
    robot_interfaces::msg::RobotControlMsg generate_joint_velocity_command(uint8_t joint_index, float velocity);

    /**
     * @brief 生成关节组速度的指令
     * @param velocities 关节速度数组
     * @return robot_interfaces::msg::RobotControlMsg 指令消息
     */
    robot_interfaces::msg::RobotControlMsg generate_joint_velocity_command(const std::vector<double> &velocities);

    /**
     * @brief 生成指定关节位置的指令
     * @param joint_index 关节索引
     * @param position 位置
     * @return robot_interfaces::msg::RobotControlMsg 指令消息
     */
    robot_interfaces::msg::RobotControlMsg generate_joint_position_command(uint8_t joint_index, float position);

    /**
     * @brief 生成关节组位置的指令
     * @param positions 位置数组
     * @return robot_interfaces::msg::RobotControlMsg 指令消息
     */
    robot_interfaces::msg::RobotControlMsg generate_joint_position_command(const std::vector<double> &positions);

    /**
     * @brief 生成关节组失能的指令
     * @param joint_index 电机索引
     * @return robot_interfaces::msg::RobotControlMsg 指令消息
     */
    robot_interfaces::msg::RobotControlMsg motor_disable(uint8_t joint_index);

    /**
     * @brief 生成全部关节失能的指令
     * @return robot_interfaces::msg::RobotControlMsg 指令消息
     */
    robot_interfaces::msg::RobotControlMsg motor_disable();

    /**
     * @brief 生成电机停止运动的指令
     * @param motor_mode 电机模式
     * @return robot_interfaces::msg::RobotControlMsg 指令消息
     */
    robot_interfaces::msg::RobotControlMsg robotic_arm_move_stop(uint8_t motor_mode);

    // ----------------- advanced movement functions -----------------
    bool move_in_line(const geometry_msgs::msg::Pose &current_pose, Direction direction, double delta_pos = 0.01);
    bool move_in_orientation(const geometry_msgs::msg::Pose &current_pose, Direction direction, double delta_angle = 0.017453);
    bool plan_cartesian_path(const std::vector<geometry_msgs::msg::Pose> &waypoints, moveit_msgs::msg::RobotTrajectory &trajectory);
    bool execute_plan(const moveit_msgs::msg::RobotTrajectory &trajectory);
    bool plan_and_execute_cartesian_path(const std::vector<geometry_msgs::msg::Pose> &waypoints);
    bool computeJacobian(KDL::Jacobian &jacobian_out) const;
    bool computeJacobian(const KDL::JntArray &joint_positions, KDL::Jacobian &jacobian_out) const;

    std::vector<geometry_msgs::msg::Pose> generate_movec_waypoints(
        const geometry_msgs::msg::Pose &start_pose,
        const geometry_msgs::msg::Pose &mid_pose,
        const geometry_msgs::msg::Pose &goal_pose,
        bool must_pass_through_middle = true,
        int num_points = 30);

    // joint state getter
    void load_joint_limits();
    void load_joint_velocity_limits();
    const std::map<std::string, std::pair<double, double>> &get_joint_limits() const;
    std::vector<std::string> get_joint_names() const;
    geometry_msgs::msg::Pose get_current_pose() const;
    void speed_config_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);

private:
    rclcpp::Node::SharedPtr node_;
    std::shared_ptr<moveit::planning_interface::MoveGroupInterface> arm_;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr speed_config_sub_;

    std::string robot_model_name; // 机器人模型名称
    IKMethod ik_method_ = IKMethod::QP;

    std::vector<double> latest_joint_velocity_;
    std::mutex velocity_mutex_;

    std::unique_ptr<KDL::ChainFkSolverPos_recursive> fk_solver_;
    std::unique_ptr<KDL::ChainJntToJacSolver> jacobian_solver_;
    KDL::Chain kdl_chain_;
    KDL::Tree kdl_tree_;
    urdf::Model urdf_model_;
    std::vector<std::string> joint_names_;                           // 关节名称
    std::map<std::string, std::pair<double, double>> joint_limits_;  // 关节限位
    std::unordered_map<std::string, double> joint_velocity_limits_;  // 关节限速
    std::unordered_map<std::string, double> joint_velocity_weights_; // 关节速度权重
    KDL::JntArray current_joint_positions_;                          // 当前关节位置

    bool init_kdl(const std::string &urdf_str, const std::string &base_link, const std::string &tip_link);
    Eigen::VectorXd computePseudoInverseIK(const KDL::Jacobian &jacobian, const KDL::Twist &twist);
    Eigen::VectorXd computeDampedLeastSquaresIK(const KDL::Jacobian &jacobian, const KDL::Twist &twist);
    Eigen::VectorXd computeVelocityIK_QP(const KDL::Jacobian &jacobian, const KDL::Twist &twist,
                                         const std::vector<std::string> &joint_names, const std::optional<std::vector<double>> &current_joint_positions = std::nullopt);

    void updateJointPositions(const std::vector<double> &joint_positions);

    std::string load_urdf_file(const std::string &robot_model_name);
};

namespace kdl_utils
{
    // Eigen::VectorXd -> KDL::JntArray
    inline KDL::JntArray toKDL(const Eigen::VectorXd &vec)
    {
        KDL::JntArray jnt_array(vec.size());
        for (Eigen::Index i = 0; i < vec.size(); ++i)
        {
            jnt_array(i) = vec(i);
        }
        return jnt_array;
    }

    // KDL::JntArray -> Eigen::VectorXd
    inline Eigen::VectorXd toEigen(const KDL::JntArray &jnt_array)
    {
        Eigen::VectorXd vec(jnt_array.rows());
        for (size_t i = 0; i < jnt_array.rows(); ++i)
        {
            vec(i) = jnt_array(i);
        }
        return vec;
    }

    // Eigen::MatrixXd -> KDL::Jacobian
    inline KDL::Jacobian toKDL(const Eigen::MatrixXd &eigen_matrix)
    {
        KDL::Jacobian jacobian(eigen_matrix.cols());
        jacobian.data = eigen_matrix;
        return jacobian;
    }

    // KDL::Jacobian -> Eigen::MatrixXd
    inline Eigen::MatrixXd toEigen(const KDL::Jacobian &jacobian)
    {
        return jacobian.data;
    }
}

#endif // __ROBOT_KINEMATICS_HPP__
