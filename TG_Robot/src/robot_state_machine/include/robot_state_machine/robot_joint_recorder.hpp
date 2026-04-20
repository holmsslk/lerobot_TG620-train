#pragma once
#include <fstream>
#include <filesystem>
#include <sstream>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include <string>
#include <iomanip>
#include <chrono>
#include <queue>
class JointRecorder
{
public:
    JointRecorder(double record_rate_hz = 100.0);

    // 开始录制
    bool start(const std::string &file_path,
               const sensor_msgs::msg::JointState::SharedPtr &sample_msg);

    // 停止录制
    void stop();

    // 在 joint_states 回调中调用
    void enqueue(const sensor_msgs::msg::JointState::SharedPtr &msg);
    void writerLoop();
    trajectory_msgs::msg::JointTrajectory repeat(const std::string &txt_file_path);


    bool isRecording() const { return recording_; }

private:
    std::ofstream file_;
    bool recording_;
    rclcpp::Time last_record_time_;
    rclcpp::Time first_record_time_;
    std::string rec_file_path_;
    double record_period_; // 录制间隔 (秒)
    // 异步写线程
    std::thread writer_thread_;
    std::queue<sensor_msgs::msg::JointState::SharedPtr> msg_queue_;
    std::mutex queue_mutex_;
    std::condition_variable queue_cv_;
    bool stop_flag_;
};
