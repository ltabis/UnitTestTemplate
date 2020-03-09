cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
project(WorshopUnitTest)

## Conan setup
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

## Enable Google test library
enable_testing()

## Setting flags for linux
if (UNIX)
    find_package(Threads)
    set(CMAKE_CXX_FLAGS "-g -lgcov --coverage")
endif()

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CoinFlipper.cpp
)

## Include headers to program
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

## Client executable
add_executable(WTU
    ${SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

# Tests

## Test sources
set (SRC_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/UnitTest_CoinFlipper.cpp
)

## Creating executable of unit tests
include(GoogleTest)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

## Test executable
add_executable(unit_tests
    ${SRC}
    ${SRC_TEST}
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp
)

target_link_libraries(unit_tests PUBLIC
    gtest
    CONAN_PKG::gtest
    ${CMAKE_THREAD_LIBS_INIT}
)
