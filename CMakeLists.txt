cmake_minimum_required(VERSION 3.16)
project(vasyaCourseWork)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" CONFIG)
set(BUILD_SHARED_LIBS OFF)

add_executable(vasyaCourseWork main.cpp lineSegment.h lineSegment.cpp Point.h polygon.cpp polygon.h)