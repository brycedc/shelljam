cmake_minimum_required(VERSION 3.22)
project(ShellJam)

# Sets standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Places binary in bin folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

## Depedencies
find_package(CURL REQUIRED) #libcurl4-openssl-dev

# Subdirectories
add_subdirectory(src)