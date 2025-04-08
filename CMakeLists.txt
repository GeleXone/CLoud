project(CLoud)

include_directories(CLoud/depend/glfw)
include_directories(CLoud/depend/glad)
include_directories(CLoud/depend/cglm)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_subdirectory(CLoud)