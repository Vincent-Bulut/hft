cmake_minimum_required(VERSION 3.20)

project(hft VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(hft_lib
        src/pricing.cpp
        src/derivatives.cpp
)

target_include_directories(hft_lib PUBLIC include)

add_executable(hft
        src/main.cpp
)

target_link_libraries(hft PRIVATE hft_lib)