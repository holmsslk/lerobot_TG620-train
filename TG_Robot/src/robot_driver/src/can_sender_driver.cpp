#include "can_sender_driver.hpp"
#include "rclcpp/rclcpp.hpp"
#include "can_gripper.hpp"
namespace motor_driver
{

    GenericCanTxPacket CanSenderDriver::build_param_read(uint8_t motor_id, ParamAddr param_addr)
    {
        GenericCanTxPacket packet;
        packet.canid = std::make_unique<CanId>(motor_id + static_cast<uint32_t>(CommandType_Tx::PARAM_RW), 0, FrameType::DATA, ExtendedFrame);
        packet.use_canfd = use_canfd_;
        if (use_canfd_)
        {
            packet.data.resize(4, 0);
            packet.data[0] = 0x03;
            packet.data[1] = static_cast<uint8_t>(OperationMethod::READ);
            packet.data[2] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[3] = static_cast<uint8_t>(param_addr);
        }
        else
        {
            packet.data.resize(3, 0);
            packet.data[0] = static_cast<uint8_t>(OperationMethod::READ);
            packet.data[1] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[2] = static_cast<uint8_t>(param_addr);
        }
        return packet;
    }

    GenericCanTxPacket CanSenderDriver::build_param_write(uint8_t motor_id, ParamAddr param_addr, int32_t param_data)
    {
        GenericCanTxPacket packet;
        packet.canid = std::make_unique<CanId>(motor_id + static_cast<uint32_t>(CommandType_Tx::PARAM_RW), 0, FrameType::DATA, ExtendedFrame);
        packet.use_canfd = use_canfd_;
        if (use_canfd_)
        {
            packet.data.resize(12, 0);
            packet.data[0] = 0x08;
            packet.data[1] = static_cast<uint8_t>(OperationMethod::WRITE);
            packet.data[2] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[3] = static_cast<uint8_t>(param_addr);
            packet.data[4] = static_cast<uint8_t>(ParamType::INT32);
            packet.data[5] = param_data >> 24;
            packet.data[6] = param_data >> 16;
            packet.data[7] = param_data >> 8;
            packet.data[8] = param_data;
        }
        else
        {
            packet.data.resize(8, 0);
            packet.data[0] = static_cast<uint8_t>(OperationMethod::WRITE);
            packet.data[1] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[2] = static_cast<uint8_t>(param_addr);
            packet.data[3] = static_cast<uint8_t>(ParamType::INT32);
            packet.data[4] = static_cast<uint8_t>(param_data >> 24);
            packet.data[5] = static_cast<uint8_t>(param_data >> 16);
            packet.data[6] = static_cast<uint8_t>(param_data >> 8);
            packet.data[7] = static_cast<uint8_t>(param_data);
        }

        return packet;
    }

    GenericCanTxPacket CanSenderDriver::build_param_write(uint8_t motor_id, ParamAddr param_addr, float param_data)
    {
        GenericCanTxPacket packet;
        packet.canid = std::make_unique<CanId>(motor_id + static_cast<uint32_t>(CommandType_Tx::PARAM_RW), 0, FrameType::DATA, ExtendedFrame);
        packet.use_canfd = use_canfd_;

        if (use_canfd_)
        {
            packet.data.resize(12, 0);
            packet.data[0] = 0x08;
            packet.data[1] = static_cast<uint8_t>(OperationMethod::WRITE);
            packet.data[2] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[3] = static_cast<uint8_t>(param_addr);
            packet.data[4] = static_cast<uint8_t>(ParamType::FLOAT);
            FloatUintConverter converter;
            converter.f = param_data;
            packet.data[5] = converter.u >> 24;
            packet.data[6] = converter.u >> 16;
            packet.data[7] = converter.u >> 8;
            packet.data[8] = converter.u;
            return packet;
        }
        else
        {
            packet.data.resize(8, 0);
            packet.data[0] = static_cast<uint8_t>(OperationMethod::WRITE);
            packet.data[1] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[2] = static_cast<uint8_t>(param_addr);
            packet.data[3] = static_cast<uint8_t>(ParamType::FLOAT);
            FloatUintConverter converter;
            converter.f = param_data;
            packet.data[4] = converter.u >> 24;
            packet.data[5] = converter.u >> 16;
            packet.data[6] = converter.u >> 8;
            packet.data[7] = converter.u;
        }

        return packet;
    }

    GenericCanTxPacket CanSenderDriver::build_debug_param_read(uint8_t motor_id, DebugParamAddr param_addr)
    {
        GenericCanTxPacket packet;
        packet.canid = std::make_unique<CanId>(motor_id + static_cast<uint32_t>(CommandType_Tx::DUBUG_PARAM), 0, FrameType::DATA, ExtendedFrame);
        packet.use_canfd = use_canfd_;
        if (use_canfd_)
        {
            packet.data.resize(4, 0);
            packet.data[0] = 0x03;
            packet.data[1] = static_cast<uint8_t>(OperationMethod::READ);
            packet.data[2] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[3] = static_cast<uint8_t>(param_addr);
        }
        else
        {
            packet.data.resize(3, 0);
            packet.data[0] = static_cast<uint8_t>(OperationMethod::READ);
            packet.data[1] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[2] = static_cast<uint8_t>(param_addr);
        }
        return packet;
    }

    GenericCanTxPacket CanSenderDriver::build_debug_param_write(uint8_t motor_id, DebugParamAddr param_addr, int32_t param_data)
    {
        GenericCanTxPacket packet;
        packet.canid = std::make_unique<CanId>(motor_id + static_cast<uint32_t>(CommandType_Tx::DUBUG_PARAM), 0, FrameType::DATA, ExtendedFrame);

        packet.use_canfd = use_canfd_;
        if (use_canfd_)
        {
            packet.data.resize(12, 0);
            packet.data[0] = 0x08;
            packet.data[1] = static_cast<uint8_t>(OperationMethod::WRITE);
            packet.data[2] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[3] = static_cast<uint8_t>(param_addr);
            packet.data[4] = static_cast<uint8_t>(ParamType::INT32);
            packet.data[5] = param_data >> 24;
            packet.data[6] = param_data >> 16;
            packet.data[7] = param_data >> 8;
            packet.data[8] = param_data;
        }
        else
        {
            packet.data.resize(8, 0);
            packet.data[0] = static_cast<uint8_t>(OperationMethod::WRITE);
            packet.data[1] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[2] = static_cast<uint8_t>(param_addr);
            packet.data[3] = static_cast<uint8_t>(ParamType::INT32);
            packet.data[4] = static_cast<uint8_t>(param_data >> 24);
            packet.data[5] = static_cast<uint8_t>(param_data >> 16);
            packet.data[6] = static_cast<uint8_t>(param_data >> 8);
            packet.data[7] = static_cast<uint8_t>(param_data);
        }

        return packet;
    }

    GenericCanTxPacket CanSenderDriver::build_debug_param_write(uint8_t motor_id, DebugParamAddr param_addr, float param_data)
    {
        GenericCanTxPacket packet;
        packet.canid = std::make_unique<CanId>(motor_id + static_cast<uint32_t>(CommandType_Tx::DUBUG_PARAM), 0, FrameType::DATA, ExtendedFrame);
        packet.use_canfd = use_canfd_;

        if (use_canfd_)
        {
            packet.data.resize(12, 0);
            packet.data[0] = 0x08;
            packet.data[1] = static_cast<uint8_t>(OperationMethod::WRITE);
            packet.data[2] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[3] = static_cast<uint8_t>(param_addr);
            packet.data[4] = static_cast<uint8_t>(ParamType::FLOAT);
            FloatUintConverter converter;
            converter.f = param_data;
            packet.data[5] = converter.u >> 24;
            packet.data[6] = converter.u >> 16;
            packet.data[7] = converter.u >> 8;
            packet.data[8] = converter.u;
            return packet;
        }
        else
        {
            packet.data.resize(8, 0);
            packet.data[0] = static_cast<uint8_t>(OperationMethod::WRITE);
            packet.data[1] = static_cast<uint8_t>(param_addr) >> 8;
            packet.data[2] = static_cast<uint8_t>(param_addr);
            packet.data[3] = static_cast<uint8_t>(ParamType::FLOAT);
            FloatUintConverter converter;
            converter.f = param_data;
            packet.data[4] = converter.u >> 24;
            packet.data[5] = converter.u >> 16;
            packet.data[6] = converter.u >> 8;
            packet.data[7] = converter.u;
        }

        return packet;
    }

    GenericCanTxPacket CanSenderDriver::build_motor_control(uint8_t motor_id, MotorEnableMode enable_flag, MotorControlMode motor_mode,
                                                            std::optional<float> pos, std::optional<float> vel, std::optional<float> eff, uint8_t kp, uint8_t kd)
    {

        GenericCanTxPacket packet;
        packet.canid = std::make_unique<CanId>(motor_id + static_cast<uint32_t>(CommandType_Tx::MOTOR_CTRL), 0, FrameType::DATA, ExtendedFrame);
        packet.use_canfd = use_canfd_;
        FloatUintConverter converter;

        if (use_canfd_)
        {
            packet.data.resize(24, 0);
            packet.data[0] = 0x10;
            packet.data[1] = static_cast<uint8_t>(enable_flag);
            packet.data[2] = static_cast<uint8_t>(motor_mode);

            switch (motor_mode)
            {
            case MotorControlMode::CURRENT_MODE:
            {
                if (eff)
                {
                    converter.f = *eff;
                    for (int i = 0; i < 4; ++i)
                        packet.data[11 + i] = converter.u >> (24 - i * 8);
                }
                break;
            }
            case MotorControlMode::EFFORT_POSITION_MODE:
            {
                if (pos)
                {
                    converter.f = *pos * 180.0f / PI;
                    for (int i = 0; i < 4; ++i)
                        packet.data[3 + i] = converter.u >> (24 - i * 8);
                }
                if (vel)
                {
                    converter.f = *vel * 180.0f / PI;
                    for (int i = 0; i < 4; ++i)
                        packet.data[7 + i] = converter.u >> (24 - i * 8);
                }
                if (eff)
                {
                    converter.f = *eff;
                    for (int i = 0; i < 4; ++i)
                        packet.data[11 + i] = converter.u >> (24 - i * 8);
                }
                break;
            }
            case MotorControlMode::SPEED_MODE:
            {
                if (vel)
                {
                    converter.f = *vel * 180.0f / PI;
                    for (int i = 0; i < 4; ++i)
                        packet.data[7 + i] = converter.u >> (24 - i * 8);
                }
                break;
            }
            case MotorControlMode::POSITION_ABS_MODE:
            {
                if (pos)
                {
                    converter.f = *pos * 180.0f / PI;
                    for (uint8_t i = 0; i < 4; i++)
                        packet.data[3 + i] = converter.u >> (24 - i * 8);
                }
                break;
            }
            case MotorControlMode::POSITION_INC_MODE:
            {
                if (pos)
                {
                    converter.f = *pos * 180.0f / PI;
                    for (uint8_t i = 0; i < 4; ++i)
                        packet.data[3 + i] = converter.u >> (24 - i * 8);
                }
                break;
            }
            }
            packet.data[15] = kp;
            packet.data[16] = kd;
        }
        else
        {
            packet.data.resize(8, 0);
            packet.data[0] = static_cast<uint8_t>(enable_flag);
            packet.data[1] = static_cast<uint8_t>(motor_mode);
            if (pos)
            {
                converter.f = *pos * 180.0f / PI;
                for (uint8_t i = 0; i < 4; ++i)
                    packet.data[4 + i] = converter.u >> (24 - i * 8);
            }
            else if (vel)
            {
                converter.f = *vel;
                for (uint8_t i = 0; i < 4; ++i)
                    packet.data[4 + i] = converter.u >> (24 - i * 8);
            }
            else if (eff)
            {
                converter.f = *eff;
                for (uint8_t i = 0; i < 4; ++i)
                    packet.data[4 + i] = converter.u >> (24 - i * 8);
            }
        }
        return packet;
    }

    GenericCanTxPacket CanSenderDriver::build_function_op(uint8_t motor_id, FuncOpCode func_code)
    {
        GenericCanTxPacket packet;
        packet.canid = std::make_unique<CanId>(motor_id + static_cast<uint32_t>(CommandType_Tx::FUNC_CTRL), 0, FrameType::DATA, ExtendedFrame);
        packet.use_canfd = use_canfd_;

        if (use_canfd_)
        {
            packet.data.resize(2, 0);
            packet.data[0] = 0x01;
            packet.data[1] = static_cast<uint8_t>(func_code);
        }
        else
        {
            packet.data.resize(1, 0);
            packet.data[0] = static_cast<uint8_t>(func_code);
        }
        return packet;
    }

    GenericCanTxPacket CanSenderDriver::build_motor_status_req(uint8_t motor_id, std::optional<uint8_t> data_type, std::optional<uint8_t> motor_req_method)
    {
        GenericCanTxPacket packet;
        packet.canid = std::make_unique<CanId>(motor_id + static_cast<uint32_t>(CommandType_Tx::FDB_REQ), 0, FrameType::DATA, ExtendedFrame);

        packet.use_canfd = use_canfd_;
        if (use_canfd_)
        {
            packet.data.resize(1, 0);
            packet.data[0] = 0x00;
        }
        else
        {
            packet.data.resize(2, 0);
            if (data_type && motor_req_method)
            {
                packet.data[0] = *data_type;
                packet.data[1] = *motor_req_method;
            }
        }
        return packet;
    }

    GenericCanTxPacket CanSenderDriver::build_gripper_control(uint8_t gripper_type, uint8_t position, uint8_t velocity, uint8_t effort, const uint8_t *data, uint8_t data_length)
    {
        GenericCanTxPacket packet;
        RCLCPP_INFO(rclcpp::get_logger("can_sender_driver"), "gripper_type %d", gripper_type);
        packet.use_canfd = use_canfd_;

        switch (gripper_type)
        {
        case static_cast<uint8_t>(Gripper_Type::OmniPicker):
        {
            packet.data.resize(8, 0);
            packet.canid = std::make_unique<CanId>(CANFD_2_RS485_ID, 0, FrameType::DATA, ExtendedFrame);
            packet.data[0] = 0x01;
            send_packet(packet);
            packet.canid = std::make_unique<CanId>(SEND_GRIPPER_ID, 0, FrameType::DATA, ExtendedFrame);
            OmniPicker_Frame ominipicker_frame(position, velocity, effort, 0xFF, 0xFF);

            std::copy(ominipicker_frame.getDataPtr(), ominipicker_frame.getDataPtr() + 8, packet.data.begin());
            break;
        }
        case static_cast<uint8_t>(Gripper_Type::PGC_Gripper):
        {
            packet.data.resize(8, 0);
            packet.canid = std::make_unique<CanId>(CANFD_2_RS485_ID, 0, FrameType::DATA, ExtendedFrame);
            packet.data[0] = 0x01;
            send_packet(packet);
            packet.canid = std::make_unique<CanId>(SEND_GRIPPER_ID, 0, FrameType::DATA, ExtendedFrame);
            PGC_Gripper pgc_gripper_frame(velocity, effort, position);
            std::copy(pgc_gripper_frame.getDataPtr(), pgc_gripper_frame.getDataPtr() + 8, packet.data.begin());
            break;
        }
        case static_cast<uint8_t>(Gripper_Type::Raw_Frame):
        {
            packet.canid = std::make_unique<CanId>(CANFD_2_RS485_ID, 0, FrameType::DATA, ExtendedFrame);
            packet.data.resize(data_length + 6, 0);
            packet.data[0] = 0x02;
            send_packet(packet);
            packet.canid = std::make_unique<CanId>(CANFD_2_RS485_ID, 0, FrameType::DATA, ExtendedFrame);
            Canfd_485_Raw_Frame canfd_485_raw_frame(data, data_length, true);
            std::copy(canfd_485_raw_frame.getDataPtr(), canfd_485_raw_frame.getDataPtr() + canfd_485_raw_frame.getDataLength(), packet.data.begin());
            break;
        }

        default:
            break;
        }
        return packet;
    }

    CanSenderDriver::CanSenderDriver(const std::string &device, bool use_canfd) : use_canfd_(use_canfd)
    {
        sender_ = std::make_unique<SocketCanSender>(device, use_canfd);
    }

    GenericCanTxPacket CanSenderDriver::build_button_status()
    {
        GenericCanTxPacket frame;
        // uint8_t canid = 0x7F;
        frame.canid = std::make_unique<CanId>(static_cast<uint32_t>(0x7F), 0, FrameType::DATA, ExtendedFrame);
        frame.use_canfd = use_canfd_;
        frame.data.resize(4, 0);
        frame.data[0] = 0x46;
        frame.data[1] = 0x58;
        frame.data[2] = 0x4A;
        frame.data[3] = 0x53;
        return frame;
    }
    void CanSenderDriver::send_packet(const GenericCanTxPacket &packet)
    {

        if (packet.use_canfd == false)
        {
            if (send_mutex_.try_lock())
            {
                sender_->send(packet.data.data(), packet.data.size(), *packet.canid, std::chrono::seconds(1));
                send_mutex_.unlock();
            }
        }
        else
        {
            if (send_mutex_.try_lock())
            {
                sender_->send_fd(packet.data.data(), packet.data.size(), *packet.canid, std::chrono::seconds(1));
                send_mutex_.unlock();
            }
        }
    }

} // namespace motor_driver
