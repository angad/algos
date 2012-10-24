/*
 * queue.h
 *
 *  Created on: Oct 16, 2012
 *      Author: angadsingh
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>

using namespace std;

template <class T>

class Queue {
private:
	struct node {
		node *next;
		T n;
	};
	node *front;
	node* back;

public:
	Queue();
	Queue(node* item) {
		this->front = item;
		this->back = NULL;
		this->front->next = back;
	}

	~Queue() {
		while(front) {
			node* next = front->next;
			delete front;
			front = next;
		}
	}

	void enqueue(T n);
	T dequeue();
};


#endif /* QUEUE_H_ */
