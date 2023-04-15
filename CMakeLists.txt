cmake_minimum_required(VERSION 3.24)
project(DumbDateLib)

set(CMAKE_CXX_STANDARD 17)

add_library(DumbDateLib dumb_date.cpp)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/b796f7d44681514f58a683a3a71ff17c94edb0c1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(main_test main_test.cpp)
target_link_libraries(main_test GTest::gtest_main)
target_link_libraries(main_test DumbDateLib)

include(GoogleTest)
gtest_discover_tests(main_test)
