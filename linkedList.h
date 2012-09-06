/*
 * linkedList.h
 *
 *  Created on: Sep 6, 2012
 *      Author: angadsingh
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


struct node{
	int n;
	node* next;
};


class LinkedList {

	node *head;

public:
	LinkedList() {
		head = new node();
		head->n = 0;
		head->next = NULL;
	}

	~LinkedList() {
		delete(head);
	}

	void print();

	//all functions below return the current head of the linked list

	//adds a new node with value n
	node* add(int n);

	//inserts a new node with value n at position p
	node* insert(int n, int p);

	//removes node
	node* remove(node*);

	//removes all nodes with value n
	node* remove(int n);

	//reverses the linked list
	node* reverse();
};


#endif /* LINKEDLIST_H_ */
