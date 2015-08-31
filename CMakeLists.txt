cmake_minimum_required(VERSION 2.8)
project(libflow)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(TrapniCommon)

add_subdirectory(src)
add_subdirectory(examples)
