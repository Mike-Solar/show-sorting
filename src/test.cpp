//
// Created by Mike Solar on 2025-06-22.
//
#include <iostream>
#include <assert.h>
#include "BubbleSort.h"
#include "InsertSort.h"
#include "QuickSort.h"

void test_sort(SortBase &&base) {
	base.generate(10);
	base.sort();
	std::unique_ptr<int[]> ret = base.array();
	for(int i=0;i<9;i++) {
		assert(ret[i]<=ret[i+1]);
	}
}
int main() {
	std::cout << "Testing bubble sort..." << std::endl;
	test_sort(BubbleSort());
	std::cout << "Testing insert sort..." << std::endl;
	test_sort(InsertSort());
	std::cout << "Testing quick sort..." << std::endl;
	test_sort(QuickSort());
	return 0;
}