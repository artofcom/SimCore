#include "Simulation.h"
#include <iostream>

Simulation::Simulation() : m_tick(0) {
    
}

Simulation::~Simulation() {
    
}

void Simulation::Update(float dt)
{
    ++m_tick;

    std::cout
        << "[INFO] Tick : "
        << m_tick
        << " dt : "
        << dt
        << std::endl;

    if (m_tick == 1)
        std::cout << "[INFO] Robot Task Started\n";

    if (m_tick == 3)
        std::cout << "[INFO] Robot Task Completed\n";
}

void Simulation::Initialize() {}

void Simulation::Shutdown() {}

