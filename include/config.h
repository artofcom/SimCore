#pragma once

#include <string>

struct SimulationConfig
{
    int tickRate = 60;
    std::string logLevel = "info";
};

struct RobotConfig
{
    float speed = 2.0f;
};

class Config
{
  public:
    static Config& Instance();

    bool Load(const std::string& filename);

  public:
    SimulationConfig simulation;
    RobotConfig robot;

  private:
    Config() = default;
};