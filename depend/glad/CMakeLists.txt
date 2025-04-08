cmake_minimum_required(VERSION 4.0)

set(glad_src
    src/gl.c
)
include_directories(include)

add_library(glad ${glad_src})