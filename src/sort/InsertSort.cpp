//
// Created by Mike Solar on 2025-06-22.
//

#include "InsertSort.h"
#include <ctime>
#include <cstdlib>
#include <random>

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
	std::default_random_engine generator;
	std::uniform_int_distribution<int> dist(10000, INT32_MAX);
	generator.seed(std::random_device{}());
	for (int i=0;i<length;i++) {
		cur->next = new LinkedList<int>();
		cur->next->data=dist(generator);
		cur->next->prev=cur;
		cur->next->next=nullptr;
		cur=cur->next;
	}
	pivot = head.next;

}
void InsertSort::sort() {
	// 处理空链表或单节点链表
	if (head.next == nullptr || head.next->next == nullptr) return;

	pivot = head.next;  // 初始化 pivot 为首节点
	LinkedList<int> *cur = pivot->next;  // 从第二个节点开始

	while (cur != nullptr) {
		LinkedList<int> *nextNode = cur->next;

		if (cur->data >= pivot->data) {
			compareTime_++;
			pivot = cur;
			cur = nextNode;
			continue;
		}

		LinkedList<int> *pos = pivot;
		while (pos != &head && pos->data > cur->data) {
			compareTime_++;
			pos = pos->prev;
		}

		cur->prev->next = cur->next;
		if (cur->next) cur->next->prev = cur->prev;
		swapTime_++;

		cur->prev = pos;
		cur->next = pos->next;
		if (pos->next) pos->next->prev = cur;
		pos->next = cur;

		cur = nextNode;
	}
}

