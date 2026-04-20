#include "robot_state_machine/robot_kinematics.hpp"

RobotKinematics::RobotKinematics() {}

void RobotKinematics::initialize(const rclcpp::Node::SharedPtr &node)
{
    node_ = node;

    node_->declare_parameter<std::string>("robot_model_name", "arm620");
    robot_model_name = node_->get_parameter("robot_model_name").as_string();

    node_->declare_parameter<double>("speed_scaling", 1.0);
    double init_speed_scaling = node_->get_parameter("speed_scaling").as_double();
    speed_config_sub_ = node_->create_subscription<std_msgs::msg::Float64MultiArray>("motion_config", 10, std::bind(&RobotKinematics::speed_config_callback, this, std::placeholders::_1));
    if (!init_kdl(robot_model_name, "base_link", "Link6"))
    {
        RCLCPP_ERROR(node_->get_logger(), "Failed to initialize robot kinematics from URDF.");
        return;
    }

    arm_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(node_, "arm");
    arm_->setGoalJointTolerance(0.0007);
    arm_->setMaxVelocityScalingFactor(init_speed_scaling); // 初始值
    arm_->setMaxAccelerationScalingFactor(init_speed_scaling);
    arm_->setPoseReferenceFrame("base_link");
    arm_->allowReplanning(true);
    arm_->setGoalPositionTolerance(0.0005);
    arm_->setGoalOrientationTolerance(0.0007);
    joint_names_ = get_joint_names();
    load_joint_limits();
    load_joint_velocity_limits();
}

std::string RobotKinematics::load_urdf_file(const std::string &robot_model_name)
{
    std::string package_share_directory = ament_index_cpp::get_package_share_directory("robot_description");
    std::string urdf_file_path = package_share_directory + "/urdf/" + robot_model_name + ".urdf";
    std::ifstream urdf_file(urdf_file_path);

    if (!urdf_file.is_open())
    {
        RCLCPP_ERROR(node_->get_logger(), "Failed to open URDF file: %s", urdf_file_path.c_str());
        return "";
    }
    std::stringstream urdf_string_stream;
    urdf_string_stream << urdf_file.rdbuf();
    urdf_file.close();

    return urdf_string_stream.str();
}

bool RobotKinematics::init_kdl(const std::string &robot_model_name, const std::string &base_link, const std::string &tip_link)
{
    std::string urdf_str = load_urdf_file(robot_model_name);
    if (urdf_str.empty())
    {
        RCLCPP_ERROR(node_->get_logger(), "URDF string is empty. Cannot initialize KDL.");
        return false;
    }

    // Parse URDF to KDL tree
    if (!kdl_parser::treeFromString(urdf_str, kdl_tree_))
    {
        RCLCPP_ERROR(node_->get_logger(), "Failed to parse URDF into KDL tree.");
        return false;
    }

    // Convert to KDL chain
    if (!kdl_tree_.getChain(base_link, tip_link, kdl_chain_))
    {
        RCLCPP_ERROR(node_->get_logger(), "Failed to extract KDL chain from %s to %s",
                     base_link.c_str(), tip_link.c_str());
        return false;
    }

    // Parse into urdf::Model
    if (!urdf_model_.initString(urdf_str))
    {
        RCLCPP_ERROR(node_->get_logger(), "Failed to parse URDF string into urdf::Model.");
        return false;
    }
    RCLCPP_INFO(node_->get_logger(), "Successfully initialized KDL.");
    return true;
}

void RobotKinematics::setIKMmethod(IKMethod method)
{
    ik_method_ = method;
}

void RobotKinematics::updateJointPositions(const std::vector<double> &joint_positions)
{
    if (joint_positions.size() != kdl_chain_.getNrOfJoints())
    {
        RCLCPP_WARN(node_->get_logger(), "Joint size mismatch: expected %u, got %zu",
                    kdl_chain_.getNrOfJoints(), joint_positions.size());
        return;
    }

    Eigen::VectorXd eigen_joints = Eigen::VectorXd::Map(joint_positions.data(), joint_positions.size());
    current_joint_positions_ = kdl_utils::toKDL(eigen_joints);
}

bool RobotKinematics::computeJacobian(KDL::Jacobian &jacobian_out) const
{
    if (!jacobian_solver_)
    {
        RCLCPP_ERROR(node_->get_logger(), "Jacobian solver not initialized");
        return false;
    }

    if (current_joint_positions_.rows() != static_cast<unsigned int>(kdl_chain_.getNrOfJoints()))
    {
        RCLCPP_ERROR(node_->get_logger(), "Invalid or uninitialized joint positions.");
        return false;
    }

    jacobian_out.resize(kdl_chain_.getNrOfJoints());
    if (jacobian_solver_->JntToJac(current_joint_positions_, jacobian_out) != 0)
    {
        RCLCPP_ERROR(node_->get_logger(), "Failed to compute Jacobian");
        return false;
    }
    return true;
}

bool RobotKinematics::computeJacobian(const KDL::JntArray &joint_positions, KDL::Jacobian &jacobian_out) const
{
    if (!jacobian_solver_)
    {
        RCLCPP_ERROR(node_->get_logger(), "Jacobian solver not initialized");
        return false;
    }

    if (joint_positions.rows() != static_cast<unsigned int>(kdl_chain_.getNrOfJoints()))
    {
        RCLCPP_ERROR(node_->get_logger(), "Invalid joint positions size");
        return false;
    }

    jacobian_out.resize(kdl_chain_.getNrOfJoints());
    if (jacobian_solver_->JntToJac(joint_positions, jacobian_out) != 0)
    {
        RCLCPP_ERROR(node_->get_logger(), "Failed to compute Jacobian");
        return false;
    }
    return true;
}

geometry_msgs::msg::Twist RobotKinematics::generateTwist(Direction direction, double linearSpeed, double angularSpeed)
{
    geometry_msgs::msg::Twist twist_msg;

    switch (direction)
    {
    case Direction::FORWARD:
        twist_msg.linear.x = linearSpeed;
        break;
    case Direction::BACKWARD:
        twist_msg.linear.x = -linearSpeed;
        break;
    case Direction::LEFT:
        twist_msg.linear.y = linearSpeed;
        break;
    case Direction::RIGHT:
        twist_msg.linear.y = -linearSpeed;
        break;
    case Direction::UP:
        twist_msg.linear.z = linearSpeed;
        break;
    case Direction::DOWN:
        twist_msg.linear.z = -linearSpeed;
        break;
    case Direction::ROLL_CW:
        twist_msg.angular.x = angularSpeed;
        break;
    case Direction::ROLL_CCW:
        twist_msg.angular.x = -angularSpeed;
        break;
    case Direction::PITCH_UP:
        twist_msg.angular.y = angularSpeed;
        break;
    case Direction::PITCH_DOWN:
        twist_msg.angular.y = -angularSpeed;
        break;
    case Direction::YAW_LEFT:
        twist_msg.angular.z = angularSpeed;
        break;
    case Direction::YAW_RIGHT:
        twist_msg.angular.z = -angularSpeed;
        break;
    default:
        break;
    }
    return twist_msg;
}

bool RobotKinematics::moveToPose(const geometry_msgs::msg::Pose &targetPose)
{
    std::vector<geometry_msgs::msg::Pose> waypoints;
    waypoints.push_back(targetPose);

    moveit_msgs::msg::RobotTrajectory trajectory;

    if (!plan_cartesian_path(waypoints, trajectory))
    {
        RCLCPP_ERROR(node_->get_logger(), "MoveIt failed to plan the Cartesian motion!");
        return false;
    }
    RCLCPP_INFO(node_->get_logger(), "MoveIt successfully planned the Cartesian motion!");
    return execute_plan(trajectory);
}

bool RobotKinematics::moveToJointPositions(const std::vector<double> &target_joint_positions)
{
    RCLCPP_INFO(node_->get_logger(), "Moving to joint positions: %f, %f, %f, %f, %f, %f",
                target_joint_positions[0], target_joint_positions[1], target_joint_positions[2],
                target_joint_positions[3], target_joint_positions[4], target_joint_positions[5]);
    arm_->setJointValueTarget(target_joint_positions);
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    bool result = (arm_->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
    if (result)
    {
        arm_->execute(plan);
    }
    else
    {
        RCLCPP_ERROR(node_->get_logger(), "Joint motion planning failed.");
    }
    return result;
}

std::vector<geometry_msgs::msg::Pose> RobotKinematics::generate_movec_waypoints(
    const geometry_msgs::msg::Pose &start_pose,
    const geometry_msgs::msg::Pose &mid_pose,
    const geometry_msgs::msg::Pose &goal_pose,
    bool must_pass_through_middle,
    int num_points)
{
    std::vector<geometry_msgs::msg::Pose> waypoints;
    tf2::Quaternion start_q, mid_q, goal_q;
    tf2::fromMsg(start_pose.orientation, start_q);
    tf2::fromMsg(mid_pose.orientation, mid_q);
    tf2::fromMsg(goal_pose.orientation, goal_q);

    if (must_pass_through_middle)
    {
        geometry_msgs::msg::Point assist_point;
        assist_point.x = start_pose.position.x + 0.4 * (mid_pose.position.x - start_pose.position.x);
        assist_point.y = start_pose.position.y + 0.4 * (mid_pose.position.y - start_pose.position.y);
        assist_point.z = start_pose.position.z + 0.4 * (mid_pose.position.z - start_pose.position.z);

        for (int i = 0; i < num_points / 2; ++i)
        {
            double t = static_cast<double>(i) / (num_points / 2);
            geometry_msgs::msg::Pose pose;
            pose.position.x = pow(1 - t, 2) * start_pose.position.x + 2 * (1 - t) * t * assist_point.x + pow(t, 2) * mid_pose.position.x;
            pose.position.y = pow(1 - t, 2) * start_pose.position.y + 2 * (1 - t) * t * assist_point.y + pow(t, 2) * mid_pose.position.y;
            pose.position.z = pow(1 - t, 2) * start_pose.position.z + 2 * (1 - t) * t * assist_point.z + pow(t, 2) * mid_pose.position.z;
            pose.orientation = tf2::toMsg(start_q.slerp(mid_q, t));
            waypoints.push_back(pose);
        }

        for (int i = 1; i <= num_points / 2; ++i)
        {
            double t = static_cast<double>(i) / (num_points / 2);
            geometry_msgs::msg::Pose pose;
            pose.position.x = (1 - t) * mid_pose.position.x + t * goal_pose.position.x;
            pose.position.y = (1 - t) * mid_pose.position.y + t * goal_pose.position.y;
            pose.position.z = (1 - t) * mid_pose.position.z + t * goal_pose.position.z;
            pose.orientation = tf2::toMsg(mid_q.slerp(goal_q, t));
            waypoints.push_back(pose);
        }
    }
    else
    {
        for (int i = 0; i < num_points; ++i)
        {
            double t = static_cast<double>(i) / num_points;
            geometry_msgs::msg::Pose pose;
            pose.position.x = pow(1 - t, 2) * start_pose.position.x + 2 * (1 - t) * t * mid_pose.position.x + pow(t, 2) * goal_pose.position.x;
            pose.position.y = pow(1 - t, 2) * start_pose.position.y + 2 * (1 - t) * t * mid_pose.position.y + pow(t, 2) * goal_pose.position.y;
            pose.position.z = pow(1 - t, 2) * start_pose.position.z + 2 * (1 - t) * t * mid_pose.position.z + pow(t, 2) * goal_pose.position.z;
            pose.orientation = tf2::toMsg(start_q.slerp(goal_q, t));
            waypoints.push_back(pose);
        }
    }
    return waypoints;
}

robot_interfaces::msg::RobotControlMsg RobotKinematics::motor_disable(uint8_t joint_idx)
{
    robot_interfaces::msg::RobotControlMsg control_msg;
    control_msg.motor_enable_flag.resize(MOTOR_NUM);
    control_msg.motor_mode.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::POSITION_ABS_MODE);
    control_msg.position.assign(MOTOR_NUM, 0.0f);
    control_msg.velocity.assign(MOTOR_NUM, 0.0f);
    control_msg.effort.assign(MOTOR_NUM, 0.0f);

    for (uint8_t i = 0; i < MOTOR_NUM; i++)
    {
        if (i != joint_idx - 1)
        {
            control_msg.motor_enable_flag[i] = robot_interfaces::msg::RobotControlMsg::MOTOR_ENABLE;
        }
        else
        {
            control_msg.motor_enable_flag[i] = robot_interfaces::msg::RobotControlMsg::MOTOR_DISABLE;
        }
    }
    return control_msg;
}

robot_interfaces::msg::RobotControlMsg RobotKinematics::motor_disable()
{
    robot_interfaces::msg::RobotControlMsg control_msg;
    control_msg.motor_enable_flag.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::MOTOR_DISABLE);
    control_msg.motor_mode.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::EFFORT_POSITION_MODE);
    control_msg.position.assign(MOTOR_NUM, 0.0f);
    control_msg.velocity.assign(MOTOR_NUM, 0.0f);
    control_msg.effort.assign(MOTOR_NUM, 0.0f);
    return control_msg;
}

robot_interfaces::msg::RobotControlMsg RobotKinematics::generate_joint_velocity_command(uint8_t joint_idx, float velocity)
{
    robot_interfaces::msg::RobotControlMsg control_msg;
    control_msg.motor_enable_flag.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::MOTOR_ENABLE);
    control_msg.motor_mode.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::SPEED_MODE);
    control_msg.velocity.resize(MOTOR_NUM, 0.0f);
    if (joint_idx >= MOTOR_NUM)
    {
        // RCLCPP_ERROR(node_->get_logger(), "Invalid joint index: %d", joint_idx);
        return control_msg;
    }
    control_msg.velocity[joint_idx] = velocity;
    control_msg.position.clear();
    control_msg.effort.clear();
    return control_msg;
}

robot_interfaces::msg::RobotControlMsg RobotKinematics::generate_joint_velocity_command(const std::vector<double> &velocities)
{
    robot_interfaces::msg::RobotControlMsg control_msg;
    if (velocities.size() != MOTOR_NUM)
    {
        // RCLCPP_ERROR(node_->get_logger(), "Invalid number of velocities: %lu", velocities.size());
        return control_msg;
    }
    control_msg.motor_enable_flag.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::MOTOR_ENABLE);
    control_msg.motor_mode.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::SPEED_MODE);
    control_msg.velocity.resize(MOTOR_NUM, 0.0f);
    control_msg.velocity = velocities;
    control_msg.position.clear();
    control_msg.effort.clear();
    return control_msg;
}

robot_interfaces::msg::RobotControlMsg RobotKinematics::robotic_arm_move_stop(uint8_t motor_mode)
{
    robot_interfaces::msg::RobotControlMsg control_msg;
    control_msg.motor_enable_flag.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::MOTOR_ENABLE);
    if (motor_mode == robot_interfaces::msg::RobotControlMsg::SPEED_MODE)
    {
        control_msg.motor_mode.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::SPEED_MODE);
        control_msg.velocity.assign(MOTOR_NUM, 0.0f);
        control_msg.position.clear();
        control_msg.effort.clear();
    }
    else if (motor_mode == robot_interfaces::msg::RobotControlMsg::POSITION_ABS_MODE)
    {
        control_msg.motor_mode.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::POSITION_ABS_MODE);
    }
    return control_msg;
}

robot_interfaces::msg::RobotControlMsg RobotKinematics::generate_joint_position_command(uint8_t joint_idx, float position)
{
    robot_interfaces::msg::RobotControlMsg control_msg;
    control_msg.motor_enable_flag.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::MOTOR_ENABLE);
    control_msg.motor_mode.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::POSITION_ABS_MODE);
    control_msg.position.resize(MOTOR_NUM, 0.0f);
    if (joint_idx >= MOTOR_NUM)
    {
        RCLCPP_ERROR(node_->get_logger(), "Invalid joint index: %d", joint_idx);
        return control_msg;
    }
    control_msg.position[joint_idx] = position;
    control_msg.velocity.clear();
    control_msg.effort.clear();
    return control_msg;
}

robot_interfaces::msg::RobotControlMsg RobotKinematics::generate_joint_position_command(const std::vector<double> &positions)
{
    robot_interfaces::msg::RobotControlMsg control_msg;
    control_msg.motor_enable_flag.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::MOTOR_ENABLE);
    control_msg.motor_mode.assign(MOTOR_NUM, robot_interfaces::msg::RobotControlMsg::POSITION_ABS_MODE);
    control_msg.position.resize(MOTOR_NUM, 0.0f);
    control_msg.position = positions;
    control_msg.velocity.clear();
    control_msg.effort.clear();
    return control_msg;
}

bool RobotKinematics::move_in_line(const geometry_msgs::msg::Pose &current_pose, Direction direction, double delta_pos)
{
    geometry_msgs::msg::Pose target_pose = current_pose;
    switch (direction)
    {
    case Direction::FORWARD:
        target_pose.position.x += delta_pos;
        break;
    case Direction::BACKWARD:
        target_pose.position.x -= delta_pos;
        break;
    case Direction::LEFT:
        target_pose.position.y += delta_pos;
        break;
    case Direction::RIGHT:
        target_pose.position.y -= delta_pos;
        break;
    case Direction::UP:
        target_pose.position.z += delta_pos;
        break;
    case Direction::DOWN:
        target_pose.position.z -= delta_pos;
        break;
    default:
        return false;
    }
    return moveToPose(target_pose);
}

bool RobotKinematics::move_in_orientation(const geometry_msgs::msg::Pose &current_pose, Direction direction, double delta_angle)
{
    geometry_msgs::msg::Pose target_pose = current_pose;
    tf2::Quaternion q;
    switch (direction)
    {
    case Direction::ROLL_CW:
        q.setRPY(delta_angle, 0, 0);
        break;
    case Direction::ROLL_CCW:
        q.setRPY(-delta_angle, 0, 0);
        break;
    case Direction::PITCH_UP:
        q.setRPY(0, delta_angle, 0);
        break;
    case Direction::PITCH_DOWN:
        q.setRPY(0, -delta_angle, 0);
        break;
    case Direction::YAW_LEFT:
        q.setRPY(0, 0, delta_angle);
        break;
    case Direction::YAW_RIGHT:
        q.setRPY(0, 0, -delta_angle);
        break;
    default:
        return false;
    }
    tf2::Quaternion q_current;
    tf2::fromMsg(current_pose.orientation, q_current);
    tf2::Quaternion q_target = q * q_current;
    q_target.normalize();
    target_pose.orientation = tf2::toMsg(q_target);

    return moveToPose(target_pose);
}

bool RobotKinematics::plan_cartesian_path(const std::vector<geometry_msgs::msg::Pose> &waypoints, moveit_msgs::msg::RobotTrajectory &trajectory)
{
    const double jump_threshold = 0.0;
    const double eef_step = 0.01;
    double fraction = arm_->computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
    return fraction > 0.9;
}

bool RobotKinematics::execute_plan(const moveit_msgs::msg::RobotTrajectory &trajectory)
{
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    plan.trajectory_ = trajectory;
    moveit::core::MoveItErrorCode result = arm_->execute(plan);
    return bool(result);
}

bool RobotKinematics::plan_and_execute_cartesian_path(const std::vector<geometry_msgs::msg::Pose> &waypoints)
{
    moveit_msgs::msg::RobotTrajectory trajectory;
    if (!plan_cartesian_path(waypoints, trajectory))
    {
        RCLCPP_ERROR(node_->get_logger(), "Failed to plan Cartesian path through waypoints!");
        return false;
    }
    return execute_plan(trajectory);
}

void RobotKinematics::load_joint_limits()
{
    std::string robot_model_name;
    node_->get_parameter("robot_model_name", robot_model_name);

    std::string urdf_content = load_urdf_file(robot_model_name);

    if (urdf_content.empty())
    {
        RCLCPP_ERROR(node_->get_logger(), "URDF content is empty. Cannot load joint limits.");
        return;
    }

    urdf::Model model;
    if (!model.initString(urdf_content))
    {
        RCLCPP_ERROR(node_->get_logger(), "Failed to parse URDF file.");
        return;
    }

    joint_limits_.clear();
    for (const auto &joint_pair : model.joints_)
    {
        const auto &joint = joint_pair.second;
        if (joint->type == urdf::Joint::REVOLUTE)
        {
            if (joint->limits)
            {
                joint_limits_[joint->name] = {joint->limits->lower, joint->limits->upper};
                RCLCPP_INFO(node_->get_logger(), "Loaded limit for joint [%s]: [%f, %f]",
                            joint->name.c_str(), joint->limits->lower, joint->limits->upper);
            }
        }
    }
}

void RobotKinematics::load_joint_velocity_limits()
{
    std::string robot_model_name;
    node_->get_parameter("robot_model_name", robot_model_name);

    std::string urdf_content = load_urdf_file(robot_model_name);
    if (urdf_content.empty())
    {
        RCLCPP_ERROR(node_->get_logger(), "URDF content is empty. Cannot load joint velocity limits.");
        return;
    }

    urdf::Model model;
    if (!model.initString(urdf_content))
    {
        RCLCPP_ERROR(node_->get_logger(), "Failed to parse URDF file.");
        return;
    }

    joint_velocity_limits_.clear();
    for (const auto &joint_pair : model.joints_)
    {
        const auto &joint = joint_pair.second;
        if (joint->type == urdf::Joint::REVOLUTE || joint->type == urdf::Joint::PRISMATIC || joint->type == urdf::Joint::CONTINUOUS)
        {
            joint_velocity_limits_[joint->name] = joint->limits->velocity;
            RCLCPP_INFO(node_->get_logger(), "Loaded velocity limit for joint [%s]: [%f]",
                        joint->name.c_str(), joint->limits->velocity);
        }
    }
}

const std::map<std::string, std::pair<double, double>> &RobotKinematics::get_joint_limits() const
{
    return joint_limits_;
}

std::vector<std::string> RobotKinematics::get_joint_names() const
{
    return arm_->getJointNames();
}

geometry_msgs::msg::Pose RobotKinematics::get_current_pose() const
{
    return arm_->getCurrentPose().pose;
}
void RobotKinematics::speed_config_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    RCLCPP_INFO(node_->get_logger(),
                "Updated speed_scaling,accel_scaling");
    double speed_scaling_ = std::clamp(msg->data[0], 0.1, 1.0);
    double accel_scaling_ = std::clamp(msg->data[1], 0.1, 1.0);

    arm_->setMaxVelocityScalingFactor(speed_scaling_);
    arm_->setMaxAccelerationScalingFactor(accel_scaling_);

    RCLCPP_INFO(node_->get_logger(),
                "Updated speed_scaling=%.2f, accel_scaling=%.2f",
                speed_scaling_, accel_scaling_);
}