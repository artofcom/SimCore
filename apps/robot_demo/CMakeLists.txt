add_executable(robot_demo
    main.cpp
    RobotNode.h
    RobotNode.cpp
)

target_link_libraries(robot_demo
    PRIVATE
        simcore
)