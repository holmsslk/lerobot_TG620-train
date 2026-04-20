#include <chrono>
#include <thread>
#include <memory>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "example_cpp/arm.hpp"  

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto arm = std::make_shared<Arm>();

    /**************************/
    // 1. RESET
    arm->ResetArm();
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 2. DISABLE
    arm->DisableArm();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 3. JOINT CONTROL
    arm->JointCtrlArm(4, 1);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 4. JOINT STOP
    arm->JointStop();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 5. MOVEJ
    std::vector<double> joint_angles = {0.0, 20.0, -20.0, 0, 0, 0};
    arm->MoveWithJointAngle(joint_angles);
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 6. MOVEL
    std::vector<double> pose = {0.1, 0.2, 0.3, 0, 0, 0};
    arm->MoveWithPoseGoal(pose);
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 7. TEACH
    arm->Teach();
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 8. TEACH STOP
    arm->TeachStop();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 9. TEACH REPEAT
    arm->TeachRepeat();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 10. GRIPPER CONTROL
    std::vector<double> gripper_cmd1 = {1, 100.0, 40.0, 100.0};
    arm->GripperControl(gripper_cmd1);

    std::vector<double> gripper_cmd2 = {2, 0x01, 0x06, 0x01, 0x03, 0x01, 0xF4, 0x78};
    arm->GripperControl(gripper_cmd2);

    // 11. ZERO POSITION SET
    arm->ZeroPositionSet();
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 12. BACK TO INITIAL
    arm->BackToInitial();
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 13. USER PARAM SET
    arm->UsrParamSet(1, 8, 170);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 14. USER PARAM GET
    uint8_t joint_id = 4;
    arm->UsrParamGet(joint_id);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 15. JOINT PRINT
    arm->JOINTPrint();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    /**************************/
    rclcpp::shutdown();
    return 0;
}

