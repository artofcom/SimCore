#pragma once

#include <memory>

namespace simcore
{

class Robot;
class Goal;

class GoalController
{
  public:
    void Update(const std::shared_ptr<Robot>& robot, const std::shared_ptr<Goal>& goal, double dt);
};

} // namespace simcore