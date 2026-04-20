#include "robot_can_driver.hpp"
#include "rclcpp/rclcpp.hpp"

namespace motor_driver
{

    RobotCanDriver::RobotCanDriver(const std::string &device, bool use_canfd)
        : CanReceiverDriver(device, use_canfd), CanSenderDriver(device, use_canfd), use_canfd_(use_canfd) {}

    RobotCanDriver::~RobotCanDriver()
    {
        stop_receive();
    }

    void RobotCanDriver::start_receive()
    {
        if (running_.exchange(true))
            return;
        receive_thread_ = std::thread([this]()
                                      { this->run_receive_loop(); });
    }

    void RobotCanDriver::stop_receive()
    {
        running_.store(false);
        if (receive_thread_.joinable())
        {
            receive_thread_.join();
        }
    }

    void RobotCanDriver::send_motor_control(uint8_t motor_id, MotorEnableMode enable_flag, MotorControlMode motor_mode,
                                            std::optional<float> pos, std::optional<float> vel, std::optional<float> eff, uint8_t kp, uint8_t kd)
    {
        GenericCanTxPacket frame;
        if (use_canfd_)
        {
            frame = build_motor_control(motor_id, enable_flag, motor_mode, pos, vel, eff, kp, kd);
        }
        else
        {
            switch (motor_mode)
            {
            case MotorControlMode::CURRENT_MODE:
            {
                frame = build_motor_control(motor_id, enable_flag, motor_mode, std::nullopt, std::nullopt, eff);
                break;
            }
            case MotorControlMode::EFFORT_POSITION_MODE:
            {
                frame = build_motor_control(motor_id, enable_flag, motor_mode, pos, std::nullopt, eff);
                break;
            }
            case MotorControlMode::SPEED_MODE:
            {
                frame = build_motor_control(motor_id, enable_flag, motor_mode, std::nullopt, vel, std::nullopt);
                break;
            }
            case MotorControlMode::POSITION_ABS_MODE:
            case MotorControlMode::POSITION_INC_MODE:
            {
                frame = build_motor_control(motor_id, enable_flag, motor_mode, pos, std::nullopt, std::nullopt);
                break;
            }
            default:
                break;
            }
        }
        send_packet(frame);
    }

    void RobotCanDriver::send_gripper_control(uint8_t gripper_type, double position, double velocity, double effort, const uint8_t *data, uint8_t data_length)
    {
        auto frame = build_gripper_control(gripper_type, position, velocity, effort, data, data_length);
        send_packet(frame);
    }

    void RobotCanDriver::send_motor_feedback_request(uint8_t motor_id, std::optional<MotorFeedbackType> type)
    {
        GenericCanTxPacket frame;
        if (use_canfd_)
        {
            frame = build_motor_status_req(motor_id, std::nullopt, std::nullopt);
        }
        else
        {
            if (type)
            {
                frame = build_motor_status_req(motor_id, static_cast<uint8_t>(*type), static_cast<uint8_t>(MotorFeedbackMethod::ONCE));
            }
        }
        send_packet(frame);
    }

    void RobotCanDriver::send_function_op_code(uint8_t motor_id, FuncOpCode op_code)
    {
        GenericCanTxPacket frame = build_function_op(motor_id, op_code);
        send_packet(frame);
    }

    void RobotCanDriver::send_param_write(uint8_t motor_id, ParamAddr param_addr, int32_t param_data)
    {
        GenericCanTxPacket frame = build_param_write(motor_id, param_addr, param_data);
        send_packet(frame);
    }

    void RobotCanDriver::send_param_write(uint8_t motor_id, ParamAddr param_addr, float param_data)
    {
        GenericCanTxPacket frame = build_param_write(motor_id, param_addr, param_data);
        send_packet(frame);
    }
    void RobotCanDriver::send_debug_param_write(uint8_t motor_id, DebugParamAddr param_addr, int32_t param_data)
    {
        GenericCanTxPacket frame = build_debug_param_write(motor_id, param_addr, param_data);
        send_packet(frame);
    }

    void RobotCanDriver::send_debug_param_write(uint8_t motor_id, DebugParamAddr param_addr, float param_data)
    {
        GenericCanTxPacket frame = build_debug_param_write(motor_id, param_addr, param_data);
        send_packet(frame);
    }
    void RobotCanDriver::send_param_read(uint8_t motor_id, ParamAddr param_addr)
    {
        GenericCanTxPacket frame = build_param_read(motor_id, param_addr);
        send_packet(frame);
    }
    void RobotCanDriver::send_debug_param_read(uint8_t motor_id, DebugParamAddr param_addr)
    {
        GenericCanTxPacket frame = build_debug_param_read(motor_id, param_addr);
        send_packet(frame);
    }
    void RobotCanDriver::send_button()
    {
        GenericCanTxPacket frame = build_button_status();
        send_packet(frame);
    }

} // namespace motor_driver
