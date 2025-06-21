//
// Created by mikesolar on 25-6-21.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "SortBase.h"


class QuickSort : public SortBase{
public:
    explicit QuickSort(int length):SortBase(length){}
    ~QuickSort() override= default;
    void sort() override;
    void generate() override;
private:
    void quickSort(int *arr, int left, int right);
    int partition(int *arr, int left, int right);
    int compareTime=0;
    int swapTime=0;
};



#endif //QUICKSORT_H
