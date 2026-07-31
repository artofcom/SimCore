#pragma once

#include <memory>
#include <vector>

namespace simcore
{
class Robot;
class Obstacle;

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

  private:
    std::vector<std::shared_ptr<Robot>> robots_;
    std::vector<std::shared_ptr<Obstacle>> obstacles_;
};

} // namespace simcore