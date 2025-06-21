cmake_minimum_required(VERSION 3.10)

project(ShowSorting CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-stdlib=libc++")
add_executable(show_sorting main.cpp
        SortBase.h
        QuickSort.cpp
        QuickSort.h)