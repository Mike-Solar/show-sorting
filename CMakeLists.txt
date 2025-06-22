cmake_minimum_required(VERSION 3.10)

project(ShowSorting CXX)

set(CMAKE_CXX_STANDARD 14)
add_executable(show_sorting main.cpp
        SortBase.h
        QuickSort.cpp
        QuickSort.h
        InsertSort.cpp
        InsertSort.h
        LinkedList.h)