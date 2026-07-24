#include "../include/Simulation.h"
#include <iostream>



void Simulation::Update(float dt)
{
    ++m_tick;

    std::cout << "Tick : "
        << m_tick
        << "  dt : "
        << dt
        << std::endl;
}