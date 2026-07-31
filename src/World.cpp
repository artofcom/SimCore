#include "simcore/World.h"
#include "simcore/Goal.h"
#include "simcore/Obstacle.h"
#include "simcore/Robot.h"
#include <cmath>
#include <spdlog/spdlog.h>

namespace simcore
{

void World::Update(double dt)
{
    for (auto& robot : robots_)
    {
        UpdateRobot(robot, dt);
    }
}

void World::UpdateRobot(const std::shared_ptr<Robot>& robot, double dt)
{
    if (CheckCollision(robot))
    {
        robot->Stop();

        spdlog::warn("Robot collided with obstacle.");

        return;
    }

    robot->Update(dt);
}

void World::AddRobot(std::shared_ptr<Robot> robot)
{
    robots_.push_back(robot);
}

size_t World::GetRobotCount() const
{
    return robots_.size();
}

std::shared_ptr<Robot> World::GetRobot(size_t index) const
{
    if (index >= robots_.size())
    {
        return nullptr;
    }
    return robots_[index];
}

void World::AddObstacle(std::shared_ptr<Obstacle> obstacle)
{
    obstacles_.push_back(obstacle);
}
size_t World::GetObstacleCount() const
{
    return obstacles_.size();
}
std::shared_ptr<Obstacle> World::GetObstacle(size_t index) const
{
    if (index < obstacles_.size())
        return obstacles_[index];

    return nullptr;
}
void World::SetGoal(std::shared_ptr<Goal> goal)
{
    goal_ = goal;
}
std::shared_ptr<Goal> World::GetGoal() const
{
    return goal_;
}
bool World::CheckCollision(const std::shared_ptr<Robot>& robot) const
{
    const Pose2D robotPose = robot->GetPose();
    const float robotRadius = robot->GetRadius();

    for (const auto& obstacle : obstacles_)
    {
        const Pose2D obstaclePose = obstacle->GetPose();
        const float obstacleRadius = obstacle->GetRadius();

        const float dx = robotPose.x - obstaclePose.x;
        const float dy = robotPose.y - obstaclePose.y;

        const float distanceSquared = dx * dx + dy * dy;

        const float radiusSum = robotRadius + obstacleRadius;

        if (distanceSquared < radiusSum * radiusSum)
        {
            return true;
        }
    }

    return false;
}
} // namespace simcore