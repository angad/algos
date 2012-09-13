/*
 * linkedList.cpp
 *
 *  Created on: Sep 6, 2012
 *      Author: angadsingh
 */

#include<iostream>
#include "linkedList.h"

using namespace std;

void LinkedList::print() {
	if(head == NULL) {
		cout<<"No elements in the list to print!"<<endl;
		return;
	}

	node *ptr = head;
	for(; ptr->next!=NULL; ptr=ptr->next) {
		cout<<ptr->n<<endl;
	}
	//print the last element
	cout<<ptr->n<<endl;
}


node* LinkedList::add(int n) {

	if(head == NULL) {
		head = new node();
		head->n = n;
		head->next = NULL;
	}

	//First element in the list
	if(head->n == 0) {
		head->n = n;
	} else {
		node* next = new node();
		next->n = n;
		node* ptr;

		//traverse to the end of the list
		for(ptr=head; ptr->next!=NULL; ptr=ptr->next);

		ptr->next = next;
		next->next = NULL;
	}
	return head;
}

node* LinkedList::insert(int n, int p) {
	if(head == NULL) return NULL;

	int c = count();
	if(p >= c) {
		//if inserting at a position greater than length
		//then append
		return add(n);
	}

	node *ptr = head;
	node *next = new node();
	next->n = n;
	if(p==0) {
		//inserting at head
		next->next = head;
		head = next;
		return head;
	}

	int i = 1;
	for(; ptr->next!=NULL; ptr=ptr->next) {
		if(i==p) {
			next->next = ptr->next;
			ptr->next = next;
			return head;
		} i++;
	}
	return head;
}

node* LinkedList::remove(int n) {
	if(head == NULL) return NULL;

	if(head->n == n) {
		head = head->next;
		return head;
	}
	node *ptr = head;
	for(; ptr->next != NULL; ptr=ptr->next) {
		if(ptr->next->n == n) {
			ptr->next = ptr->next->next;
		}
	}
	return head;
}

node* LinkedList::remove(node *n) {
	if(head == NULL) return NULL;

	node* ptr = head;
	for(; ptr->next != NULL; ptr=ptr->next) {
		if(ptr->next == n->next) {
			ptr->next =ptr->next->next;
		}
	}
	return head;
}

node* LinkedList::reverse() {
	if(head == NULL) return NULL;

	node *new_head = NULL;
	while(head) {
		node *next = head->next;
		head->next = new_head;
		new_head = head;
		head = next;
	}
	head = new_head;
	return head;
}

//Using the Tortoise and Hare algorithm
//http://en.wikipedia.org/wiki/Cycle_detection
//also called Floyd's cycle-finding algorithm
bool LinkedList::detectLoop() {
	node *slownode = head;
	node *fastnode = head;

	while(fastnode && fastnode->next) {
		if(fastnode->next == slownode) {
			return true;
		}
		if(fastnode->next->next == slownode) {
			return true;
		}
		fastnode = fastnode->next->next;
		slownode = slownode->next;
	}
	return false;
}

//creates a loop in the current linked list by
//attaching the next of the last to the head
node* LinkedList::createLoop() {
	if(head->next == NULL) return head;
	node* ptr = head;
	for(; ptr->next != NULL; ptr=ptr->next);
	ptr->next = head;
	return head;
}

int LinkedList::count() {
	if(head->next == NULL) return 0;

	if(detectLoop()) {
		return -1;
		//to be implemented
	}

	node* ptr = head;
	int c = 1;
	for(; ptr->next != NULL; ptr=ptr->next) {
		c++;
	}
	return c;
}


int LinkedList::getNth(int n) {
	if(head->next == NULL) return 0;

	if(n > count()) return -1;

	node* ptr = head;
	int i = 0;
	for(; ptr->next != NULL; ptr=ptr->next) {
		if(n==i) {
			return ptr->n;
		}
	}
	return -1;
}

node* LinkedList::split() {
	int n = count();
	if(n == 1) return NULL;
	int iter = (n / 2) + (n % 2);

	node* ptr = head;
	for(int i = 1; i < iter; i++) {
		ptr = ptr->next;
	}

	cout<<"splitting at "<<ptr->n<<endl;
	node* half = ptr->next;
	ptr->next = NULL;
	return half;
}

node* LinkedList::sortedInsert(int n) {
	node *next = new node();
	next->n = n;

	node *ptr = head;
	if(n <= ptr->n) {
		//if smaller than the first element
		next->next = head;
		head = next;
		return head;
	}

	for(; ptr->next!=NULL; ptr=ptr->next) {
		//if in-between two elements
		if(n >= ptr->n && n <= ptr->next->n) {
			next->next = ptr->next;
			ptr->next = next;
			return head;
		}
	}
	//if larger than the last element
	if(n >= ptr->n) {
		next->next = NULL;
		ptr->next = next;
		return head;
	}

	return head;
}

//adapted from Programming Interviews Exposed
//pg. 43-44
node* LinkedList::mthToLast(int m) {
	node *current, *mBehind;
	int i;

	current = head;

	for(i = 0; i < m; i++) {
		if(current->next) {
			current = current->next;
		} else {
			return NULL;
		}
	}

	mBehind = head;
	while(current->next) {
		current = current->next;
		mBehind = mBehind->next;
	}

	return mBehind;
}

int main() {
	LinkedList *l = new LinkedList();

	l->add(10);
//	l->add(20);
//	l->add(30);
//	l->add(40);
	l->print();
//	cout<<"...."<<endl;
//	l->insert(5, 0);
//	l->print();
//	cout<<"...."<<endl;
//	l->insert(15, 1);
//	l->print();
	cout<<"...."<<endl;
//	l->insert(25, 10);
	l->print();
	cout<<"...."<<endl;
//	l->remove(25);
//	l->print();
//	l->reverse();
	cout<<"...."<<endl;
	l->print();
	cout<<"...."<<endl;

	l->sortedInsert(40);
	l->sortedInsert(20);
	l->sortedInsert(5);
	l->sortedInsert(60);
	l->sortedInsert(55);
	l->print();
//	l->createLoop();

	if(l->detectLoop()) cout<<"LOOP detected!"<<endl;
	else cout <<"No LOOP detected"<<endl;

	cout<<"...."<<endl;
	cout<<"length: "<<l->count()<<endl;
	l->print();

	LinkedList *half = new LinkedList(l->split());

	l->print();
	cout<<"...."<<endl;
	half->print();
	return 0;

}
