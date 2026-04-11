cmake_minimum_required(VERSION 3.20)

project(hft VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 REQUIRED)

add_library(hft_lib
        src/pricing.cpp
        src/derivatives.cpp
)

target_include_directories(hft_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

pybind11_add_module(_core
        src/bindings.cpp
)

target_link_libraries(_core PRIVATE hft_lib)

set_target_properties(_core PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/hft
)

add_executable(hft
        src/main.cpp
)

target_link_libraries(hft PRIVATE hft_lib)