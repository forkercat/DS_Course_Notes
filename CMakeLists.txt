cmake_minimum_required(VERSION 2.8)
project(DS_Course_Notes)

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Wall")
else ()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -std=c11")
endif ()

file(GLOB SOURCES src/*.c)

add_executable(DS_Course_Notes ${SOURCES})