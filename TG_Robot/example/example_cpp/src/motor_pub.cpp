#include "rclcpp/rclcpp.hpp"
#include "robot_interfaces/msg/robot_control_msg.hpp"

using std::placeholders::_1;

class MotorControlPublisher : public rclcpp::Node
{
public:
    MotorControlPublisher()
    : Node("motor_control_publisher")
    {
        publisher_ = this->create_publisher<robot_interfaces::msg::RobotControlMsg>("/motor_control_msg", 10);

        // 创建周期性定时器，10ms (100Hz)
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(10),
            std::bind(&MotorControlPublisher::timer_callback, this));

        // 初始化消息内容
        msg_.motor_enable_flag = {1, 1, 1, 1, 1, 1};
        msg_.motor_mode        = {5, 4, 4, 4, 4, 4};  // 速度模式
        msg_.position          = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        msg_.velocity          = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        msg_.effort.clear();

        RCLCPP_INFO(this->get_logger(), "Started motor_control_publisher node, sending velocity commands...");
    }

private:
    void timer_callback()
    {
        publisher_->publish(msg_);
        // RCLCPP_INFO(this->get_logger(), "Published: [%f, %f, %f, %f, %f, %f]",
        //             msg_.velocity[0], msg_.velocity[1], msg_.velocity[2],
        //             msg_.velocity[3], msg_.velocity[4], msg_.velocity[5]);
    }

    rclcpp::Publisher<robot_interfaces::msg::RobotControlMsg>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    robot_interfaces::msg::RobotControlMsg msg_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MotorControlPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

