#include <chrono>
#include <thread>

#include "simcore/Goal.h"
#include "simcore/Robot.h"
#include "simcore/Simulation.h"
#include <spdlog/spdlog.h>

int main()
{
    simcore::Simulation simulation;

    simulation.Initialize();

    auto& world = simulation.GetWorld();

    auto goal = std::make_shared<simcore::Goal>();
    goal->SetPosition(5.0f, 5.0f);
    world.SetGoal(goal);

    auto robot = world.GetRobot(0);
    robot->SetPose(0.0f, 0.0f, 0.0f); // 있다면 호출

    for (int i = 0; i < 100; ++i)
    {
        simulation.Update(0.1);

        auto pose = robot->GetPose();

        spdlog::info("x:{:.2f} y:{:.2f} theta:{:.2f}", pose.x, pose.y, pose.theta);
    }

    simulation.Shutdown();

    return 0;
}