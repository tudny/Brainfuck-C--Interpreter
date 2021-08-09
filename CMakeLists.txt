cmake_minimum_required(VERSION 3.15)
project(BF)

set(CMAKE_CXX_STANDARD 14)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif ()

set(SOURCE_FILES
        src/main.cpp
        src/brainfuck.cpp
        src/brainfuck.h)

add_executable(BF ${SOURCE_FILES})