#include <chrono>
#include <thread>

#include "simcore/Simulation.h"

int main()
{
    Simulation sim;

    sim.Initialize();

    for (int i = 0; i < 5; i++)
    {
        sim.Update(1.0f);
    }

    sim.Shutdown();

    return 0;
}