include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(simcore_tests
    LoggerTest.cpp
)

target_link_libraries(simcore_tests
    PRIVATE
        simcore
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(simcore_tests)