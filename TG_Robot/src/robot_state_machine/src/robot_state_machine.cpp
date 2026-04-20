#include "robot_state_machine.hpp"

StateMachine::StateMachine(std::string node_name) : Node(node_name), qos(10)
{
    kinematics_ = std::make_shared<RobotKinematics>();
    current_mode_ = 0;
    playback_stop_flag_ = false;
    qos.reliable();
    // arm = std::make_shared<moveit::planning_interface::MoveGroupInterface>(rclcpp::Node::SharedPtr(this), std::string("arm"));
    mode_sub = this->create_subscription<std_msgs::msg::UInt8>("robotic_arm_control_mode", qos, std::bind(&StateMachine::working_mode_callback, this, std::placeholders::_1));
    jointctrl_sub_ = this->create_subscription<robot_interfaces::msg::KeyPressedAction>("jointctrl_action", qos, std::bind(&StateMachine::jointctrl_action_callback, this, std::placeholders::_1));
    cartesian_sub_ = this->create_subscription<robot_interfaces::msg::KeyPressedAction>("cartesian_action", qos, std::bind(&StateMachine::cartesian_action_callback, this, std::placeholders::_1));
    movej_sub_ = this->create_subscription<std_msgs::msg::Float64MultiArray>("movej_action", qos, std::bind(&StateMachine::movej_action_callback, this, std::placeholders::_1));
    movel_sub_ = this->create_subscription<std_msgs::msg::Float64MultiArray>("movel_action", qos, std::bind(&StateMachine::movel_action_callback, this, std::placeholders::_1));
    movec_sub_ = this->create_subscription<robot_interfaces::msg::MoveCAction>("movec_action", qos, std::bind(&StateMachine::movec_action_callback, this, std::placeholders::_1));
    teach_sub_ = this->create_subscription<std_msgs::msg::String>("teach_action", qos, std::bind(&StateMachine::teach_action_callback, this, std::placeholders::_1));
    gripper_sub_ = this->create_subscription<robot_interfaces::msg::GripperControl>("gripper_action", qos, std::bind(&StateMachine::gripper_action_callback, this, std::placeholders::_1));
    teachrepeat_sub_ = this->create_subscription<std_msgs::msg::String>("teachrepeat_action", qos, std::bind(&StateMachine::teach_repeat_callback, this, std::placeholders::_1));
    state_sd_sub_ = this->create_subscription<robot_interfaces::msg::StateAction>("sd_state_action", qos, std::bind(&StateMachine::save_delete_state_callback, this, std::placeholders::_1));
    state_load_sub_ = this->create_subscription<std_msgs::msg::String>("loadstate_action", qos, std::bind(&StateMachine::load_state_callback, this, std::placeholders::_1));
    joint_states_sub_ = this->create_subscription<sensor_msgs::msg::JointState>("joint_states", 10, std::bind(&StateMachine::joint_states_callback, this, std::placeholders::_1));
    usr_param_sub_ = this->create_subscription<robot_interfaces::msg::GenericMotorParameter>("usr_param_set", 10, std::bind(&StateMachine::usr_param_callback, this, std::placeholders::_1));
    angular_vel_sub_ = this->create_subscription<std_msgs::msg::Float64MultiArray>("joint_velocity", qos, std::bind(&StateMachine::angular_vel_callback, this, std::placeholders::_1));

    debug_param_msg_pub = this->create_publisher<robot_interfaces::msg::GenericMotorParameter>("debug_parameter_cmd", 10);
    motor_msg_pub = this->create_publisher<robot_interfaces::msg::RobotControlMsg>("motor_control_msg", 10);
    usr_param_pub = this->create_publisher<robot_interfaces::msg::GenericMotorParameter>("motor_parameter_cmd", 10);
    gripper_msg_pub = this->create_publisher<robot_interfaces::msg::GripperControl>("gripper_control_msg", 10);
    motor_op_pub_ = this->create_publisher<robot_interfaces::msg::GenericMotorOperation>("motor_operation_cmd", 10);
    button_states_pub = this->create_publisher<std_msgs::msg::UInt8>("button_status_cmd", 10);
    cer_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cartesian_velocity_cmd", 10);
    client_ = rclcpp_action::create_client<FollowJointTrajectory>(this, "/arm_controller/follow_joint_trajectory");
    raw_traj_pub_ = this->create_publisher<trajectory_msgs::msg::JointTrajectory>(
        "/raw_joint_trajectory", 10);

    // current_count_ = 0;
    recording_ = false;
    teach_bag_writer_ = nullptr;
    play_bag_reader_ = nullptr;
    velocities = std::vector<double>(6, 0.0);
    JointRecorder recorder_(100.0); // 100Hz 录制频率
}

void StateMachine::post_init()
{
    kinematics_->initialize(shared_from_this()); // 安全地使用 shared_from_this()
}

void StateMachine::joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
{
    if (msg->effort.size() < 6 || msg->position.size() < 6)
    {
        RCLCPP_WARN(this->get_logger(), "JointStates data in complete! Expected 6, got effort: %zu, position: %zu", msg->effort.size(), msg->position.size());
        return;
    }
    latest_joint_states_ = msg;

    if (recorder_.isRecording())
    {
        recorder_.enqueue(latest_joint_states_);
    }
}

void StateMachine::working_mode_callback(const std_msgs::msg::UInt8::SharedPtr msg)
{
    current_mode_ = msg->data;
    switch (current_mode_)
    {
    case BACKTOSTART:
    { // 回到初始位置
        std::vector<double> target_joint_positions = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
        kinematics_->moveToJointPositions(target_joint_positions);
        break;
    }
    case DISABLE:
    {
        auto motor_control_msg = kinematics_->motor_disable();
        motor_msg_pub->publish(motor_control_msg);
        break;
    }
    case TEACH:
    { // 记录轨迹，可以通过键盘给定机械臂六个关节的期望位置
        RCLCPP_INFO(this->get_logger(), "Robot arm is at TEACH mode!");
        gravity_sub = this->create_subscription<sensor_msgs::msg::JointState>("gravity_torque", 10, std::bind(&StateMachine::gravity_callback, this, std::placeholders::_1));
        break;
    }
    
    case BACKTOINITIAL:
    { // 回到开始运动的初始位置
        std::vector<double> target_joint_positions = {0.0f, 0.43633f, 0.43633f, 0.0f, 0.0f, 0.0f};
        kinematics_->moveToJointPositions(target_joint_positions);
        break;
    }
    case MOTORZEROPOSSET:
    {
        motor_op_msg.op_code = static_cast<uint8_t>(motor_driver::FuncOpCode::MOTOR_ZERO_POS_SET);
        for (int i = 1; i <= 6; i++)
        {
            motor_op_msg.motor_id = i;
            motor_op_pub_->publish(motor_op_msg);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        break;
    }
    default:
        break;
    }
    RCLCPP_INFO(this->get_logger(), "Current mode is %d", current_mode_);
}

void StateMachine::jointctrl_motor_mode(const uint8_t joint_index, const float speed)
{

    float command_speed = 0.0f;
    const auto &joint_names = kinematics_->get_joint_names();
    const auto &joint_limits = kinematics_->get_joint_limits();

    if (latest_joint_states_ && joint_index < latest_joint_states_->position.size())
    {
        const std::string &joint_name = joint_names[joint_index];
        double position = latest_joint_states_->position[joint_index];
        auto it = joint_limits.find(joint_name);
        if (it != joint_limits.end())
        {
            double lower_limit = it->second.first + 0.05236;
            double upper_limit = it->second.second - 0.05236;
            if (position < lower_limit && speed < 0.0f)
            {
                command_speed = 0.0f;
            }
            else if (position > upper_limit && speed > 0.0f)
            {
                command_speed = 0.0f;
            }
            else
            {
                command_speed = speed;
            }
        }
    }

    auto motor_control_msg = kinematics_->generate_joint_velocity_command(joint_index, command_speed);
    motor_msg_pub->publish(motor_control_msg);

    RCLCPP_INFO(this->get_logger(), "Joint %d speed command: %.3f", joint_index + 1, command_speed);
}

void StateMachine::jointctrl_thread()
{
    jointctrl_thread_running_ = true;
    RCLCPP_INFO(this->get_logger(), "Joint control thread started...");
    while (!stop_jointctrl_thread_)
    {
        jointctrl_motor_mode(active_joint_index_, active_joint_speed_);
        RCLCPP_INFO(this->get_logger(), "Joint %d speed command: %.3f", active_joint_index_ + 1, active_joint_speed_);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 每 100ms 发一次
    }
    jointctrl_motor_mode(active_joint_index_, 0.0f);
    jointctrl_thread_running_ = false;
    RCLCPP_INFO(this->get_logger(), "Joint control thread exited.");
}

void StateMachine::jointctrl_action_callback(const robot_interfaces::msg::KeyPressedAction::SharedPtr msg)
{

    if (current_mode_ != JOINTCONTROL)
        return;
    std::lock_guard<std::mutex> lock(jointctrl_mutex_);

    if (msg->is_pressed == true)
    {
        if (!jointctrl_thread_running_)
        {
            active_joint_index_ = (msg->key_code - JOINT1_POSITIVE) / 2;
            active_joint_speed_ = (msg->key_code & 1) ? JOINT_ROTATE_POSITIVE_SPEED : JOINT_ROTATE_NEGATIVE_SPEED;

            stop_jointctrl_thread_ = false;
            jointctrl_thread_ = std::thread(&StateMachine::jointctrl_thread, this);
            jointctrl_thread_.detach();

            RCLCPP_INFO(this->get_logger(), "Joint %d rotate %s", active_joint_index_ + 1,
                        (msg->key_code & 1) ? "positive" : "negative");
        }
    }
    else
    {
        stop_jointctrl_thread_ = true;
        RCLCPP_INFO(this->get_logger(), "Joint control stop requested.");
    }
}
void StateMachine::angular_vel_callback(const std_msgs::msg::Float64MultiArray vel_msg)
{
    if (current_mode_ != CARTESIAN)
        return;
    std::lock_guard<std::mutex> lock(velocities_mutex_);
    velocities = vel_msg.data;
}
void StateMachine::cartesian_move_thread()
{

    cartesian_thread_running_ = true;
    RCLCPP_INFO(this->get_logger(), "Cartesian move thread started...");
    rclcpp::Rate rate(50);
    while (!stop_cartesian_thread_)
    {
        if (!latest_joint_states_)
        {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                                 "No joint_states received yet.");
            rate.sleep();
            continue;
        }
        if (active_twist_direction_ == Direction::NONE)
        {
            rate.sleep();
            continue;
        }
        // 1. 从键盘动作生成 Twist
        geometry_msgs::msg::Twist twist = kinematics_->generateTwist(active_twist_direction_);
        cer_vel_pub_->publish(twist);

        // 2. 读取 velocities 并生成电机控制消息
        std::vector<double> current_velocities;
        {
            std::lock_guard<std::mutex> lock(velocities_mutex_);
            current_velocities = velocities;
        }

        // 3. 发布消息控制电机
        auto motor_control_msg = kinematics_->generate_joint_velocity_command(current_velocities);
        motor_msg_pub->publish(motor_control_msg);
        RCLCPP_INFO(this->get_logger(), "Publishing motor velocity control message: %lf, %lf, %lf, %lf, %lf, %lf",
                    motor_control_msg.velocity[0], motor_control_msg.velocity[1], motor_control_msg.velocity[2],
                    motor_control_msg.velocity[3], motor_control_msg.velocity[4], motor_control_msg.velocity[5]);

        rate.sleep();
    }

    auto motor_control_msg = kinematics_->robotic_arm_move_stop(robot_interfaces::msg::RobotControlMsg::SPEED_MODE);
    motor_msg_pub->publish(motor_control_msg);
    RCLCPP_INFO(this->get_logger(), "Publishing motor velocity control message: %lf, %lf, %lf, %lf, %lf, %lf",
                motor_control_msg.velocity[0], motor_control_msg.velocity[1], motor_control_msg.velocity[2],
                motor_control_msg.velocity[3], motor_control_msg.velocity[4], motor_control_msg.velocity[5]);

    cartesian_thread_running_ = false;
    RCLCPP_INFO(this->get_logger(), "Cartesian move thread exited.");
}

void StateMachine::cartesian_action_callback(const robot_interfaces::msg::KeyPressedAction::SharedPtr msg)
{
    if (current_mode_ != CARTESIAN)
        return;
    std::lock_guard<std::mutex> lock(cartesian_mutex_);
    if (msg->is_pressed)
    {
        Direction new_direction = static_cast<Direction>(msg->key_code);
        if (!cartesian_thread_running_)
        {
            active_twist_direction_ = new_direction;
            stop_cartesian_thread_ = false;
            cartesian_thread_ = std::thread(&StateMachine::cartesian_move_thread, this);
            cartesian_thread_.detach();
            RCLCPP_INFO(this->get_logger(), "Cartesian move started, direction: %d", static_cast<int>(new_direction));
        }
    }
    else
    {
        stop_cartesian_thread_ = true;
        RCLCPP_INFO(this->get_logger(), "Stop requesting for Cartesian move.");
    }
}

void StateMachine::movej_action_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    if (current_mode_ != MOVEJ)
        return;
    RCLCPP_INFO(this->get_logger(), "Movej action received.");
    if (msg->data.size() % 6 != 0)
    {
        RCLCPP_ERROR(this->get_logger(), "Error input joint angle values!");
        return;
    }
    size_t group_count = msg->data.size() / 6;
    for (size_t i = 0; i < group_count; ++i)
    {
        std::vector<double> joint_values(msg->data.begin() + i * 6, msg->data.begin() + (i + 1) * 6);

        const auto &joint_names = kinematics_->get_joint_names();
        const auto &joint_limits = kinematics_->get_joint_limits();

        bool is_valid = true;
        for (size_t j = 0; j < joint_values.size(); ++j)
        {
            const std::string &joint_name = joint_names[j];
            auto it = joint_limits.find(joint_name);
            if (it != joint_limits.end())
            {
                double val = joint_values[j] * M_PI / 180.0;
                if (val < it->second.first || val > it->second.second)
                {
                    RCLCPP_ERROR(this->get_logger(), "Joint %s value %f out of range [%.2f, %.2f]",
                                 joint_name.c_str(), val, it->second.first, it->second.second);
                    is_valid = false;
                    break;
                }
                else
                {
                    joint_values[j] = val;
                }
            }
        }
        if (!is_valid)
        {
            RCLCPP_WARN(this->get_logger(), "Skipping invalid joint group %zu", i + 1);
            continue;
        }
        bool success = kinematics_->moveToJointPositions(joint_values);
        if (!success)
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to move to joint group %zu", i + 1);
            continue; // 不中断执行，如需中断，改为break
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Joint group %zu moved successfully", i + 1);
        }
    }
}

void StateMachine::movel_action_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    if (current_mode_ != MOVEL)
        return;
    if (msg->data.size() % 6 != 0)
    {
        RCLCPP_ERROR(this->get_logger(), "Error input pose values!");
        return;
    }

    for (size_t i = 0; i < msg->data.size() / 6; ++i)
    {
        geometry_msgs::msg::Pose target_pose;
        size_t idx = i * 6;
        target_pose.position.x = msg->data[idx];
        target_pose.position.y = msg->data[idx + 1];
        target_pose.position.z = msg->data[idx + 2];

        double roll = msg->data[idx + 3] * M_PI / 180.0;
        double pitch = msg->data[idx + 4] * M_PI / 180.0;
        double yaw = msg->data[idx + 5] * M_PI / 180.0;

        tf2::Quaternion q;
        q.setRPY(roll, pitch, yaw);
        target_pose.orientation = tf2::toMsg(q);

        RCLCPP_INFO(this->get_logger(), "Moving to pose %zu...", i + 1);
        bool success = kinematics_->moveToPose(target_pose);
        if (!success)
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to move to pose %zu", i + 1);
            break; // 或根据业务需求继续执行剩下的点
        }
    }
}

void StateMachine::movec_action_callback(const robot_interfaces::msg::MoveCAction::SharedPtr msg)
{
    if (current_mode_ != MOVEC)
        return;
    auto pose_array = msg->pose_array;
    auto must_pass_through_middle = msg->must_pass_through_middle;

    if (pose_array.data.size() != 12)
    {
        RCLCPP_ERROR(this->get_logger(), "Error input pose values!");
        return;
    }

    geometry_msgs::msg::Pose mid_pose, goal_pose;
    tf2::Quaternion q;

    mid_pose.position.x = pose_array.data[0];
    mid_pose.position.y = pose_array.data[1];
    mid_pose.position.z = pose_array.data[2];
    q.setRPY(pose_array.data[3], pose_array.data[4], pose_array.data[5]);
    mid_pose.orientation = tf2::toMsg(q);

    goal_pose.position.x = pose_array.data[6];
    goal_pose.position.y = pose_array.data[7];
    goal_pose.position.z = pose_array.data[8];
    q.setRPY(pose_array.data[9], pose_array.data[10], pose_array.data[11]);
    goal_pose.orientation = tf2::toMsg(q);

    geometry_msgs::msg::Pose current_pose = kinematics_->get_current_pose();
    auto waypoints = kinematics_->generate_movec_waypoints(current_pose, mid_pose, goal_pose, must_pass_through_middle);

    if (!kinematics_->plan_and_execute_cartesian_path(waypoints))
    {
        RCLCPP_ERROR(this->get_logger(), "Error in cartesian path planning and execution!");
    }
}

void StateMachine::gravity_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
{
    if (current_mode_ != TEACH)
        return;
    robot_interfaces::msg::RobotControlMsg rbt_ctrl_msg;
    rbt_ctrl_msg.motor_enable_flag.resize(6, 0);
    rbt_ctrl_msg.motor_mode.resize(6, 0.0);
    rbt_ctrl_msg.velocity.resize(6, 0.0);
    rbt_ctrl_msg.effort.resize(6, 0.0);
    rbt_ctrl_msg.kp.resize(6, 0);
    rbt_ctrl_msg.kd.resize(6, 0);
    for (size_t i = 0; i < rbt_ctrl_msg.motor_mode.size(); ++i)
    {
        rbt_ctrl_msg.motor_enable_flag[i] = true;
        rbt_ctrl_msg.motor_mode[i] = EFFORT_POSITION_MODE;
        rbt_ctrl_msg.effort[i] = msg->effort[i];;
        rbt_ctrl_msg.kp[i] = 0;
        rbt_ctrl_msg.kd[i] = 0;
    }
    RCLCPP_ERROR(this->get_logger(), "effort_axis_2: %lf", msg->effort[1]);
    motor_msg_pub->publish(rbt_ctrl_msg);
}

void StateMachine::teach_action_callback(const std_msgs::msg::String::SharedPtr msg)
{
    if ((current_mode_ != TEACH) && (current_mode_ != TEACH_STOP))
        return;
    if (msg->data == "stop")
    {
        recorder_.stop();
        return;
    }

    if (latest_joint_states_ && !recorder_.isRecording())
    {
        std::string txt_file_path = std::string("config/") + msg->data + ".txt";
        recorder_.start(txt_file_path, latest_joint_states_);
    }
}

void StateMachine::teach_repeat_callback(const std_msgs::msg::String::SharedPtr msg)
{
    if (current_mode_ != TEACHREPEAT)
        return;
    if (msg->data == "stop")
    {
        RCLCPP_INFO(this->get_logger(), "Stopping teach repeat...");
        return;
    }
    std::string txt_path = std::string("config/") + msg->data + ".txt";
    if (!std::filesystem::exists(txt_path))
    {
        RCLCPP_ERROR(this->get_logger(), "Trajectory file not found: %s", txt_path.c_str());
        return;
    }
    auto traj_msg = recorder_.repeat(txt_path);
    if (traj_msg.points.empty())
    {
        RCLCPP_ERROR(this->get_logger(), "Trajectory is empty, not sending goal.");
        return;
    }

    // 回到起始位置
    std::vector<double> start_position = traj_msg.points.front().positions;
    bool result = kinematics_->moveToJointPositions(start_position);
    if (result)
    {
        RCLCPP_INFO(this->get_logger(), "Successfully moved to start position.");
    }
    else
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to move to start position!");
    }
    // 等待 action server
    if (!client_->wait_for_action_server(std::chrono::seconds(5)))
    {
        RCLCPP_ERROR(this->get_logger(), "Action server not available.");
        return;
    }

    //  发布轨迹
    raw_traj_pub_->publish(traj_msg);
}

void StateMachine::save_current_state_to_db(const std::string &state_name)
{
    if (!latest_joint_states_ || latest_joint_states_->position.empty())
    {
        RCLCPP_WARN(this->get_logger(), "No joint states received yet!");
        return;
    }
    char *workspace_path = getenv("COLCON_PREFIX_PATH");
    if (!workspace_path)
    {
        RCLCPP_ERROR(this->get_logger(), "COLCON_PREFIX_PATH environment variable not set!");
        return;
    }
    std::filesystem::path ws_path(workspace_path);
    ws_path = ws_path.parent_path();
    std::string config_dir = ws_path.string() + "/config";

    if (!std::filesystem::exists(config_dir))
    {
        std::filesystem::create_directory(config_dir);
    }

    std::string db_path = config_dir + "/robotic_arm_saved_states.db3";

    sqlite3 *db;
    if (sqlite3_open(db_path.c_str(), &db))
    {
        RCLCPP_ERROR(this->get_logger(), "Can't open database: %s", sqlite3_errmsg(db));
        return;
    }

    // 创建表（如果不存在）
    const char *create_table_sql =
        "CREATE TABLE IF NOT EXISTS saved_states ("
        "name TEXT PRIMARY KEY, "
        "joints TEXT"
        ");";
    char *errmsg;
    if (sqlite3_exec(db, create_table_sql, nullptr, nullptr, &errmsg) != SQLITE_OK)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to create table: %s", errmsg);
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return;
    }

    // 把关节角度数组转成字符串
    std::ostringstream joints_stream;
    for (size_t i = 0; i < latest_joint_states_->position.size(); ++i)
    {
        joints_stream << latest_joint_states_->position[i];
        if (i != latest_joint_states_->position.size() - 1)
        {
            joints_stream << ",";
        }
    }
    std::string joints_str = joints_stream.str();

    // 插入或替换
    std::string insert_sql = "INSERT OR REPLACE INTO saved_states (name, joints) VALUES (?, ?);";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, insert_sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to prepare insert statement: %s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, state_name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, joints_str.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to insert data: %s", sqlite3_errmsg(db));
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "Saved current joint state as '%s' into database!", state_name.c_str());
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void StateMachine::delete_state_from_db(const std::string &state_name)
{
    char *workspace_path = getenv("COLCON_PREFIX_PATH");
    if (!workspace_path)
    {
        RCLCPP_ERROR(this->get_logger(), "COLCON_PREFIX_PATH environment variable not set!");
        return;
    }
    std::filesystem::path ws_path(workspace_path);
    ws_path = ws_path.parent_path();
    std::string config_dir = ws_path.string() + "/config";
    if (!std::filesystem::exists(config_dir))
    {
        RCLCPP_ERROR(this->get_logger(), "Config directory does not exist!");
    }
    std::string db_path = config_dir + "/robotic_arm_saved_states.db3";

    sqlite3 *db;
    if (sqlite3_open(db_path.c_str(), &db))
    {
        RCLCPP_ERROR(this->get_logger(), "Can't open database: %s", sqlite3_errmsg(db));
        return;
    }

    std::string delete_sql = "DELETE FROM saved_states WHERE name = ?;";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, delete_sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to prepare delete statement: %s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, state_name.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to delete state '%s': %s", state_name.c_str(), sqlite3_errmsg(db));
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "Deleted state '%s' from database.", state_name.c_str());
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void StateMachine::save_delete_state_callback(const robot_interfaces::msg::StateAction::SharedPtr msg)
{
    if (current_mode_ != STATEOPERATION)
        return;
    if (msg->operation_mode == robot_interfaces::msg::StateAction::SAVE)
    {
        if (msg->state_name.empty())
        {
            RCLCPP_ERROR(this->get_logger(), "Received empty state name, ignoring save/delete request.");
            return;
        }
        save_current_state_to_db(msg->state_name);
    }
    else if (msg->operation_mode == robot_interfaces::msg::StateAction::DELETE)
    {
        delete_state_from_db(msg->state_name);
    }
    else
    {
        RCLCPP_ERROR(this->get_logger(), "Unknown operation mode: %d", msg->operation_mode);
    }
}

void StateMachine::load_state_from_db(const std::string &state_name)
{
    char *workspace_path = getenv("COLCON_PREFIX_PATH");
    if (!workspace_path)
    {
        RCLCPP_ERROR(this->get_logger(), "COLCON_PREFIX_PATH environment variable not set! Cannot determine workspace location.");
        return;
    }

    std::filesystem::path ws_path(workspace_path);
    ws_path = ws_path.parent_path();
    std::string config_dir = ws_path.string() + "/config";
    std::string db_path = config_dir + "/robotic_arm_saved_states.db3";

    sqlite3 *db;
    if (sqlite3_open(db_path.c_str(), &db))
    {
        RCLCPP_ERROR(this->get_logger(), "Can't open database: %s", sqlite3_errmsg(db));
        return;
    }

    std::string query_sql = "SELECT joints FROM saved_states WHERE name = ?;";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query_sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to prepare select statement: %s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, state_name.c_str(), -1, SQLITE_TRANSIENT);

    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
    {
        const unsigned char *joints_text = sqlite3_column_text(stmt, 0);
        if (joints_text)
        {
            std::string joints_str(reinterpret_cast<const char *>(joints_text));
            std::vector<double> joint_positions;
            std::stringstream ss(joints_str);
            std::string token;
            while (std::getline(ss, token, ','))
            {
                joint_positions.push_back(std::stod(token));
            }

            if (joint_positions.size() != 6)
            {
                RCLCPP_WARN(this->get_logger(), "Loaded joint positions size mismatch! Expected 6, got %zu", joint_positions.size());
            }
            else
            {
                // 成功加载，可以赋值到 current_joint_positions_
                kinematics_->moveToJointPositions(joint_positions);
                RCLCPP_INFO(this->get_logger(), "Successfully loaded state '%s'!", state_name.c_str());
            }
        }
    }
    else
    {
        RCLCPP_WARN(this->get_logger(), "State '%s' not found in database!", state_name.c_str());
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void StateMachine::load_state_callback(const std_msgs::msg::String::SharedPtr msg)
{
    if (current_mode_ != LOADSTATE)
        return;
    if (msg->data.empty())
    {
        RCLCPP_WARN(this->get_logger(), "Received empty state name, ignoring load request.");
        return;
    }
    RCLCPP_WARN(this->get_logger(), "LOAD STATE");
    load_state_from_db(msg->data);
}

void StateMachine::gripper_action_callback(const robot_interfaces::msg::GripperControl::SharedPtr msg)
{
    if (current_mode_ != GRIPPERCONTROL)
        return;
    RCLCPP_WARN(this->get_logger(), "Gripper_Pose startpublished.");
    gripper_msg_pub->publish(*msg);
    RCLCPP_WARN(this->get_logger(), "Gripper_Pose published.");
}

void StateMachine::usr_param_callback(const robot_interfaces::msg::GenericMotorParameter::SharedPtr msg)
{
    if (current_mode_ != USERPARAMSET)
        return;
    usr_param_pub->publish(*msg);
    RCLCPP_WARN(this->get_logger(), "USR param published.");
}
int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<StateMachine>("robot_state_mechine");
    node->post_init();
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
