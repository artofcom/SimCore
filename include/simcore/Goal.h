#pragma once

#include "Pose2D.h"

namespace simcore
{
class Goal
{
  public:
    Goal();

    void SetPosition(float x, float y);

    const Pose2D& GetPose() const;

  private:
    Pose2D pose_;
};

} // namespace simcore