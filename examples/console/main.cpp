#include <chrono>
#include <thread>

#include "simcore/Robot.h"
#include "simcore/Simulation.h"
#include <spdlog/spdlog.h>

int main()
{
    simcore::Simulation simulation;

    simulation.Initialize();

    auto& world = simulation.GetWorld();

    for (int i = 0; i < 10; ++i)
    {
        simulation.Update(1.0f);

        auto robot = world.GetRobot(0);

        auto pose = robot->GetPose();

        spdlog::info("Robot Position : ({}, {})", pose.x, pose.y);
    }

    simulation.Shutdown();

    return 0;
}