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

        spdlog::info("x:{:.2f} y:{:.2f} theta:{:.2f}", pose.x, pose.y, pose.theta);
    }

    simulation.Shutdown();

    return 0;
}