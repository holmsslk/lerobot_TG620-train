#include "robot_can_node.hpp"

RobotCanNode::RobotCanNode(const std::string &node_name) : Node(node_name)
{
    this->declare_parameter<bool>("use_canfd", true);
    use_canfd_ = this->get_parameter("use_canfd").as_bool();

    can_driver_ = std::make_shared<motor_driver::RobotCanDriver>("can0", use_canfd_);
    can_driver_->start_receive();
    can_driver_->set_button_callback(
        [this](uint8_t button_mode)
        {
            this->handle_button_event(button_mode);
        });
    joint_state_sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "motor_cmd", 10, std::bind(&RobotCanNode::motor_cmd_callback, this, std::placeholders::_1));

    motor_control_sub_ = this->create_subscription<robot_interfaces::msg::RobotControlMsg>(
        "motor_control_msg", 10, std::bind(&RobotCanNode::motor_control_callback, this, std::placeholders::_1));
    gripper_control_sub_ = this->create_subscription<robot_interfaces::msg::GripperControl>(
        "gripper_control_msg", 10, std::bind(&RobotCanNode::gripper_control_callback, this, std::placeholders::_1));

    motor_parameter_sub_ = this->create_subscription<robot_interfaces::msg::GenericMotorParameter>(
        "motor_parameter_cmd", 10, std::bind(&RobotCanNode::motor_parameter_set_callback, this, std::placeholders::_1));

    debug_parameter_sub_ = this->create_subscription<robot_interfaces::msg::GenericMotorParameter>(
        "debug_parameter_cmd", 10, std::bind(&RobotCanNode::debug_parameter_set_callback, this, std::placeholders::_1));

    motor_operation_sub_ = this->create_subscription<robot_interfaces::msg::GenericMotorOperation>(
        "motor_operation_cmd", 10, std::bind(&RobotCanNode::motor_operation_set_callback, this, std::placeholders::_1));

    button_status_sub_ = this->create_subscription<std_msgs::msg::UInt8>(
        "button_status_cmd", 10, std::bind(&RobotCanNode::button_status_callback, this, std::placeholders::_1));

    motor_parameter_get_sub_ = this->create_subscription<std_msgs::msg::UInt8>(
        "motor_parameter_get", 10, std::bind(&RobotCanNode::motor_parameter_get_callback, this, std::placeholders::_1));

    debug_parameter_get_sub_ = this->create_subscription<std_msgs::msg::UInt8>(
        "debug_parameter_get", 10, std::bind(&RobotCanNode::debug_parameter_get_callback, this, std::placeholders::_1));

    traj_get_sub_ = this->create_subscription<trajectory_msgs::msg::JointTrajectory>(
        "joint_trajectory", 10, std::bind(&RobotCanNode::traj_get_callback, this, std::placeholders::_1));

    joint_state_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
    joint_state_timer_ = this->create_wall_timer(
        std::chrono::milliseconds(10), std::bind(&RobotCanNode::publish_joint_states, this));
    motor_request_timer_ = this->create_wall_timer(std::chrono::milliseconds(10), std::bind(&RobotCanNode::motor_request_timer_callback, this));
    mode_pub_ = this->create_publisher<std_msgs::msg::UInt8>("robotic_arm_control_mode", 10);
    teach_pub_ = this->create_publisher<std_msgs::msg::String>("teach_action", 10);
    teachrepeat_pub_ = this->create_publisher<std_msgs::msg::String>("teachrepeat_action", 10);
}

void RobotCanNode::motor_cmd_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
{
    motor_driver::MotorEnableMode enable_flag = motor_driver::MotorEnableMode::MOTOR_ENABLE;
    motor_driver::MotorControlMode control_mode = motor_driver::MotorControlMode::POSITION_ABS_MODE;

    for (size_t i = 1; i <= msg->position.size(); i++)
    {
        uint8_t motor_id = static_cast<uint8_t>(i);
        std::optional<float> pos = (i <= msg->position.size()) ? std::optional<float>(msg->position[i - 1]) : std::nullopt;
        // std::optional<float> vel = (i <= msg->velocity.size()) ? std::optional<float>(msg->velocity[i - 1]) : std::nullopt;
        //  std::optional<float> eff = (i <= msg->effort.size()) ? std::optional<float>(msg->effort[i - 1]) : std::nullopt;
        std::optional<float> vel, eff;
        can_driver_->send_motor_control(motor_id, enable_flag, control_mode, pos, vel, eff);
    }
}

void RobotCanNode::motor_control_callback(const robot_interfaces::msg::RobotControlMsg::SharedPtr msg)
{
    for (size_t i = 1; i <= msg->motor_mode.size(); i++)
    {
        uint8_t motor_id = static_cast<uint8_t>(i);
        auto enable_flag = static_cast<motor_driver::MotorEnableMode>(msg->motor_enable_flag[i - 1]);
        auto motor_mode = static_cast<motor_driver::MotorControlMode>(msg->motor_mode[i - 1]);
        std::optional<float> pos = (i <= msg->position.size()) ? std::optional<float>(msg->position[i - 1]) : std::nullopt;
        std::optional<float> vel = (i <= msg->velocity.size()) ? std::optional<float>(msg->velocity[i - 1]) : std::nullopt;
        std::optional<float> eff = (i <= msg->effort.size()) ? std::optional<float>(msg->effort[i - 1]) : std::nullopt;
        can_driver_->send_motor_control(motor_id, enable_flag, motor_mode, pos, vel, eff);
        // RCLCPP_INFO(this->get_logger(), "joint %zu  mode %d is write!",i, msg->motor_mode[i - 1]);
    }
}

void RobotCanNode::gripper_control_callback(const robot_interfaces::msg::GripperControl::SharedPtr msg)
{
    const uint8_t *data_ptr = msg->data.empty() ? nullptr : msg->data.data();
    uint8_t data_len = static_cast<uint8_t>(msg->data.size());
    RCLCPP_INFO(this->get_logger(), "data_len %d", data_len);
    can_driver_->send_gripper_control(msg->type, msg->position, msg->velocity, msg->effort, data_ptr, data_len);
}

void RobotCanNode::disable_motor(uint8_t motor_id)
{
    can_driver_->send_motor_control(motor_id, motor_driver::MotorEnableMode::MOTOR_DISABLE,
                                    motor_driver::MotorControlMode::POSITION_ABS_MODE);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void RobotCanNode::write_param_and_save(uint8_t motor_id, motor_driver::ParamAddr addr, int32_t int_value)
{
    disable_motor(motor_id);
    can_driver_->send_param_write(motor_id, addr, int_value);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_function_op_code(motor_id, motor_driver::FuncOpCode::PARAM_SAVE_TO_FLASH);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void RobotCanNode::write_param_and_save(uint8_t motor_id, motor_driver::ParamAddr addr, float float_value)
{
    disable_motor(motor_id);
    can_driver_->send_param_write(motor_id, addr, float_value);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_function_op_code(motor_id, motor_driver::FuncOpCode::PARAM_SAVE_TO_FLASH);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
void RobotCanNode::write_debug_param(uint8_t motor_id, motor_driver::DebugParamAddr addr, int32_t int_value)
{

    can_driver_->send_debug_param_write(motor_id, addr, int_value);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void RobotCanNode::write_debug_param(uint8_t motor_id, motor_driver::DebugParamAddr addr, float float_value)
{
    can_driver_->send_debug_param_write(motor_id, addr, float_value);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
void RobotCanNode::send_op_and_save(uint8_t motor_id, motor_driver::FuncOpCode op_code)
{
    disable_motor(motor_id);
    can_driver_->send_function_op_code(motor_id, op_code);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_function_op_code(motor_id, motor_driver::FuncOpCode::PARAM_SAVE_TO_FLASH);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void RobotCanNode::motor_parameter_set_callback(const robot_interfaces::msg::GenericMotorParameter::SharedPtr msg)
{
    auto param = static_cast<motor_driver::ParamAddr>(msg->command_type);
    uint8_t id = msg->motor_id;

    switch (param)
    {
    case motor_driver::ParamAddr::SYS_CAN_ID_BASE:
    {
        const uint8_t old_id = msg->motor_id;
        const uint8_t new_id = static_cast<uint8_t>(msg->int_value);

        can_driver_->send_motor_control(old_id, motor_driver::MotorEnableMode::MOTOR_DISABLE, motor_driver::MotorControlMode::POSITION_ABS_MODE);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        can_driver_->send_param_write(old_id, motor_driver::ParamAddr::SYS_CAN_ID_BASE, new_id);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        can_driver_->send_function_op_code(new_id, motor_driver::FuncOpCode::PARAM_SAVE_TO_FLASH);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        break;
    }
    case motor_driver::ParamAddr::SERVO_CONTROL_MODE:
    case motor_driver::ParamAddr::SERVO_ENABLE_FLAG:
    case motor_driver::ParamAddr::LIMIT_POS_FLAG:
    case motor_driver::ParamAddr::SYS_CAN_TYPE:
    {
        write_param_and_save(id, param, msg->int_value);
        break;
    }
    case motor_driver::ParamAddr::LIMIT_POS_MAX:
    case motor_driver::ParamAddr::LIMIT_POS_MIN:
    case motor_driver::ParamAddr::LIMIT_POS_ZERO:
    case motor_driver::ParamAddr::LIMIT_VELOCITY_MAX:
    case motor_driver::ParamAddr::LIMIT_VELOCITY_ACC_T1:
    case motor_driver::ParamAddr::LIMIT_CURRENT_MAX:
    case motor_driver::ParamAddr::LIMIT_VOLTAGE_MAX:
    case motor_driver::ParamAddr::LIMIT_VELOCITY_ACC_T3:
    {
        write_param_and_save(id, param, msg->float_value);
        break;
    }
    case motor_driver::ParamAddr::SYS_INT_RESERVER_3:
    case motor_driver::ParamAddr::SYS_INT_RESERVER_2:
    case motor_driver::ParamAddr::SYS_INT_RESERVER_1:
    default:
        break;
    }
}

void RobotCanNode::motor_parameter_get_callback(const std_msgs::msg::UInt8 msg)
{
    uint8_t id = msg.data;
    can_driver_->send_param_read(id, motor_driver::ParamAddr::SYS_CAN_ID_BASE);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_param_read(id, motor_driver::ParamAddr::LIMIT_POS_FLAG);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_param_read(id, motor_driver::ParamAddr::LIMIT_POS_MAX);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_param_read(id, motor_driver::ParamAddr::LIMIT_POS_MIN);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_param_read(id, motor_driver::ParamAddr::LIMIT_VELOCITY_MAX);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_param_read(id, motor_driver::ParamAddr::LIMIT_VELOCITY_ACC_T1);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_param_read(id, motor_driver::ParamAddr::LIMIT_CURRENT_MAX);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_param_read(id, motor_driver::ParamAddr::LIMIT_VELOCITY_ACC_T3);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
void RobotCanNode::debug_parameter_get_callback(const std_msgs::msg::UInt8 msg)
{
    uint8_t id = msg.data;
    can_driver_->send_debug_param_read(id, motor_driver::DebugParamAddr::SYS_PN_3);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_debug_param_read(id, motor_driver::DebugParamAddr::SYS_PN_2);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_debug_param_read(id, motor_driver::DebugParamAddr::SYS_PN_1);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_debug_param_read(id, motor_driver::DebugParamAddr::SYS_PN_0);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_debug_param_read(id, motor_driver::DebugParamAddr::SYS_SN_3);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_debug_param_read(id, motor_driver::DebugParamAddr::SYS_SN_2);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_debug_param_read(id, motor_driver::DebugParamAddr::SYS_SN_1);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    can_driver_->send_debug_param_read(id, motor_driver::DebugParamAddr::SYS_SN_0);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
void RobotCanNode::debug_parameter_set_callback(const robot_interfaces::msg::GenericMotorParameter::SharedPtr msg)
{
    auto param = static_cast<motor_driver::DebugParamAddr>(msg->command_type);
    uint8_t id = msg->motor_id;
    write_debug_param(id, param, msg->float_value);
    RCLCPP_INFO(this->get_logger(), "joint %d  param %u  value: %lf is write!", id, static_cast<unsigned int>(param), msg->float_value);
}
void RobotCanNode::motor_operation_set_callback(const robot_interfaces::msg::GenericMotorOperation::SharedPtr msg)
{
    auto op = static_cast<motor_driver::FuncOpCode>(msg->op_code);
    uint8_t id = msg->motor_id;

    switch (op)
    {
    case motor_driver::FuncOpCode::PARAM_RESET:
    case motor_driver::FuncOpCode::CLEAR_ERROR_CODE:
    case motor_driver::FuncOpCode::MOTOR_ZERO_POS_SET:
    case motor_driver::FuncOpCode::MOTOR_IAP_UPDATE:
    case motor_driver::FuncOpCode::MOTOR_HALL_CALIBRATION:
    case motor_driver::FuncOpCode::MOTOR_CURRENT_CALIBRATION:
    case motor_driver::FuncOpCode::MOTOR_ENCODER_CALIBRATION:
    case motor_driver::FuncOpCode::MOTOR_SOFTWARE_RESET:
        send_op_and_save(id, op);
        break;
    case motor_driver::FuncOpCode::PARAM_SAVE_TO_FLASH:
    default:
        break;
    }
}

void RobotCanNode::publish_joint_states()
{
    auto message = sensor_msgs::msg::JointState();
    message.header.stamp = this->get_clock()->now();
    message.name.reserve(motor_driver::MOTOR_NUM);
    message.position.reserve(motor_driver::MOTOR_NUM);
    message.velocity.reserve(motor_driver::MOTOR_NUM);
    message.effort.reserve(motor_driver::MOTOR_NUM);

    for (uint8_t motor_id = 1; motor_id <= motor_driver::MOTOR_NUM; motor_id++)
    {
        auto motor_status = can_driver_->get_motor_status(motor_id);
        if (motor_status)
        {
            message.name.push_back("joint" + std::to_string(motor_id));
            message.position.push_back(motor_status->position * motor_driver::PI / 180.0); // degree to rad
            message.velocity.push_back(motor_status->velocity);
            message.effort.push_back(motor_status->current);
        }
    }
    joint_state_pub_->publish(message);
}
void RobotCanNode::handle_button_event(uint8_t button_mode)
{
    std_msgs::msg::UInt8 mode_msg;
    std_msgs::msg::String str_msg;

    switch (button_mode)
    {
    case static_cast<int>(motor_driver::BUTTONSTATUS::ENTRY_TEACH):
        mode_msg.data = 7;
        mode_pub_->publish(mode_msg);

        str_msg.data = "teach_example";
        teach_pub_->publish(str_msg);
        break;

    case static_cast<int>(motor_driver::BUTTONSTATUS::EXIT_TEACH):
        str_msg.data = "stop";
        teach_pub_->publish(str_msg);
        break;

    case static_cast<int>(motor_driver::BUTTONSTATUS::TEACH_REPEAT):
        mode_msg.data = 8;
        mode_pub_->publish(mode_msg);

        str_msg.data = "teach_example";
        teachrepeat_pub_->publish(str_msg);
        break;

    default:
        break;
    }
}
void RobotCanNode::button_status_callback(const std_msgs::msg::UInt8::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "button_data:%d", msg->data);
    if (msg->data == 1)
    {
        RCLCPP_INFO(this->get_logger(), "button_finish_rec");
        can_driver_->send_button();
    }
}
void RobotCanNode::motor_request_timer_callback()
{
    if (!motor_request_queue_.empty())
    {
        auto task = motor_request_queue_.front();
        motor_request_queue_.pop();
        can_driver_->send_motor_feedback_request(task.motor_id, task.type);
    }
    else
    {
        if (use_canfd_)
        {
            for (uint8_t i = 1; i <= motor_driver::MOTOR_NUM; i++)
            {
                motor_request_queue_.push({i, std::nullopt});
            }
        }
        else
        {
            for (uint8_t i = 1; i <= motor_driver::MOTOR_NUM; i++)
            {
                motor_request_queue_.push({i, motor_driver::MotorFeedbackType::DATA1});
                motor_request_queue_.push({i, motor_driver::MotorFeedbackType::DATA3});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotCanNode>("robot_can_node");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
