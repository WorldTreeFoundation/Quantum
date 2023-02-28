cmake_minimum_required(VERSION 3.26.0)
set(CMAKE_CXX_STANDARD 11)

project(Quantum)

# ###########################################################
# Create a library
# ###########################################################

# Generate the shared library from the library sources
add_library(quantum_library STATIC
    src/Quantum.cpp
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