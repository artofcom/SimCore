#include <iostream>
#include <numbers>

#include "simcore/Robot.h"

int main()
{
    simcore::Robot robot;

    robot.MoveForward(1.0);
    robot.Turn(std::numbers::pi / 2.0);
    robot.MoveForward(2.0);

    const auto& pose = robot.GetPose();

    std::cout
        << "x = " << pose.x
        << ", y = " << pose.y
        << ", theta = " << pose.theta
        << '\n';
}