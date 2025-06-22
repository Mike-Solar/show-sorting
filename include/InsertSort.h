//
// Created by Mike Solar on 2025-06-22.
//

#ifndef INSERTSORT_H
#define INSERTSORT_H
#include "LinkedList.h"
#include "SortBase.h"

class InsertSort :public SortBase{
public:
	InsertSort();
	~InsertSort() override;
	void sort() override;
	void generate(int length) override;
private:
	LinkedList<int> head;
	LinkedList<int>* pivot;
};



#endif //INSERTSORT_H
