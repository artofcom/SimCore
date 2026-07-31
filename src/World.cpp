#include "simcore/World.h"
#include "simcore/Robot.h"

namespace simcore
{

void World::Update(double dt)
{
    for (auto& robot : robots_)
    {
        robot->Update(dt);
    }
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

} // namespace simcore