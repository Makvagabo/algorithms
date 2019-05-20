cmake_minimum_required(VERSION 3.13)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        algorithms main.cpp

        Numerical/prng.cpp
        Numerical/examples.cpp
        Numerical/gcd.cpp
        Numerical/raise_to_power.cpp
        Numerical/find_factors.cpp)