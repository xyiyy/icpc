cmake_minimum_required(VERSION 3.2)
project(icpc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(output output/main.cpp)
add_executable(testrunner testrunner/main.cpp)
file(GLOB TASKS "src/*.cpp")
file(GLOB_RECURSE HEADERS "xyiyylib/*.hpp" )

add_executable(test ${TASKS} ${HEADERS})
