//
// Created by Mike Solar on 2025-06-22.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template<typename T>
struct LinkedList {
	struct LinkedList* next;
	struct LinkedList* prev;
	T data;
	LinkedList() {
		next=nullptr;
		prev=nullptr;
	}
};



#endif //LINKEDLIST_H
