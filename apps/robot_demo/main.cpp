#include <iostream>
#include <Simulation.h>

int main()
{
    Simulation sim;

    sim.Update(1.0f);

    std::cout << "Robot Demo started.." << std::endl;
    return 0;
}