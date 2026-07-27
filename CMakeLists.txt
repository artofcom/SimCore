cmake_minimum_required(VERSION 3.20)

project(SimCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Library
# -----------------------------
add_library(simcore
    src/Simulation.cpp
)

target_include_directories(simcore
    PUBLIC
        include
)

# -----------------------------
# Console Example
# -----------------------------
add_executable(console_demo
    examples/console/main.cpp
)

target_link_libraries(console_demo
    PRIVATE
        simcore
)

# -----------------------------
# Tests
# -----------------------------
enable_testing()

add_subdirectory(tests)