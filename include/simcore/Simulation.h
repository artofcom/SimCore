#pragma once

#include "World.h"

namespace simcore
{
class Simulation
{
  private:
    int m_tick;

    World world_;

  public:
    Simulation();
    ~Simulation();

    void Initialize();

    void Update(float dt);

    void Shutdown();

    World& GetWorld();
};
} // namespace simcore
