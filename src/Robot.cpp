#include "simcore/Robot.h"
#include <cmath>

namespace simcore
{
Robot::Robot() : velocity_(0.0f) {}

void Robot::MoveForward(double distance)
{
    pose_.x += distance * std::cos(pose_.theta);
    pose_.y += distance * std::sin(pose_.theta);
}

void Robot::Turn(double radians)
{
    pose_.theta += radians;
}

Pose2D Robot::GetPose() const
{
    return pose_;
}

void Robot::Update(double dt)
{
    pose_.x += velocity_ * dt;
}
void Robot::SetLinearVelocity(float velocity)
{
    velocity_ = velocity;
}
void Robot::Stop()
{
    velocity_ = 0.0f;
}

} // namespace simcore