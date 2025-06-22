cmake_minimum_required(VERSION 3.10)

project(ShowSorting CXX)

set(CMAKE_CXX_STANDARD 14)
set(SRC_LIST include/SortBase.h
        src/sort/QuickSort.cpp
        include/QuickSort.h
        src/sort/InsertSort.cpp
        include/InsertSort.h
        include/LinkedList.h
        src/sort/BubbleSort.cpp
        include/BubbleSort.h)
add_executable(show_sorting src/main.cpp
    ${SRC_LIST}
)

add_executable(test src/test.cpp ${SRC_LIST})
target_include_directories(show_sorting PUBLIC include/)
target_include_directories(test PUBLIC include/)