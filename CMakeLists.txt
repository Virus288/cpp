cmake_minimum_required(VERSION 3.10)

# Project name
project(MyMovementApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Change build output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# Add executable target
add_executable(program main.cpp movement/movement.cpp)
