//
// Created by Mike Solar on 2025-06-21.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "SortBase.h"
#include <memory>


class QuickSort : public SortBase{
public:
    explicit QuickSort();
    ~QuickSort() override = default;
    void sort() override;
    void generate(int length) override;
private:
    void quickSort(int left, int right);
    int partition(int left, int right);
    std::unique_ptr<int[]> data; // 使用智能指针确保正确释放
};



#endif //QUICKSORT_H
