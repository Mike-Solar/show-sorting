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
	std::unique_ptr<int[]> array() override {
		std::unique_ptr<int[]> ret(new int[length_]);
		int i=0;
		for (LinkedList<int> *cur=head.next;cur!=nullptr;cur=cur->next) {
			ret[i]=cur->data;
			i++;
		}
		return std::move(ret);
	}
private:
	LinkedList<int> head;
	LinkedList<int>* pivot;
};



#endif //INSERTSORT_H
