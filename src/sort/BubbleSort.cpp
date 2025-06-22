//
// Created by katherinesolar on 25-6-22.
//

#include "BubbleSort.h"

#include <random>

void BubbleSort::sort() {
	for (int i=0;i<length_-1;i++) {
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
	std::default_random_engine generator;
	std::uniform_int_distribution<int> dist(10000, INT32_MAX);
	generator.seed(std::random_device{}());
	for (int i = 0; i < length; i++) {
		data[i] = dist(generator);
	}
}
