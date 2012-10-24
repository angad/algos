/*
 * stack.h
 *
 *  Created on: Sep 9, 2012
 *      Author: angadsingh
 */

#ifndef STACK_H_
#define STACK_H_

struct node {
	node *next;
	int n;
};


class Stack {

	node *top;

public:
	Stack() {
		top = NULL;
	}

	Stack(node* top) {
		this->top = top;
	}

	~Stack() {
		while(top) {
			node* next = top->next;
			delete top;
			top = next;
		}
	}

	node* push(int n);
	int pop();
	int peek();
	Stack* sort();
	bool isEmpty();
};

#endif /* STACK_H_ */
