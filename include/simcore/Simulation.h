#pragma once

#include "World.h"
#include "Pose2D.h"

namespace simcore
{
class Simulation
{
  private:
    int m_tick;

    World world_;

  public:
    Simulation();
    ~Simulation();

    void Initialize();

    void Update(float dt);

    void Shutdown();

    World& GetWorld();

    const Pose2D& GetRobotPose(size_t index = 0) const;

    void SetGoal(float x, float y);
    const Pose2D& GetGoalPose() const;

    bool HasGoal() const;

    size_t GetObstacleCount() const;

    std::shared_ptr<Obstacle> GetObstacle(size_t index) const;
};
} // namespace simcore
