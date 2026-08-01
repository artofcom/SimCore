#include "simcore/Simulation.h"
#include "config.h"
#include "simcore/Robot.h"
#include "simcore/World.h"
#include "simcore/Goal.h"
#include <spdlog/spdlog.h>
#include "simcore/Obstacle.h"

namespace simcore
{
Simulation::Simulation() : m_tick(0) {}

Simulation::~Simulation() = default;

void Simulation::Initialize()
{
    spdlog::info("Simulation initialized.");

   // Config::Instance().Load("config/config.json");

   Config::Instance().Load(
        "/home/artofcom/workspace/SimCore/config/config.json");

    spdlog::info("Robot speed: {}", Config::Instance().robot.speed);

    auto robot = std::make_shared<Robot>();
    robot->SetLinearVelocity(1.0f);
    robot->SetAngularVelocity(0.5f);
    // robot->SetPose(0.0f, 0.0f, 0.0f);

    world_.AddRobot(robot);

    // adding test obstacles.
    auto obstacle = std::make_shared<Obstacle>();
    obstacle->SetPosition(3.0f, 1.5f);
    obstacle->SetRadius(0.5f);
    world_.AddObstacle(obstacle);

    auto obstacle2 = std::make_shared<Obstacle>();
    obstacle2->SetPosition(-2.0f, -1.0f);
    obstacle2->SetRadius(0.7f);
    world_.AddObstacle(obstacle2);
}

void Simulation::Update(float dt)
{
    world_.Update(dt);

    // Demo lines.
    ++m_tick;
    spdlog::info("Tick: {}, dt: {}", m_tick, dt);

    if (m_tick == 1)
        spdlog::info("[INFO] Robot Task Started\n");

    if (m_tick == 3)
        spdlog::info("[INFO] Robot Task Completed\n");
}

void Simulation::Shutdown()
{
    spdlog::info("Simulation shutdown.");
}

World& Simulation::GetWorld()
{
    return world_;
}

const Pose2D& Simulation::GetRobotPose(size_t index) const
{
    if (index >= world_.GetRobotCount())
        throw std::out_of_range("Robot index out of range.");
    
    return world_.GetRobot(index)->GetPose();
}

void Simulation::SetGoal(float x, float y)
{
    auto goal = std::make_shared<Goal>();

    goal->SetPosition(x, y);

    world_.SetGoal(goal);
}
const Pose2D& Simulation::GetGoalPose() const
{
    return world_.GetGoal()->GetPose();
}

bool Simulation::HasGoal() const
{
    return world_.GetGoal() != nullptr;
}

size_t Simulation::GetObstacleCount() const
{
    return world_.GetObstacleCount();
}

std::shared_ptr<Obstacle> Simulation::GetObstacle(size_t index) const
{
    return world_.GetObstacle(index);
}

} // namespace simcore