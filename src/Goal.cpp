#include "simcore/Goal.h"

namespace simcore
{
Goal::Goal() {}

void Goal::SetPosition(float x, float y)
{
    pose_.x = x;
    pose_.y = y;
}

const Pose2D& Goal::GetPose() const
{
    return pose_;
}
} // namespace simcore
