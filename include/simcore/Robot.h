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

        const Pose2D& GetPose() const;

    private:
        Pose2D pose_;
    };
}