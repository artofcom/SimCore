#include "simcore/World.h"
#include "simcore/Robot.h"

namespace simcore
{
void World::AddRobot(std::shared_ptr<Robot> robot)
{
    robots_.push_back(robot);
}

void World::Update(double dt)
{
    for (auto& robot : robots_)
    {
        robot->Update(dt);
    }
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
} // namespace simcore