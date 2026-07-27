#include <iostream>
#include <chrono>
#include <thread>

#include "Simulation.h"

int main()
{
    Simulation sim;

    sim.Initialize();

    for (int i = 0; i < 5; i++)
    {
        sim.Update(1.0f);
    }

    sim.Shutdown();
}