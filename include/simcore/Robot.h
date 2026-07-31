#pragma once

#include "Pose2D.h"

namespace simcore
{
class Robot
{
  public:
    Robot();

    void MoveForward(double distance);
    void Turn(double radians);
    void Update(double dt);
    void SetLinearVelocity(float velocity);
    void Stop();
    void SetAngularVelocity(float angularVelocity);

    Pose2D GetPose() const;

  private:
    Pose2D pose_;
    float linearVelocity_;
    float angularVelocity_;
};
} // namespace simcore