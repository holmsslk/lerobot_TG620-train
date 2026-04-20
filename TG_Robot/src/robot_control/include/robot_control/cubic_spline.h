#ifndef __CUBIC_SPLINE_H__
#define __CUBIC_SPLINE_H__
#include "rclcpp/rclcpp.hpp"
#include "control_msgs/action/follow_joint_trajectory.hpp"
class cubicSpline
{
public:
    typedef enum _BoundType
    {
        BoundType_First_Derivative,
        BoundType_Second_Derivative
    } BoundType;

public:
    cubicSpline();
    ~cubicSpline();

    void initParam();
    void releaseMem();

    void Traj_Generate(const std::shared_ptr<const control_msgs::action::FollowJointTrajectory_Goal> &goal,
                       std::vector<std::vector<double>> &positions_list,
                       std::vector<std::vector<double>> &velocity_list,
                       std::vector<double> &time_list);

protected:
    bool loadData(const double *x_data, const double *y_data, int count, double bound1, double bound2, BoundType type);
    bool getYbyX(double &x_in, double &y_out, double &vel, double &acc);
    void Interpolation(const std::vector<double> &time_from_start,
                       const std::vector<double> &positions,
                       double rate,
                       double max_time,
                       std::vector<double> &p_out,
                       std::vector<double> &v_out,
                       std::vector<double> &a_out);
    bool spline(BoundType type);

protected:
    double *x_sample_, *y_sample_;
    double *M_;
    int sample_count_;
    double bound1_, bound2_;
    std::vector<std::vector<double>> p_joint_;
    std::vector<std::vector<double>> v_joint_;
    std::vector<std::vector<double>> a_joint_;
    std::vector<double> time_from_start;
    std::vector<double> time_after_spline;
    int dof = 6; // 机械臂关节数
};

#endif /* __CUBIC_SPLINE_H__ */