#include "Simulation.h"
#include "Robot.h"
#include <iostream>

Simulation::Simulation() : m_tick(0) {
    // Create robot
    robot_ = new Robot(0.0, 0.0);
}

Simulation::~Simulation() {
    delete robot_;
}

void Simulation::Update(float dt)
{
    ++m_tick;

    std::cout << "Tick : "
        << m_tick
        << "  dt : "
        << dt
        << std::endl;

    // Set robot speed only (no angle)
    if (m_tick == 1) {
        robot_->setSpeed(2.0);
    } else if (m_tick == 2) {
        robot_->setSpeed(3.0);  // Different speed for demonstration
    } else if (m_tick == 3) {
        robot_->setSpeed(1.5);
    }

    // Update robot
    robot_->update(dt);
}

