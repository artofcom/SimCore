#pragma once

#include "Pose2D.h"

namespace simcore
{
class Obstacle
{
  public:
    Obstacle();

    void SetPosition(float x, float y);

    Pose2D GetPose() const;

    void SetRadius(float radius);

    float GetRadius() const;

  private:
    Pose2D pose_;

    float radius_;
};
} // namespace simcore