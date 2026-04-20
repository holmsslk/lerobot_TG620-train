#ifndef __CAN_SENDER_DRIVER_H__
#define __CAN_SENDER_DRIVER_H__

#include <array>
#include <memory>
#include <cstdint>
#include <vector>
#include <optional>
#include <common_defs.hpp>
#include <mutex>
#include "ros2_socketcan/socket_can_id.hpp"
#include "ros2_socketcan/socket_can_sender.hpp"

namespace motor_driver
{

    using namespace drivers::socketcan;

    typedef struct
    {
        std::unique_ptr<CanId> canid;
        std::array<uint8_t, 8> data;
    } CanTxPacket;

    typedef struct
    {
        std::unique_ptr<CanId> canid;
        std::array<uint8_t, 64> data;
    } FdCanTxPacket;

    typedef struct
    {
        std::vector<uint8_t> data;
        std::unique_ptr<CanId> canid;
        bool use_canfd = false;
    } GenericCanTxPacket;

    class CanSenderDriver
    {
    public:
        explicit CanSenderDriver(const std::string &device, bool use_canfd = false);
        ~CanSenderDriver() = default;

        /* CAN */
        GenericCanTxPacket build_param_read(uint8_t motor_id, ParamAddr param_addr);
        GenericCanTxPacket build_param_write(uint8_t motor_id, ParamAddr param_addr, int32_t param_data);
        GenericCanTxPacket build_param_write(uint8_t motor_id, ParamAddr param_addr, float param_data);
        GenericCanTxPacket build_debug_param_read(uint8_t motor_id, DebugParamAddr param_addr);
        GenericCanTxPacket build_debug_param_write(uint8_t motor_id, DebugParamAddr param_addr, int32_t param_data);
        GenericCanTxPacket build_debug_param_write(uint8_t motor_id, DebugParamAddr param_addr, float param_data);
        GenericCanTxPacket build_motor_control(
            uint8_t motor_id,
            MotorEnableMode enable_flag,
            MotorControlMode motor_mode,
            std::optional<float> pos = std::nullopt,
            std::optional<float> vel = std::nullopt,
            std::optional<float> eff = std::nullopt,
            uint8_t kp = 0, uint8_t kd = 0);
        GenericCanTxPacket build_button_status();

        GenericCanTxPacket build_function_op(uint8_t motor_id, FuncOpCode func_code);
        GenericCanTxPacket build_motor_status_req(
            uint8_t motor_id,
            std::optional<uint8_t> data_type = std::nullopt,
            std::optional<uint8_t> motor_req_method = std::nullopt);
        GenericCanTxPacket build_gripper_control(uint8_t gripper_type, uint8_t position, uint8_t velocity, uint8_t effort, const uint8_t *data, uint8_t data_length);
        void send_packet(const GenericCanTxPacket &packet);

    private:
        std::unique_ptr<SocketCanSender> sender_;
        std::mutex send_mutex_;
        bool use_canfd_;
    };

} // namespace motor_driver

#endif // __CAN_SENDER_DRIVER_H__
