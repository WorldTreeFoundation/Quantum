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
    src/Quantum.cpp
    src/World.cpp
)
add_library(quantum::library ALIAS quantum_library)

target_include_directories(quantum_library
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
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

# ###########################################################
# Unit tests
# ###########################################################

add_subdirectory(3rd_party/google-test)

# enable CTest testing
enable_testing()

# Add a testing executable
set(UNIT_TEST unit_tests)
add_executable(${UNIT_TEST}
    tests/unit/wave_function_tests.cpp
    tests/unit/quant_tests.cpp
)

target_link_libraries(${UNIT_TEST}
    quantum_library
    GTest::GTest 
    GTest::Main
)

add_test(NAME ${UNIT_TEST} COMMAND ${UNIT_TEST})

add_custom_command(
     TARGET ${UNIT_TEST}
     COMMENT "Run tests"
     POST_BUILD 
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
     COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$"
)