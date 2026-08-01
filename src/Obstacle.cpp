
#include "simcore/Obstacle.h"

namespace simcore
{
Obstacle::Obstacle() : radius_(0.0f) {}

void Obstacle::SetPosition(float x, float y)
{
    pose_.x = x;
    pose_.y = y;
}

const Pose2D& Obstacle::GetPose() const
{
    return pose_;
}

void Obstacle::SetRadius(float radius)
{
    radius_ = radius;
}

float Obstacle::GetRadius() const
{
    return radius_;
}
} // namespace simcore