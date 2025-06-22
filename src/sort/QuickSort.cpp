//
// Created by Mike Solar on 2025-06-21.
//

#include "QuickSort.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <utility>


QuickSort::QuickSort():SortBase() {
    length_ = 0;
}

void QuickSort::sort() {
    int left=0;
    int right=length_-1;
    quickSort(left, right);
}

void QuickSort::generate(int length) {
    this->length_=length;
    this->data=std::make_unique<int[]>(length);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> dist(10000, INT32_MAX);
    generator.seed(std::random_device{}());
    for (int i = 0; i < length; i++) {
        srand(time(NULL));
        data[i] = dist(generator);
    }
}

void QuickSort::quickSort(int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot=partition(left, right);
    quickSort(left, pivot-1);
    quickSort(pivot+1, right);
}

int QuickSort::partition(int left, int right) {

    int pivot = left;
    int index=left+1;
    int i;
    for (i=index; i<=right; i++) {
        if (data[i] < data[pivot]) {
            std::swap(data[i], data[index]);
            swapTime_++;
            index++;
        }
        compareTime_++;
    }
    std::swap(data[pivot], data[index-1]);
    swapTime_++;
    return index-1;
}


