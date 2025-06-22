//
// Created by Mike Solar on 2025-06-22.
//

#include "InsertSort.h"
#include <ctime>
#include <cstdlib>
InsertSort::InsertSort() : SortBase(){
	length_ = 0;
	pivot = nullptr;
}
InsertSort::~InsertSort() {
	for (LinkedList<int> *cur=head.next; cur!=nullptr;) {
		LinkedList<int> *tmp = cur->next;
		delete cur;
		cur = tmp;
	}
}

void InsertSort::generate(int length) {
	this->length_ = length;
	LinkedList<int> *cur=&head;
	for (int i=0;i<length;i++) {
		cur->next = new LinkedList<int>();
		srand(time(NULL));
		cur->next->data=rand()%10000+10000;
		cur->next->prev=cur;
		cur=cur->next;
	}
	pivot = head.next;

}
void InsertSort::sort() {
	LinkedList<int> *cur=head.next->next;
	while (cur!=nullptr) {
		if (cur->data >= pivot->data) {
			compareTime_++;
			pivot = cur;
			continue;
		}
		LinkedList<int> *tmp = cur->next;
		LinkedList<int> *tmpPrev = cur->prev;
		for (LinkedList<int> *tmp2=pivot; tmp2!=nullptr; tmp2=tmp2->prev) {
			if (tmp2->data < cur->data) {
				LinkedList<int> *tmp3=tmp2->next;
				tmp2->next=cur;
				cur->prev=tmp2;
				cur->next=tmp3;
				tmp3->prev=cur;
				swapTime_++;
			}
			compareTime_++;
		}
		tmp->prev=tmpPrev;
		tmpPrev->next=tmp;
	}
}
