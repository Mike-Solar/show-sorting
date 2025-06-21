//
// Created by mikesolar on 25-6-21.
//

#include "QuickSort.h"
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <utility>


void QuickSort::sort() {
    int left=0;
    int right=length-1;
    quickSort(data, left, right);
}

void QuickSort::generate() {
    srand(time(0));
    for (int i = 0; i < length; i++) {
        data[i] = rand()%10000 + 10000;
    }
}

void QuickSort::quickSort(int *data, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot=partition(data, left, right);
    quickSort(data, left, pivot);
    quickSort(data, pivot+1, right);
}

int QuickSort::partition(int *arr, int left, int right) {

    int pivot = left;
    int index=left+1;
    for (int i=index+1; i<=right; i++) {
        if (arr[i] < arr[pivot]) {
            std::swap(arr[i], arr[index]);
            index++;
        }
    }
    std::swap(arr[pivot], arr[index]);
    return pivot;
}


