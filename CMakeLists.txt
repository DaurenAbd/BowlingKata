cmake_minimum_required(VERSION 3.10)
project(Bowling)

set(CMAKE_CXX_STANDARD 11)

set(GTEST_DIR lib/googletest)

add_subdirectory(${GTEST_DIR})

include_directories(${GTEST_DIR}/googletest/include)
include_directories(${GTEST_DIR}/googlemock/include)

add_executable(Bowling main.cpp tests.cpp Bowling.cpp Bowling.h)

target_link_libraries(Bowling gtest gtest_main)