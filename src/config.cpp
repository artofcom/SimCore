#include "config.h"

#include <fstream>

#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

using json = nlohmann::json;

Config& Config::Instance()
{
    static Config instance;
    return instance;
}

bool Config::Load(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        spdlog::error("Failed to open config file: {}", filename);
        return false;
    }

    json j;
    file >> j;

    simulation.tickRate = j["simulation"]["tickRate"];
    simulation.logLevel = j["simulation"]["logLevel"];

    robot.speed = j["robot"]["speed"];

    spdlog::info("Config loaded successfully.");
    return true;
}