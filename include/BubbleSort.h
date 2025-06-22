//
// Created by katherinesolar on 25-6-22.
//

#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <memory>

#include "SortBase.h"


class BubbleSort : public SortBase{
public:
	explicit BubbleSort():SortBase(){}
	~BubbleSort() override = default;
	void sort() override;
	void generate(int length) override;
	std::unique_ptr<int[]> array() override {
		std::unique_ptr<int[]> ret(new int[length_]);
		for (int i=0;i<length_;i++) {
			ret[i] = data[i];
		}
		return std::move(ret);
	}
private:
	std::unique_ptr<int[]> data;
};



#endif //BUBBLESORT_H
