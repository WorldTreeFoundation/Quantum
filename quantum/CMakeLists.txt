cmake_minimum_required(VERSION 3.26.0)
set(CMAKE_CXX_STANDARD 11)

# ###########################################################
# Project declaration
# ###########################################################
file(READ "include/quantum/Quantum.h" ver)

string(REGEX MATCH "VERSION_MAJOR ([0-9]*)" _ ${ver})
set(ver_major ${CMAKE_MATCH_1})

string(REGEX MATCH "VERSION_MINOR ([0-9]*)" _ ${ver})
set(ver_minor ${CMAKE_MATCH_1})

string(REGEX MATCH "VERSION_PATCH ([0-9]*)" _ ${ver})
set(ver_patch ${CMAKE_MATCH_1})

project(Quantum VERSION ${ver_major}.${ver_minor}.${ver_patch})
message("Quantum version: ${PROJECT_VERSION}")

# ###########################################################
# Create a library
# ###########################################################

# Generate the shared library from the library sources
add_library(quantum_library STATIC
    src/World.cpp
)
add_library(quantum::library ALIAS quantum_library)

target_include_directories(quantum_library
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# ###########################################################
# Create an executable
# ###########################################################

# Add an executable with the above sources
add_executable(quantum_binary
    src/main.cpp
)

# link the new quantum_library target with the quantum_binary target
target_link_libraries(quantum_binary
    PRIVATE
    quantum::library
)