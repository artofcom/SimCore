cmake_minimum_required(VERSION 3.20)

project(SimCore LANGUAGES CXX)

# ============================================================
# C++
# ============================================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================================================
# FetchContent
# ============================================================
include(FetchContent)

# spdlog
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.15.3
)
FetchContent_MakeAvailable(spdlog)

# nlohmann_json
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(json)

# ============================================================
# SimCore Library
# ============================================================
add_library(simcore
    src/Simulation.cpp
    src/config.cpp
    src/Robot.cpp
    src/World.cpp
)

target_include_directories(simcore
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(simcore
    PUBLIC
        spdlog::spdlog
        nlohmann_json::nlohmann_json
)

# ============================================================
# Console Demo
# ============================================================
add_executable(console_demo
    examples/console/main.cpp
)

target_link_libraries(console_demo
    PRIVATE
        simcore
)

# Copy config folder next to executable
add_custom_command(TARGET console_demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/config
        $<TARGET_FILE_DIR:console_demo>/config
)

# ============================================================
# Robot Demo
# ============================================================
add_subdirectory(apps/robot_demo)

# ============================================================
# Tests
# ============================================================
enable_testing()
add_subdirectory(tests)