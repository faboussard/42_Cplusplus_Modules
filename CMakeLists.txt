cmake_minimum_required(VERSION 3.28)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(module_00/ex00/ClapTrap.hpp)

add_executable(cpp
        module_03/ex00/main.cpp
        module_03/ex00/ClapTrap.cpp)
