cmake_minimum_required(VERSION 4.0)

project(CLoud)

include_directories(depend/glfw/include)
include_directories(depend/glad/include)
include_directories(depend/cglm/include)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR/runtime_build})

add_subdirectory(src)
add_subdirectory(depend/GLFW)
add_subdirectory(depend/glad)
add_subdirectory(depend/cglm)