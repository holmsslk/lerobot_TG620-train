#include "can_receiver_driver.hpp"

namespace motor_driver
{

    void CanReceiverParser::parse(const CanId &can_id, const std::vector<uint8_t> &rx_data, bool use_canfd_, std::shared_ptr<Motor_Status> motor_status, rclcpp::Logger logger)
    {
        uint32_t base_id = can_id.identifier() & 0xFFFFFF00;
        switch (base_id)
        {
        case static_cast<uint32_t>(CommandType_Rx::FDB_REQ):
        {
            if (use_canfd_)
            {
                FloatUintConverter converter;
                motor_status->enable_flag = rx_data[1];
                motor_status->motor_mode = rx_data[2];
                converter.u = (rx_data[3] << 24) | (rx_data[4] << 16) | (rx_data[5] << 8) | rx_data[6];
                motor_status->position = converter.f;
                converter.u = (rx_data[7] << 24) | (rx_data[8] << 16) | (rx_data[9] << 8) | rx_data[10];
                motor_status->velocity = converter.f;
                converter.u = (rx_data[11] << 24) | (rx_data[12] << 16) | (rx_data[13] << 8) | rx_data[14];
                motor_status->current = converter.f;
                motor_status->error_code = (rx_data[15] << 24) | (rx_data[16] << 16) | (rx_data[17] << 8) | rx_data[18];
                motor_status->voltage = (rx_data[19] << 8) | rx_data[20];
                motor_status->temperature = (rx_data[21] << 8) | rx_data[22];
                motor_status->limit_flag = rx_data[23];
            }
            else
            {
                switch (rx_data[0])
                {
                case static_cast<uint8_t>(MotorFeedbackType::DATA1):
                {
                    motor_status->enable_flag = rx_data[1];
                    motor_status->motor_mode = rx_data[2];
                    FloatUintConverter converter;
                    converter.u = (static_cast<uint32_t>(rx_data[4]) << 24) |
                                  (static_cast<uint32_t>(rx_data[5]) << 16) |
                                  (static_cast<uint32_t>(rx_data[6]) << 8) |
                                  static_cast<uint32_t>(rx_data[7]);
                    motor_status->position = converter.f;
                    break;
                }
                case static_cast<uint8_t>(MotorFeedbackType::DATA2):
                {
                    motor_status->limit_flag = rx_data[1];
                    motor_status->temperature = (rx_data[2] << 8) | rx_data[3];
                    FloatUintConverter converter;
                    converter.u = (static_cast<uint32_t>(rx_data[4]) << 24) |
                                  (static_cast<uint32_t>(rx_data[5]) << 16) |
                                  (static_cast<uint32_t>(rx_data[6]) << 8) |
                                  static_cast<uint32_t>(rx_data[7]);
                    motor_status->velocity = converter.f;
                    break;
                }
                case static_cast<uint8_t>(MotorFeedbackType::DATA3):
                {
                    motor_status->voltage = (rx_data[2] << 8) | rx_data[3];
                    FloatUintConverter converter;
                    converter.u = (static_cast<uint32_t>(rx_data[4]) << 24) |
                                  (static_cast<uint32_t>(rx_data[5]) << 16) |
                                  (static_cast<uint32_t>(rx_data[6]) << 8) |
                                  static_cast<uint32_t>(rx_data[7]);
                    motor_status->current = converter.f;
                    break;
                }
                case static_cast<uint8_t>(MotorFeedbackType::DATA4):
                {
                    motor_status->error_code = (rx_data[4] << 24) | (rx_data[5] << 16) | (rx_data[6] << 8) | rx_data[7];
                }
                default:
                    break;
                }
            }
            break;
        }
        case static_cast<uint32_t>(CommandType_Rx::FUNC_CTRL):
        {
            uint8_t status = use_canfd_ ? rx_data[2] : rx_data[1];
            uint8_t op = use_canfd_ ? rx_data[1] : rx_data[0];
            if (status == static_cast<uint8_t>(ExecuteStatus::SUCCESS))
            {
                RCLCPP_INFO(logger, "Operation %u done successfully!", static_cast<unsigned>(op));
            }
            else
            {
                RCLCPP_ERROR(logger, "Operation %u done failed!", static_cast<unsigned>(op));
            }
            break;
        }
        case static_cast<uint32_t>(CommandType_Rx::PARAM_RW):
        {
            FloatUintConverter converter;

            uint8_t offset = use_canfd_ ? 1 : 0;
            uint8_t rw_mode = use_canfd_ ? rx_data[1] : rx_data[0];
            uint16_t param_addr = (rx_data[offset + 1] << 8) | rx_data[offset + 2];
            uint8_t type = rx_data[offset + 3];
            converter.u = (static_cast<uint32_t>(rx_data[offset + 4]) << 24) |
                          (static_cast<uint32_t>(rx_data[offset + 5]) << 16) |
                          (static_cast<uint32_t>(rx_data[offset + 6]) << 8) |
                          (static_cast<uint32_t>(rx_data[offset + 7]));

            const char *type_str = (type == 1) ? "(int)" : (type == 2) ? "(float)"
                                                                       : "(unknown)";

            if (rw_mode == static_cast<uint8_t>(OperationMethod::READ))
            {
                if (type == 0x01)
                {
                    RCLCPP_INFO(logger, "Read parameter %u %s, value: %d", param_addr, type_str, static_cast<int32_t>(converter.u));
                }
                else if (type == 0x02)
                {
                    RCLCPP_INFO(logger, "Read parameter %u %s, value: %f", param_addr, type_str, converter.f);
                }
            }
            else if (rw_mode == static_cast<uint8_t>(OperationMethod::WRITE))
            {
                if (type == 0x01)
                {
                    RCLCPP_INFO(logger, "Write parameter %u %s, value: %d", param_addr, type_str, static_cast<int32_t>(converter.u));
                }
                else if (type == 0x02)
                {
                    RCLCPP_INFO(logger, "Write parameter %u %s, value: %f", param_addr, type_str, converter.f);
                }
            }
            break;
        }
        case static_cast<uint32_t>(CommandType_Rx::DUBUG_PARAM):
        {
            FloatUintConverter converter;

            uint8_t offset = use_canfd_ ? 1 : 0;
            uint8_t rw_mode = use_canfd_ ? rx_data[1] : rx_data[0];
            uint16_t param_addr = (rx_data[offset + 1] << 8) | rx_data[offset + 2];
            uint8_t type = rx_data[offset + 3];
            converter.u = (static_cast<uint32_t>(rx_data[offset + 4]) << 24) |
                          (static_cast<uint32_t>(rx_data[offset + 5]) << 16) |
                          (static_cast<uint32_t>(rx_data[offset + 6]) << 8) |
                          (static_cast<uint32_t>(rx_data[offset + 7]));

            const char *type_str = (type == 1) ? "(int)" : (type == 2) ? "(float)"
                                                                       : "(unknown)";

            if (rw_mode == static_cast<uint8_t>(OperationMethod::READ))
            {
                if (type == 0x01)
                {
                    if (param_addr < static_cast<uint16_t>(motor_driver::DebugParamAddr::SERVO_MIX_KP))
                    {
                        std::string chars;
                        for (size_t i = 3; i < rx_data.size(); ++i)
                        {
                            chars += static_cast<char>(rx_data[i]);
                        }
                        RCLCPP_INFO(logger, "Read DEBUG parameter %u %s, value: %s ", param_addr, type_str,
                                    chars.c_str());
                    }
                    else
                    {
                        RCLCPP_INFO(logger, "Read DEBUG parameter %u %s, value: %d", param_addr, type_str, static_cast<int32_t>(converter.u));
                    }
                }
                else if (type == 0x02)
                {
                    RCLCPP_INFO(logger, "Read DEBUG parameter %u %s, value: %f", param_addr, type_str, converter.f);
                }
            }
            else if (rw_mode == static_cast<uint8_t>(OperationMethod::WRITE))
            {
                if (type == 0x01)
                {
                    RCLCPP_INFO(logger, "Write DEBUG parameter %u %s, value: %d", param_addr, type_str, static_cast<int32_t>(converter.u));
                }
                else if (type == 0x02)
                {
                    RCLCPP_INFO(logger, "Write DEBUG parameter %u %s, value: %f", param_addr, type_str, converter.f);
                }
            }
            break;
        }
        default:
            break;
        }
    }

    CanReceiverDriver::CanReceiverDriver(const std::string &device, bool use_canfd) : device_(device), use_canfd_(use_canfd)
    {
        RCLCPP_INFO(rclcpp::get_logger("CanReceiverDriver"), "Initializing CAN receiver for device: %s, use_canfd: %s", device.c_str(), use_canfd ? "true" : "false");
        receiver_ = std::make_unique<SocketCanReceiver>(device_, use_canfd);
        int fd = receiver_->get_native_handle();

        // 设置为非阻塞模式
        int flags = fcntl(fd, F_GETFL, 0);
        if (flags < 0)
        {
            RCLCPP_ERROR(rclcpp::get_logger("CanReceiverDriver"), "Failed to get socket flags");
        }
        if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) < 0)
        {
            RCLCPP_ERROR(rclcpp::get_logger("CanReceiverDriver"), "Failed to set socket to non-blocking mode");
        }
        auto filters = SocketCanReceiver::CanFilterList::ParseFilters("0x00000000~0xFFFFFFFF");
        receiver_->SetCanFilters(filters);
        RCLCPP_INFO(rclcpp::get_logger("CanReceiverDriver"), "CAN filters set successfully");

        received_motor_ids_per_buffer_[0].clear();
        received_motor_ids_per_buffer_[1].clear();
    }
    const ProtocolEntry protocol_table[] = {
        {"JRSJ", static_cast<uint8_t>(BUTTONSTATUS::ENTRY_TEACH)},
        {"TCSJ", static_cast<uint8_t>(BUTTONSTATUS::EXIT_TEACH)},
        {"GJFX", static_cast<uint8_t>(BUTTONSTATUS::TEACH_REPEAT)},
    };

    bool CanReceiverDriver::receive_once_nonblocking()
    {
        try
        {
            CanId can_id;
            uint8_t motor_id;
            int write_index = 1 - current_buffer_index_.load();

            std::shared_ptr<Motor_Status> status;
            {
                std::unique_lock lock(motor_status_mutex_);
                std::vector<uint8_t> data;

                if (use_canfd_)
                {
                    std::array<uint8_t, 64> tmp;
                    can_id = receiver_->receive_fd(tmp.data(), std::chrono::milliseconds(0));
                    data.assign(tmp.begin(), tmp.begin() + can_id.length());
                }
                else
                {
                    std::array<uint8_t, 8> tmp;
                    can_id = receiver_->receive(tmp.data(), std::chrono::milliseconds(0));
                    data.assign(tmp.begin(), tmp.end());
                }
                uint8_t gripper_id = can_id.identifier() & 0x000000FF;
                if (gripper_id > 6)
                {
                    RCLCPP_INFO(rclcpp::get_logger("CanReceiverDriver"), "button_id:%d", gripper_id);
                }

                if (gripper_id == 0x8F)
                {
                    uint8_t key[5] = {data[0], data[1], data[2], data[3], '\0'};
                    // 遍历哈希表进行匹配
                    for (uint8_t i = 0; i < PROTOCOL_COUNT; ++i)
                    {
                        if (memcmp(protocol_table[i].code, key, sizeof(key)) == 0)
                        {
                            button_status_rec = protocol_table[i].description;
                        }
                    }
                    if (button_status_rec != last_status_rec_)
                    {
                        if (button_callback_)
                        {
                            button_callback_(button_status_rec);
                        }
                        if (button_status_rec == static_cast<uint8_t>(motor_driver::BUTTONSTATUS::TEACH_REPEAT))
                        {
                            // 复现模式：触发一次后清零，允许下次重复触发
                            last_status_rec_ = 0;
                        }
                        else
                        {
                            // 普通模式：直接记录状态
                            last_status_rec_ = button_status_rec;
                        }
                        cur_status_rec_ = button_status_rec;
                    }
                    RCLCPP_INFO(rclcpp::get_logger("CanReceiverDriver"), "button_status:%d", button_status_rec);
                }
                else
                {
                    motor_id = can_id.identifier() & 0x000000FF;
                    if (motor_status_map_[write_index].find(motor_id) == motor_status_map_[write_index].end())
                    {
                        motor_status_map_[write_index][motor_id] = std::make_shared<Motor_Status>();
                    }
                    status = motor_status_map_[write_index][motor_id];
                    CanReceiverParser::parse(can_id, data, use_canfd_, status, rclcpp::get_logger("can_receiver_driver"));
                    received_motor_ids_per_buffer_[write_index].insert(motor_id);
                    RCLCPP_DEBUG(rclcpp::get_logger("CanReceiverDriver"),
                                 "Received motor ID: %d (buffer %d, %lu/%d)", motor_id, write_index,
                                 received_motor_ids_per_buffer_[write_index].size(), motor_driver::MOTOR_NUM);
                    if (received_motor_ids_per_buffer_[write_index].size() == motor_driver::MOTOR_NUM)
                    {
                        current_buffer_index_.store(write_index);
                        received_motor_ids_per_buffer_[write_index].clear();
                        RCLCPP_DEBUG(rclcpp::get_logger("CanReceiverDriver"), "All motor statuses recieved, switching buffer to index %d", write_index);
                    }
                }
            }

            return true;
        }
        catch (const SocketCanTimeout &)
        {
            return false; // 非阻塞读取的正常现象
        }
        catch (const std::system_error &e)
        {
            // 明确过滤 EAGAIN/EWOULDBLOCK 错误（非阻塞模式的正常现象）
            if (e.code().value() == EAGAIN || e.code().value() == EWOULDBLOCK)
            {
                return false;
            }
            RCLCPP_ERROR(rclcpp::get_logger("CanReceiverDriver"), "CAN receiver fatal error: %s", e.what());
            throw; // 重新抛出非预期错误
        }
        catch (const std::runtime_error &e)
        {
            if (std::strstr(e.what(), "Resource temporarily unavailable") != nullptr)
            {
                return false;
            }
            RCLCPP_ERROR(rclcpp::get_logger("CanReceiverDriver"), "CAN receiver fatal error: %s", e.what());
            throw; // 重新抛出非预期错误
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("CanReceiverDriver"), "Unexpected error: %s", e.what());
            throw;
        }
    }

    void CanReceiverDriver::run_receive_loop()
    {
        rclcpp::Rate rate(1000);
        RCLCPP_INFO(rclcpp::get_logger("can_receiver_driver"), "Starting non-blocking CAN receive loop");
        while (rclcpp::ok())
        {
            bool received = receive_once_nonblocking();
            if (!received)
            {
                RCLCPP_DEBUG(rclcpp::get_logger("can_receiver_driver"), "No can frame received");
            }
            rate.sleep();
        }
        RCLCPP_INFO(rclcpp::get_logger("can_receiver_driver"), "Exiting non-blocking CAN receive loop");
    }

    std::shared_ptr<Motor_Status> CanReceiverDriver::get_motor_status(uint8_t motor_id) const
    {
        std::shared_lock lock(motor_status_mutex_);
        int read_index = current_buffer_index_.load();
        auto it = motor_status_map_[read_index].find(motor_id);
        return it != motor_status_map_[read_index].end() ? it->second : nullptr;
    }
    uint8_t CanReceiverDriver::get_button_status() const
    {
        return cur_status_rec_;
    }

} // namespace motor_driver