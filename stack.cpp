/*
 * stack.cpp
 *
 *  Created on: Sep 9, 2012
 *      Author: angadsingh
 */


#include <iostream>
#include "stack.h"
using namespace std;

node* Stack::push(int n) {
	node* newTop = new node();
	newTop->next = top;
	newTop->n = n;

	top = newTop;
	return top;
}

int Stack::pop() {
	int n;
	if(top == NULL) {
		return -1;
		//throw error
	} else {
		n = top->n;
		if(top->next !=NULL) {
			top = top->next;
		}
		else top = NULL;
		return n;
	}
}

int Stack::peek() {
	int n;
	if(top == NULL) {
		return -1;
	} else {
		return top->n;
	}
}

bool Stack::isEmpty() {
	if(top == NULL) return true;
	else return false;
}

Stack* Stack::sort() {

	Stack *t = new Stack();
	while(!isEmpty()) {
		int tmp = pop();
		while(!t->isEmpty() && t->peek > tmp) {
			push(t->pop());
		}
		t->push(tmp);
	}
	return t;
}

int main() {

	Stack *s = new Stack();
	s->push(10);
	s->push(20);

	cout<<s->pop()<<endl;
	cout<<s->pop()<<endl;

	Stack *t = s->sort();
	cout<<t->pop()<<endl;
	cout<<t->pop()<<endl;


	return 0;
}
