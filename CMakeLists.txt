cmake_minimum_required(VERSION 3.20)

project(SimCore)

set(CMAKE_CXX_STANDARD 20)

add_library(simcore
    src/Robot.cpp
    src/Simulation.cpp
)

target_include_directories(simcore
    PUBLIC
        include
)

add_executable(console_demo
    examples/console/main.cpp
)

target_link_libraries(console_demo
    PRIVATE
        simcore
)