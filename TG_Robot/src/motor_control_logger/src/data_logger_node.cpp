#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <robot_interfaces/msg/robot_control_msg.hpp>

#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

class DataLogger : public rclcpp::Node
{
public:
    DataLogger()
        : Node("data_logger")
    {
        // 打开两个日志文件
        joint_file_.open("joint_log.txt");
        if (!joint_file_.is_open())
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to open joint_log.txt");
        }

        // joint_states 订阅
        joint_sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "/joint_states", 10,
            std::bind(&DataLogger::joint_callback, this, std::placeholders::_1));

        RCLCPP_INFO(this->get_logger(), "Data logger started for motor and joint topics");
    }

private:
    std::ofstream motor_file_;
    std::ofstream joint_file_;

    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_sub_;

    void joint_callback(const sensor_msgs::msg::JointState::ConstSharedPtr msg)
    {
        double t_joint = msg->header.stamp.sec + msg->header.stamp.nanosec * 1e-9;

        if (joint_file_.is_open())
        {
            joint_file_ << "=== JointState ===" << std::endl;
            joint_file_ << "  time: " << std::fixed << std::setprecision(5) << t_joint << "s" << std::endl;

            joint_file_ << "  names: ";
            for (auto &n : msg->name)
                joint_file_ << n << " ";
            joint_file_ << std::endl;

            joint_file_ << "  positions: ";
            for (auto v : msg->position)
                joint_file_ << v << " ";
            joint_file_ << std::endl;

            if (!msg->velocity.empty())
            {
                joint_file_ << "  velocities: ";
                for (auto v : msg->velocity)
                    joint_file_ << v << " ";
                joint_file_ << std::endl;
            }

            if (!msg->effort.empty())
            {
                joint_file_ << "  effort: ";
                for (auto v : msg->effort)
                    joint_file_ << v << " ";
                joint_file_ << std::endl;
            }

            joint_file_ << "-----------------------------" << std::endl;
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DataLogger>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
