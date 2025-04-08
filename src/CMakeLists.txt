cmake_minimum_required(VERSION 4.0)

set ( cloud_src
        main.c
)

add_executable(CLoud ${cloud_src})
target_link_libraries(CLoud glad)
target_link_libraries(CLoud glfw)
target_link_libraries(CLoud cglm)