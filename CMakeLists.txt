cmake_minimum_required(VERSION 3.13)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    algorithms main.cpp
    Numerical/lcg.cpp Numerical/lcg.h
    Numerical/examples.cpp Numerical/examples.h
)