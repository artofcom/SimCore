#include <iostream>
#include <chrono>
#include <thread>

#include "Simulation.h"

int main()
{
    Simulation simulation;

    constexpr float dt = 0.1f;

    while (true)
    {
        simulation.Update(dt);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}