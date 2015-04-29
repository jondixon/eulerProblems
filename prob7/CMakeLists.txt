cmake_minimum_required(VERSION 3.1)
project(prob7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(prob7 ${SOURCE_FILES})