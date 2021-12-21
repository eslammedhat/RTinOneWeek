cmake_minimum_required(VERSION 3.10)

# set the project name
project(RayTracingOneWeek)


message(STATUS "hello $CMAKE_CURRENT_SOURCE_DIR")

set(RT_SRC_FILES 
    ./src/main.cpp
)

# add the executable
add_executable(rt.exe ${RT_SRC_FILES})