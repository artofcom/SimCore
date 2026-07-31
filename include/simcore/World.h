#pragma once

#include "simcore/GoalController.h"
#include <memory>
#include <vector>

namespace simcore
{
class Robot;
class Obstacle;
class Goal;

class World
{
  public:
    void Update(double dt);

    // Robots
    void AddRobot(std::shared_ptr<Robot> robot);
    std::shared_ptr<Robot> GetRobot(size_t index) const;
    size_t GetRobotCount() const;

    // Obstacles.
    void AddObstacle(std::shared_ptr<Obstacle> obstacle);
    size_t GetObstacleCount() const;
    std::shared_ptr<Obstacle> GetObstacle(size_t index) const;

    bool CheckCollision(const std::shared_ptr<Robot>& robot) const;

    // Goal.
    void SetGoal(std::shared_ptr<Goal> goal);
    std::shared_ptr<Goal> GetGoal() const;

  private:
    std::vector<std::shared_ptr<Robot>> robots_;
    std::vector<std::shared_ptr<Obstacle>> obstacles_;
    std::shared_ptr<Goal> goal_;
    GoalController goalController_;

    void UpdateRobot(const std::shared_ptr<Robot>& robot, double dt);
};

} // namespace simcore