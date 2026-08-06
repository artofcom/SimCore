#include "simcore/Robot.h"
#include <cmath>

namespace simcore
{
Robot::Robot() : radius_(0.3f), linearVelocity_(0.0f), angularVelocity_(0.0f) {}

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
void Robot::SetPose(float x, float y, float theta)
{
    pose_.x = x;
    pose_.y = y;
    pose_.theta = theta;
}
void Robot::Update(double dt)
{
    pose_.theta += angularVelocity_ * dt;

    pose_.x += std::cos(pose_.theta) * linearVelocity_ * dt;
    pose_.y += std::sin(pose_.theta) * linearVelocity_ * dt;
}
void Robot::SetLinearVelocity(float velocity)
{
    linearVelocity_ = velocity;
}
void Robot::SetAngularVelocity(float angularVelocity)
{
    angularVelocity_ = angularVelocity;
}
void Robot::Stop()
{
    linearVelocity_ = 0.0f;
}

void Robot::SetRadius(float radius)
{
    radius_ = radius;
}
float Robot::GetRadius() const
{
    return radius_;
}
} // namespace simcore