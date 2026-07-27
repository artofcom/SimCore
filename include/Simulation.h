#ifndef SIMULATION_H
#define SIMULATION_H

class Robot;

class Simulation {
private:
    int m_tick;
    Robot* robot_;

public:
    Simulation();
    ~Simulation();
    
    void Update(float dt);
};

#endif // SIMULATION_H