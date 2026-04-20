#include <chrono>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#include "rclcpp/rclcpp.hpp"
#include "robot_interfaces/srv/sdk_recv.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"
#include "std_msgs/msg/u_int8_multi_array.hpp" 
#include "std_msgs/msg/float64_multi_array.hpp"

using namespace std::chrono_literals;
using SdkRecv = robot_interfaces::srv::SdkRecv;

enum WorkMode : int
{
    BACKTOSTART             = 0,
    DISABLE                 = 1,
    JOINTCONTROL            = 2,
    CARTESIAN               = 3,
    MOVEJ                   = 4,
    MOVEL                   = 5,
    MOVEC                   = 6,
    TEACH                   = 7,
    TEACHREPEAT             = 8,
    STATEOPERATION          = 9,
    LOADSTATE               = 10,
    BACKTOINITIAL           = 11,
    MOTORZEROPOSITIONSET    = 12,
    GRIPPERCONTROL          = 13,
    USERPARAMSET            = 14,
    USERPARAMGET            = 15,
    TEACHSTOP               = 16,
    JOINT_PRINT             = 17,
    JOINT_STOP              = 18
};

class Arm : public rclcpp::Node
{
public:
    Arm()
    : Node("arm_qt_cmd_cpp")
    {
        client_ = this->create_client<SdkRecv>("/sdk_cmd");

        while (!client_->wait_for_service(1s)) {
            RCLCPP_INFO(this->get_logger(), "Waiting for service...");
        }

        request_ = std::make_shared<SdkRecv::Request>();
    }

    void ResetArm()
    {
        request_->working_mode = BACKTOSTART;
        call_service();
    }

    void DisableArm()
    {
        request_->working_mode = DISABLE;
        call_service();
    }

    void JointCtrlArm(int joint_idx, int vel_dir)
    {
        request_->working_mode = JOINTCONTROL;
        request_->joint_idx = joint_idx;
        request_->vel_dir = vel_dir;
        call_service();
    }

    void JointStop()
    {
        request_->working_mode = JOINT_STOP;
        call_service();
    }

    void MoveWithJointAngle(const std::vector<double> &joint_angles)
    {
        if (joint_angles.size() != 6) {
            RCLCPP_ERROR(this->get_logger(), "joint_angles length invalid");
            return;
        }
        request_->working_mode = MOVEJ;
        request_->joint_angles_goal.data = joint_angles;
        call_service();
    }

    void MoveWithPoseGoal(const std::vector<double> &pose)
    {
        if (pose.size() != 6) {
            RCLCPP_ERROR(this->get_logger(), "pose length invalid");
            return;
        }
        request_->working_mode = MOVEL;
        request_->arm_pose_goal.data = pose;
        call_service();
    }

    void Teach()
    {
        request_->working_mode = TEACH;
        call_service();
    }

    void TeachStop()
    {
        request_->working_mode = TEACHSTOP;
        call_service();
    }

    void TeachRepeat()
    {
        request_->working_mode = TEACHREPEAT;
        call_service();
    }

    void GripperControl(const std::vector<double> &gripper_cmd)
    {
        if (gripper_cmd.empty()) {
            RCLCPP_ERROR(this->get_logger(), "gripper_cmd empty");
            return;
        }
        request_->gripper_type = static_cast<int>(gripper_cmd[0]);
        request_->working_mode = GRIPPERCONTROL;

        if (request_->gripper_type == 2) {
            request_->gripper_data.assign(gripper_cmd.begin() + 1, gripper_cmd.end());
        } else {
            request_->gripper_goal.data.assign(gripper_cmd.begin() + 1, gripper_cmd.end());
        }
        call_service();
    }

    void ZeroPositionSet()
    {
        request_->working_mode = MOTORZEROPOSITIONSET;
        call_service();
    }

    void BackToInitial()
    {
        request_->working_mode = BACKTOINITIAL;
        call_service();
    }

    void UsrParamSet(int motor_id, int command_type, double value)
    {
        request_->working_mode = USERPARAMSET;
        request_->usr_param.motor_id = motor_id;
        request_->usr_param.command_type = command_type;
        request_->usr_param.float_value = static_cast<float>(value);
        request_->usr_param.int_value = static_cast<int>(value);
        call_service();
    }

    void UsrParamGet(uint8_t joint_idx)
    {
        request_->working_mode = USERPARAMGET;
        request_->joint_idx = joint_idx;
        call_service();
    }

    void JOINTPrint()
    {
        request_->working_mode = JOINT_PRINT;
        auto result = call_service(true); // true 表示需要打印结果
        if (result) {
            auto resp = result.value();
            if (resp->success) {
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(3);
                oss << "当前关节角度: [";
                for (size_t i = 0; i < resp->cur_joint_angles.data.size(); ++i) {
                    oss << resp->cur_joint_angles.data[i];
                    if (i < resp->cur_joint_angles.data.size() - 1) oss << ", ";
                }
                oss << "]";
                RCLCPP_INFO(this->get_logger(), "%s", oss.str().c_str());

                RCLCPP_INFO(this->get_logger(),
                            "当前位姿 - x: %.3f, y: %.3f, z: %.3f, roll: %.3f, pitch: %.3f, yaw: %.3f",
                            resp->cur_pos.data[0], resp->cur_pos.data[1], resp->cur_pos.data[2],
                            resp->cur_pos.data[3], resp->cur_pos.data[4], resp->cur_pos.data[5]);
            } else {
                RCLCPP_ERROR(this->get_logger(), "服务调用失败");
            }
        }
    }

private:
    rclcpp::Client<SdkRecv>::SharedPtr client_;
    std::shared_ptr<SdkRecv::Request> request_;

    std::optional<std::shared_ptr<SdkRecv::Response>> call_service(bool return_response = false)
    {
        auto future = client_->async_send_request(request_);
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) ==
            rclcpp::FutureReturnCode::SUCCESS)
        {
            if (return_response) {
                return future.get();
            }
        } else {
            RCLCPP_ERROR(this->get_logger(), "Service call failed");
        }
        return std::nullopt;
    }
};

