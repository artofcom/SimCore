#include "simcore/Robot.h"
#include <cmath>

namespace simcore
{
Robot::Robot() = default;

void Robot::MoveForward(double distance)
{
    pose_.x += distance * std::cos(pose_.theta);
    pose_.y += distance * std::sin(pose_.theta);
}

void Robot::Turn(double radians)
{
    pose_.theta += radians;
}

const Pose2D& Robot::GetPose() const
{
    return pose_;
}
} // namespace simcore