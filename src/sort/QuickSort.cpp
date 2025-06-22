//
// Created by Mike Solar on 2025-06-21.
//

#include "QuickSort.h"
#include <cstdlib>
#include <ctime>
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
    for (int i = 0; i < length; i++) {
        srand(time(NULL));
        data[i] = rand()%10000 + 10000;
    }
}

void QuickSort::quickSort(int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot=partition(left, right);
    quickSort(left, pivot);
    quickSort(pivot+1, right);
}

int QuickSort::partition(int left, int right) {

    int pivot = left;
    int index=left+1;
    for (int i=index+1; i<=right; i++) {
        if (data[i] < data[pivot]) {
            std::swap(data[i], data[index]);
            swapTime_++;
            index++;
        }
        compareTime_++;
    }
    std::swap(data[pivot], data[index]);
    swapTime_++;
    return pivot;
}


