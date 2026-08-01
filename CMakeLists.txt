cmake_minimum_required(VERSION 3.20)

project(SimCore LANGUAGES CXX)

# ============================================================
# C++
# ============================================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================================================
# Build Options
# ============================================================

option(SIMCORE_BUILD_EXAMPLES "Build examples" ON)
option(SIMCORE_BUILD_TESTS "Build tests" ON)

# ============================================================
# Dependencies
# ============================================================

find_package(spdlog REQUIRED)

include(FetchContent)

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
    src/Obstacle.cpp
    src/Goal.cpp
    src/GoalController.cpp
)

target_include_directories(simcore
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(simcore
    PUBLIC
        spdlog::spdlog_header_only
        nlohmann_json::nlohmann_json
)

# ============================================================
# Console Demo
# ============================================================

if(SIMCORE_BUILD_EXAMPLES)

    add_executable(console_demo
        examples/console/main.cpp
    )

    target_link_libraries(console_demo
        PRIVATE
            simcore
    )

    add_custom_command(TARGET console_demo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/config
            $<TARGET_FILE_DIR:console_demo>/config
    )

    add_subdirectory(apps/robot_demo)

endif()

# ============================================================
# Tests
# ============================================================

if(SIMCORE_BUILD_TESTS)

    enable_testing()

    add_subdirectory(tests)

endif()