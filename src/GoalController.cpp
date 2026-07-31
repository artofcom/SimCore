#include "simcore/GoalController.h"

#include <cmath>

#include "simcore/Goal.h"
#include "simcore/Pose2D.h"
#include "simcore/Robot.h"
#include <spdlog/spdlog.h>

namespace simcore
{

namespace
{
constexpr float kLinearVelocity = 1.0f;
constexpr float kAngularGain = 2.0f;
constexpr float kGoalTolerance = 0.1f;

float NormalizeAngle(float angle)
{
    while (angle > M_PI)
    {
        angle -= static_cast<float>(2.0 * M_PI);
    }

    while (angle < -M_PI)
    {
        angle += static_cast<float>(2.0 * M_PI);
    }

    return angle;
}
} // namespace

void GoalController::Update(const std::shared_ptr<Robot>& robot, const std::shared_ptr<Goal>& goal,
                            double /*dt*/)
{
    if (!robot || !goal)
    {
        return;
    }

    const Pose2D& robotPose = robot->GetPose();
    const Pose2D& goalPose = goal->GetPose();

    const float dx = goalPose.x - robotPose.x;
    const float dy = goalPose.y - robotPose.y;

    const float distance = std::sqrt(dx * dx + dy * dy);

    if (distance < kGoalTolerance)
    {
        robot->SetLinearVelocity(0.0f);
        robot->SetAngularVelocity(0.0f);
        return;
    }

    const float desiredHeading = std::atan2(dy, dx);

    const float headingError = NormalizeAngle(desiredHeading - robotPose.theta);

    robot->SetLinearVelocity(kLinearVelocity);
    robot->SetAngularVelocity(kAngularGain * headingError);

    spdlog::info("Heading Error: {:.2f}", headingError);
}

} // namespace simcore