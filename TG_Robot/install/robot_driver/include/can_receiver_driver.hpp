#ifndef __CAN_RECEIVER_DRIVER_H__
#define __CAN_RECEIVER_DRIVER_H__

#include <array>
#include <map>
#include <string>
#include <memory>
#include <cstdint>
#include <shared_mutex>
#include <fcntl.h>
#include <stdexcept>
#include <common_defs.hpp>
#include "rclcpp/rclcpp.hpp"
#include "can_msgs/msg/frame.hpp"
#include "ros2_socketcan/socket_can_id.hpp"
#include "ros2_socketcan/socket_can_receiver.hpp"
#include "std_msgs/msg/string.hpp"
#include <std_msgs/msg/u_int8.hpp>
namespace motor_driver
{

    using namespace drivers::socketcan;

    // 电机数据结构体定义
    typedef struct
    {
        uint8_t enable_flag : 1;
        uint8_t motor_mode : 4;
        float position;

        uint8_t limit_flag : 1;
        uint16_t temperature : 10;
        float velocity;

        uint16_t voltage : 10;
        float current;

        uint32_t error_code;
    } Motor_Status;

    class CanReceiverParser
    {
    public:
        static void parse(const CanId &can_id, const std::vector<uint8_t> &rx_data, bool use_canfd, std::shared_ptr<Motor_Status> motor_status, rclcpp::Logger logger);
    };

    class CanReceiverDriver
    {
    public:
        explicit CanReceiverDriver(const std::string &device, bool use_canfd = false);
        void run_receive_loop();
        std::shared_ptr<Motor_Status> get_motor_status(uint8_t motor_id) const;
        uint8_t get_button_status() const;
        using ButtonCallback = std::function<void(uint8_t)>;

        void set_button_callback(ButtonCallback cb)
        {
            button_callback_ = std::move(cb);
        }

    protected:
        // 使用双重缓冲减少锁竞争
        std::map<uint8_t, std::shared_ptr<Motor_Status>> motor_status_map_[2];

        std::atomic<int> current_buffer_index_{0};

    private:
        std::string device_;
        bool use_canfd_;
        uint8_t button_status_rec = 0;
        uint8_t last_status_rec_ = 0;
        uint8_t cur_status_rec_ = 0;
        ButtonCallback button_callback_;

        mutable std::shared_mutex motor_status_mutex_;
        std::unordered_set<uint8_t> received_motor_ids_;
        std::unordered_map<int, std::unordered_set<uint8_t>> received_motor_ids_per_buffer_;
        std::unique_ptr<SocketCanReceiver> receiver_;
        bool receive_once_nonblocking();
    };

} // namespace motor_driver

#endif // __CAN_RECEIVER_DRIVER_H__