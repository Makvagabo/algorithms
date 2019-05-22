cmake_minimum_required(VERSION 3.13)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        algorithms main.cpp

        Numerical/prng.cpp
        Numerical/examples.cpp
        Numerical/gcd.cpp
        Numerical/find_factors.cpp
        Numerical/find_primes.cpp
        Numerical/is_prime.cpp)