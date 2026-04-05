cmake_minimum_required(VERSION 3.20)
project(hft)

set(CMAKE_CXX_STANDARD 17)

add_executable(hft
        derivatives.cpp
        main.cpp
)