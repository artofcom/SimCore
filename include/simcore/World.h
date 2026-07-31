#pragma once

#include <memory>
#include <vector>

namespace simcore
{
class Robot;

class World
{
  public:
    void AddRobot(std::shared_ptr<Robot> robot);

    void Update(double dt);

    std::shared_ptr<Robot> GetRobot(size_t index) const;

    size_t GetRobotCount() const;

  private:
    std::vector<std::shared_ptr<Robot>> robots_;
};

} // namespace simcore