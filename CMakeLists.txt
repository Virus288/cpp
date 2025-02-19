cmake_minimum_required(VERSION 3.10)

# Project name
project(MonstersClientApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

# Change build output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include headers
include_directories(include)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Include OpenSSL headers
include_directories(${OPENSSL_INCLUDE_DIR})

# Add executable target
add_executable(program 
    src/main.cpp 
    src/connections/auth.cpp 
    src/connections/communicator.cpp
    src/errors/errors.cpp
    src/modules/index.cpp 
    src/tools/logger.cpp 
)

# Link OpenSSL libraries (ensure both ssl and crypto are linked)
target_link_libraries(program OpenSSL::SSL OpenSSL::Crypto)

# Ensure that the project links the required OpenSSL libraries dynamically (libssl and libcrypto)
if(OPENSSL_FOUND)
    message(STATUS "Found OpenSSL: ${OPENSSL_VERSION}")
else()
    message(FATAL_ERROR "OpenSSL not found!")
endif()

target_compile_definitions(program PRIVATE CPPHTTPLIB_OPENSSL_SUPPORT)

