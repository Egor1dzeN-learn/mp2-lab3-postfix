cmake_minimum_required(VERSION 3.24)
project(untitled2)

add_executable(main main.cpp test.cpp
        ../TPostfix/TPostfix.cpp)
include_directories(../src)
include_directories(../TPostfix)


target_link_libraries(main TStack)
target_link_libraries(main gtest_main gmock_main)
target_link_libraries(main TPostfix)