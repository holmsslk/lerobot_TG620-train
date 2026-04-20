#include "robot_sdk.h"

class RobotSDK : public rclcpp ::Node
{
public:
    RobotSDK(const std::string &node_name) : Node(node_name), tf_buffer_(), tf_listener_(tf_buffer_)
    {
        RCLCPP_INFO(this->get_logger(), "robot_sdk node has been started!");

        subscriber_qt_cmd_ = this->create_service<robot_interfaces::srv::SdkRecv>("/sdk_cmd",
                                                                                  std::bind(&RobotSDK::working_mode_callback, this, std::placeholders::_1, std::placeholders::_2));
        // 对真实机械臂使用这段实时获取当前关节位置
        subscriber_joint_state_ = this->create_subscription<sensor_msgs::msg::JointState>("joint_states",
                                                                                          10, std::bind(&RobotSDK::joint_state_callback, this, std::placeholders::_1));

        mode_pub_ = this->create_publisher<std_msgs::msg::UInt8>("robotic_arm_control_mode", 10);
        movej_pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("movej_action", 10);
        movel_pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("movel_action", 10);
        motion_config_pub = this->create_publisher<std_msgs::msg::Float64MultiArray>("motion_config", 10);
        // movec_pub_            = this->create_publisher<robot_interfaces::msg::MoveCAction>("movec_action", 10);
        teach_pub_ = this->create_publisher<std_msgs::msg::String>("teach_action", 10);
        teachrepeat_pub_ = this->create_publisher<std_msgs::msg::String>("teachrepeat_action", 10);
        usr_param_pub = this->create_publisher<robot_interfaces::msg::GenericMotorParameter>("usr_param_set", 10);
        usr_param_get_pub = this->create_publisher<std_msgs::msg::UInt8>("motor_parameter_get", 10);
        jointctrl_pub_ = this->create_publisher<robot_interfaces::msg::KeyPressedAction>("jointctrl_action", 10);
        grip_publisher_ = this->create_publisher<robot_interfaces::msg::GripperControl>("gripper_action", 10);
        publisher_plan_state_ = this->create_publisher<std_msgs::msg::Bool>("plan_state", 10);
        recorded_joint_values.clear();
    }

private:
    rclcpp::Service<robot_interfaces::srv::SdkRecv>::SharedPtr subscriber_qt_cmd_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_joint_state_;
    rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr mode_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr movej_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr movel_pub_;
    rclcpp::Publisher<robot_interfaces::msg::KeyPressedAction>::SharedPtr jointctrl_pub_;
    // rclcpp::Publisher<robot_interfaces::msg::MoveCAction>::SharedPtr movec_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr teach_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr teachrepeat_pub_;
    rclcpp::Publisher<robot_interfaces::msg::GripperControl>::SharedPtr grip_publisher_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher_plan_state_; // successfully or unsuccessfully
    rclcpp::Publisher<robot_interfaces::msg::GenericMotorParameter>::SharedPtr usr_param_pub;
    rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr usr_param_get_pub;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr motion_config_pub;
    rclcpp::TimerBase::SharedPtr timer_;
    std::shared_ptr<moveit::planning_interface::MoveGroupInterface> arm;
    std::vector<double> joint_group_positions, current_joint_positions, current_joint_velocities, current_joint_efforts;

    geometry_msgs::msg::TransformStamped transform;
    std::vector<std::vector<double>> recorded_joint_values;
    std::mutex data_mutex_; // 保护共享数据

    bool is_recording = false;
    std_msgs::msg::UInt8 work_mode;
    std_msgs::msg::Float64MultiArray goal_info;
    tf2::BufferCore tf_buffer_;
    tf2_ros::TransformListener tf_listener_;
    void working_mode_callback(const std::shared_ptr<robot_interfaces::srv::SdkRecv::Request> request,
                               std::shared_ptr<robot_interfaces::srv::SdkRecv::Response> response)
    {

        work_mode.data = request->working_mode;
        mode_pub_->publish(work_mode);
        RCLCPP_INFO(this->get_logger(), "sdk_cmd topic:%d has been received", request->working_mode);
        switch (request->working_mode)
        {
        case JOINT_CONTROL:
        {
            robot_interfaces::msg::KeyPressedAction jnt_ctl_msg;
            int base_code = JOINT1_POSITIVE + (request->joint_idx - 1) * 2; // JOINT1_POSITIVE starts at 41
            jnt_ctl_msg.key_code = request->vel_dir == 1 ? base_code : base_code + 1;
            jnt_ctl_msg.is_pressed = true;
            jointctrl_pub_->publish(jnt_ctl_msg);
            RCLCPP_INFO(this->get_logger(), "mode: jnt_ctl published");
            break;
        }
        case CARTESIAN:
        {
            break;
        }
        case MOVE_J:
        {
            goal_info.data.resize(6, 0.0);
            for (int i = 0; i < 6; i++)
            {
                goal_info.data[i] = request->joint_angles_goal.data[i];
                RCLCPP_INFO(this->get_logger(), "Joint group positions [%d]: %lf", i + 1, goal_info.data[i]);
            }
            movej_pub_->publish(goal_info);
            RCLCPP_INFO(this->get_logger(), "mode: movj published");
            break;
        }
        case MOVE_L:
        {
            goal_info.data.resize(6, 0.0);
            for (int i = 0; i < 6; i++)
            {
                goal_info.data[i] = request->arm_pose_goal.data[i];
                RCLCPP_INFO(this->get_logger(), "pose group positions [%d]: %lf", i + 1, goal_info.data[i]);
            }
            movel_pub_->publish(goal_info);
            RCLCPP_INFO(this->get_logger(), "mode: movl published");
            break;
        }
        case MOVE_C:
        {

            break;
        }
        case TEACH:
        {
            std_msgs::msg::String file_name;
            file_name.data = "teach_example";
            teach_pub_->publish(file_name);
            RCLCPP_INFO(this->get_logger(), "mode: teach published");
            break;
        }
        case TEACH_STOP:
        {
            std_msgs::msg::String stop_msg;
            stop_msg.data = "stop";
            teach_pub_->publish(stop_msg);
            RCLCPP_INFO(this->get_logger(), "mode: teach stopped");
            break;
        }
        case TEACH_REPEAT:
        {
            std_msgs::msg::String file_name;
            file_name.data = "teach_example";
            teachrepeat_pub_->publish(file_name);
            RCLCPP_INFO(this->get_logger(), "mode: teach repeated");
            break;
        }
        case GRIPPER_CONTROL:
        {
            robot_interfaces::msg::GripperControl gripper_msg;
            gripper_msg.type = request->gripper_type;
            if (2 == gripper_msg.type)
            {
                gripper_msg.data = request->gripper_data;
            }
            else
            {
                gripper_msg.position = request->gripper_goal.data[0];
                gripper_msg.velocity = request->gripper_goal.data[1];
                gripper_msg.effort = request->gripper_goal.data[2];
            }

            grip_publisher_->publish(gripper_msg);
            break;
        }
        case POSE_PRINT:
        {
            response->cur_joint_angles.data.resize(6, 0.0);
            response->cur_pos.data.resize(6, 0.0);
            joint_group_positions.resize(6);
            for (size_t i = 0; i < 6; i++)
            {
                joint_group_positions[i] = current_joint_positions[i] * 180.0 / M_PI;
                response->cur_joint_angles.data[i] = joint_group_positions[i];
            }
            RCLCPP_INFO(this->get_logger(), "Joint angles_deg: %lf,%lf,%lf,%lf,%lf,%lf", joint_group_positions[0],
                        joint_group_positions[1], joint_group_positions[2], joint_group_positions[3],
                        joint_group_positions[4], joint_group_positions[5]);

            geometry_msgs::msg::TransformStamped transform;

            try
            {
                transform = tf_buffer_.lookupTransform("world", "Link6", tf2::TimePointZero);
                double x = transform.transform.translation.x;
                double y = transform.transform.translation.y;
                double z = transform.transform.translation.z;

                tf2::Quaternion quat(
                    transform.transform.rotation.x,
                    transform.transform.rotation.y,
                    transform.transform.rotation.z,
                    transform.transform.rotation.w);
                double roll, pitch, yaw;
                tf2::Matrix3x3(quat).getRPY(roll, pitch, yaw);
                response->cur_pos.data[0] = x;
                response->cur_pos.data[1] = y;
                response->cur_pos.data[2] = z;
                response->cur_pos.data[3] = roll * 180.0 / M_PI;
                response->cur_pos.data[4] = pitch * 180.0 / M_PI;
                response->cur_pos.data[5] = yaw * 180.0 / M_PI;
            }
            catch (const tf2::TransformException &ex)
            {
                RCLCPP_WARN(this->get_logger(), "Transform lookup exception: %s", ex.what());
            }

            break;
        }
        case USER_PARAM_SET:
        {
            const auto &usr_param = request->usr_param;
            usr_param_pub->publish(usr_param);
            break;
        }
        case USER_PARAM_GET:
        {
            std_msgs::msg::UInt8 usr_get_msg;
            usr_get_msg.data = request->joint_idx;
            usr_param_get_pub->publish(usr_get_msg);
            break;
        }
        case JOINT_STOP:
        {
            robot_interfaces::msg::KeyPressedAction jnt_ctl_msg;
            jnt_ctl_msg.is_pressed = false;
            jointctrl_pub_->publish(jnt_ctl_msg);
            break;
        }
        case SPEED_CONFIG:
        {
            const auto &motion_param = request->motion_config;
            motion_config_pub->publish(motion_param);
        }
        default:
        {
            break;
        }
        }
        response->success = true;
    }

    void joint_state_callback(sensor_msgs::msg::JointState::SharedPtr msg)
    {
        std::lock_guard<std::mutex> lock(data_mutex_);
        std::vector<std::string> joint_names = {"joint1", "joint2", "joint3", "joint4", "joint5", "joint6"};
        current_joint_positions.resize(joint_names.size(), 0.0);
        current_joint_efforts.resize(joint_names.size(), 0.0);
        current_joint_velocities.resize(joint_names.size(), 0.0);
        for (size_t i = 0; i < msg->name.size(); ++i)
        {
            for (size_t j = 0; j < joint_names.size(); ++j)
            {
                if (msg->name[i] == joint_names[j])
                {
                    current_joint_positions[j] = msg->position[i];
                    current_joint_velocities[j] = msg->velocity[i];
                    current_joint_efforts[j] = msg->effort[i];
                    break;
                }
            }
        }
    }

    void timer_callback()
    {
        recorded_joint_values.push_back(current_joint_positions);
    }
};

int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotSDK>("robot_sdk");
    // 等系统稳定
    rclcpp::sleep_for(std::chrono::seconds(1));
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
