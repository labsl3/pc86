cmake_minimum_required(VERSION 2.8)
project(pc86 C)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)
