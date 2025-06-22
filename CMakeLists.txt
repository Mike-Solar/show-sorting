cmake_minimum_required(VERSION 3.10)

project(ShowSorting CXX)

set(CMAKE_CXX_STANDARD 14)
add_executable(show_sorting src/main.cpp
        include/SortBase.h
        src/sort/QuickSort.cpp
        include/QuickSort.h
        src/sort/InsertSort.cpp
        include/InsertSort.h
        include/LinkedList.h
        src/sort/BubbleSort.cpp
        include/BubbleSort.h)
target_include_directories(show_sorting PUBLIC include/)