cmake_minimum_required(VERSION 3.10)

# set the project name
project(RayTracingOneWeek)




message(STATUS "current cmake src dir: ${CMAKE_CURRENT_SOURCE_DIR}")


set(RT_SRC_FILES
    "./src/ParameterHandler.cpp"
    "./src/main.cpp"
    "./src/Vec3.cpp"
    "./src/Color.cpp"
    "./src/Ray.cpp"
)

add_executable(rt ${RT_SRC_FILES})

target_include_directories( rt PUBLIC
    "./src/"
)


# Destination Path.
set(DESTINATION_PATH ".")

install(TARGETS rt
        DESTINATION DESTINATION_PATH
)