cmake_minimum_required(VERSION 3.6)
project(AdventOfCode2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Day2/main.cpp)
add_executable(AdventOfCode2015 ${SOURCE_FILES} Day2/input.txt)

set(RESOURCE_FILES Day2/input.txt)

set_target_properties(AdventOfCode2015 PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_FRAMEWORK_IDENTIFIER org.cmake.AdventOfCode2015
        RESOURCE "${RESOURCE_FILES}"
        )