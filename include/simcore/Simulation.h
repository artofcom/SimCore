#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation
{
  private:
    int m_tick;

  public:
    Simulation();
    ~Simulation();

    void Initialize();

    void Update(float dt);

    void Shutdown();
};

#endif // SIMULATION_H