cmake_minimum_required(VERSION 3.13)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        algorithms main.cpp
        Numerical/pseudo-random_number_generator.cpp
        Numerical/examples.cpp
        )