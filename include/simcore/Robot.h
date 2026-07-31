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

    void SetPose(float x, float y, float theta);
    Pose2D GetPose() const;

    void SetRadius(float radius);
    float GetRadius() const;

  private:
    Pose2D pose_;
    float radius_;
    float linearVelocity_;
    float angularVelocity_;
};
} // namespace simcore