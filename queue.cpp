/*
 * queue.cpp
 *
 *  Created on: Oct 16, 2012
 *      Author: angadsingh
 */

#include "queue.h"
#include <iostream>
using namespace std;

template<class T>
Queue<T>::Queue() {
	front = NULL;
	back = NULL;
}

template<class T>
T Queue<T>::dequeue() {
	int ret = -1;
	if(front != NULL) {
		ret = front->n;
		front = front->next;
	}
	return ret;
}

template<class T>
void Queue<T>::enqueue(T n) {
	if(front == NULL) {
		front = new node();
		front->next = NULL;
		front->n = n;
		back = front;
	} else {
		back->next = new node();
		back = back->next;
		back->n = n;
	}
}

int main() {

	Queue<int> *q;
	q->enqueue(10);
	q->enqueue(20);
	q->enqueue(30);
	q->enqueue(40);
	q->enqueue(50);
	q->enqueue(60);
	q->enqueue(70);

	cout<<q->dequeue()<<endl;
	cout<<q->dequeue()<<endl;
	cout<<q->dequeue()<<endl;
	cout<<q->dequeue()<<endl;
	cout<<q->dequeue()<<endl;
	cout<<q->dequeue()<<endl;
	cout<<q->dequeue()<<endl;
	cout<<q->dequeue()<<endl;

	return 0;
}


