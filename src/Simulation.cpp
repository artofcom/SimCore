#include "Simulation.h"
#include <spdlog/spdlog.h>

Simulation::Simulation() : m_tick(0) {}

Simulation::~Simulation() {}

void Simulation::Update(float dt)
{
    ++m_tick;

     spdlog::info("Tick: {}, dt: {}", m_tick, dt);

    if (m_tick == 1)
         spdlog::info("[INFO] Robot Task Started\n");

    if (m_tick == 3)
         spdlog::info("[INFO] Robot Task Completed\n");
}

void Simulation::Initialize() 
{
    spdlog::info("Simulation initialized.");
}

void Simulation::Shutdown()
{
    spdlog::info("Simulation shutdown.");
}
