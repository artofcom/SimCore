include(FetchContent)
cmake_minimum_required(VERSION 3.20)

project(SimCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# -----------------------------
# External Libraries
# -----------------------------
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.15.3
)

FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.12.0
)

FetchContent_MakeAvailable(json)

# -----------------------------
# Library
# -----------------------------
add_library(simcore
    src/Simulation.cpp
 "include/config.h" "src/config.cpp")

target_include_directories(simcore
    PUBLIC
        include
)

target_link_libraries(simcore
    PUBLIC
        spdlog::spdlog
        nlohmann_json::nlohmann_json
)

# -----------------------------
# Console Example
# -----------------------------
add_executable(console_demo
    examples/console/main.cpp
 "include/config.h" "src/config.cpp")

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

# -----------------------------
# Tests
# -----------------------------
enable_testing()

add_subdirectory(tests)