#include <gtest/gtest.h>
#include "robot_state_machine/robot_kinematics.hpp"
#include "robot_interfaces/msg/robot_control_msg.hpp"

using robot_interfaces::msg::RobotControlMsg;

constexpr int NUM_JOINTS = 6;
class RobotKinematicsTest : public ::testing::Test {
    protected:
        RobotKinematics rk;
};

TEST_F(RobotKinematicsTest, SingleJointVelocityValidIndex) {
    auto msg = rk.generate_joint_velocity_command(2, 1.5f);
    EXPECT_EQ(msg.velocity.size(), NUM_JOINTS);
    EXPECT_FLOAT_EQ(msg.velocity[2], 1.5f);
    for (int i = 0; i < NUM_JOINTS; ++i) {
        if (i != 2) {
            EXPECT_FLOAT_EQ(msg.velocity[i], 0.0f);
        }
    }
    EXPECT_EQ(msg.motor_enable_flag.size(), NUM_JOINTS);
    EXPECT_EQ(msg.motor_mode.size(), NUM_JOINTS);
}

TEST_F(RobotKinematicsTest, SingleJointVelocityInvalidIndex) {
    auto msg = rk.generate_joint_velocity_command(NUM_JOINTS, 2.0f);
    EXPECT_TRUE(msg.velocity.empty() || msg.velocity.size() == NUM_JOINTS);
}

TEST_F(RobotKinematicsTest, MultiJointVelocityValid) {
    std::vector<double> vels{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    auto msg = rk.generate_joint_velocity_command(vels);
    EXPECT_EQ(msg.velocity, vels);
    EXPECT_EQ(msg.motor_enable_flag.size(), NUM_JOINTS);
    EXPECT_EQ(msg.motor_mode.size(), NUM_JOINTS);
}

TEST_F(RobotKinematicsTest, MultiJointVelocityInvalid) {
    std::vector<double> vels{1.0, 2.0, 3.0};
    auto msg = rk.generate_joint_velocity_command(vels);
    EXPECT_TRUE(msg.velocity.empty() || msg.velocity.size() == NUM_JOINTS);
}
