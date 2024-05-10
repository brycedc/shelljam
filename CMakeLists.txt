cmake_minimum_required(VERSION 3.22)
project(ShellJam)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Sets standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Places binary in bin folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

## Depedencies
find_package(CURL REQUIRED) #libcurl4-openssl-dev

## Sets the include directory path
set(SHELLJAM_INCLUDE_DIR ${CMAKE_CURRENT_DIR}/include/shelljam/)

# Sets the root project path
set(PROJECTPATH ${CMAKE_SOURCE_DIR})
configure_file(include/shelljam/ProjectPath.hpp.in include/shelljam/ProjectPath.hpp)

# Adds include directory
include_directories(include ${CMAKE_BINARY_DIR}/include)

# Subdirectories
add_subdirectory(src)