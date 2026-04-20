#ifndef __ROBOT_CAN_DRIVER_HPP__
#define __ROBOT_CAN_DRIVER_HPP__

#include "can_sender_driver.hpp"
#include "can_receiver_driver.hpp"
#include "ros2_socketcan/socket_can_sender.hpp"
#include "ros2_socketcan/socket_can_receiver.hpp"
#include "rclcpp/rclcpp.hpp"
#include <memory>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <atomic>

namespace motor_driver
{

    class RobotCanDriver : public CanReceiverDriver, public CanSenderDriver
    {
    public:
        explicit RobotCanDriver(const std::string &device, bool use_canfd = true);
        ~RobotCanDriver();

        using CanReceiverDriver::get_button_status;
        using CanReceiverDriver::get_motor_status;
        void start_receive();
        void stop_receive();

        void send_motor_control(
            uint8_t motor_id,
            MotorEnableMode enable_flag,
            MotorControlMode motor_mode,
            std::optional<float> pos = std::nullopt,
            std::optional<float> vel = std::nullopt,
            std::optional<float> eff = std::nullopt,
            uint8_t kp = 0, uint8_t kd = 0);
        void send_gripper_control(uint8_t gripper_type, double position, double velocity, double effort, const uint8_t *data, uint8_t data_length);
        void send_motor_feedback_request(uint8_t motor_id, std::optional<MotorFeedbackType> type = std::nullopt);
        void send_function_op_code(uint8_t motor_id, FuncOpCode op_code);
        void send_param_write(uint8_t motor_id, ParamAddr param_addr, int32_t param_data);
        void send_param_write(uint8_t motor_id, ParamAddr param_addr, float param_data);
        void send_param_read(uint8_t motor_id, ParamAddr param_addr);
        void send_debug_param_read(uint8_t motor_id, DebugParamAddr param_addr);
        void send_debug_param_write(uint8_t motor_id, DebugParamAddr param_addr, int32_t param_data);
        void send_debug_param_write(uint8_t motor_id, DebugParamAddr param_addr, float param_data);
        void send_button();

    private:
        std::thread receive_thread_;
        std::atomic<bool> running_{false};
        bool use_canfd_;
        std::unique_ptr<SocketCanSender> sender_;
    };

} // namespace motor_driver

#endif // __ROBOT_CAN_DRIVER_H__
