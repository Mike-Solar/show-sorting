//
// Created by katherinesolar on 25-6-22.
//

#include "BubbleSort.h"

#include <cstdlib>

void BubbleSort::sort() {
	for (int i=0;i<length_-1;i--) {
		for (int j=0;j<length_-1-i;j++) {
			if (data[j] > data[j+1]) {
				std::swap(data[j], data[j+1]);
				swapTime_++;
			}
			compareTime_++;
		}
	}
}

void BubbleSort::generate(int length) {
	data = std::make_unique<int[]>(length);
	length_ = length;
	for (int i = 0; i < length; i++) {
		srand(time(nullptr));
		data[i] = rand() % 10000+10000;
	}
}
