cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

message(${PROJECT_NAME})
add_subdirectory(src)
add_subdirectory(TPostfix)
add_subdirectory(lib/googletest-main)
add_subdirectory(test)