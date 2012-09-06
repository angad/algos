/*
 * linkedList.cpp
 *
 *  Created on: Sep 6, 2012
 *      Author: angadsingh
 */

#include<iostream.h>
#include "linkedList.h"

void LinkedList::print() {
	node *ptr = head;
	for(; ptr->next!=NULL; ptr=ptr->next) {
		cout<<ptr->n<<endl;
	}
	//print the last element
	cout<<ptr->n<<endl;
}


node* LinkedList::add(int n) {

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


	node *ptr = head;
	node *next = new node();
	next->n = n;

	if(p==0) {
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
		}
		i++;
	}

	return head;
}

node* LinkedList::remove(int n) {

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

	node* ptr = head;
	for(; ptr->next != NULL; ptr=ptr->next) {
		if(ptr->next == n->next) {
			ptr->next =ptr->next->next;
		}
	}
	return head;
}

node* LinkedList::reverse() {

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

int main() {
	LinkedList *l = new LinkedList();

	l->add(10);
	l->add(20);
	l->add(30);
	l->print();
//	cout<<"...."<<endl;
//	l->insert(5, 0);
//	l->print();
//	cout<<"...."<<endl;
//	l->insert(15, 1);
//	l->print();
	cout<<"...."<<endl;
	l->insert(25, 2);
	l->print();
	cout<<"...."<<endl;
	l->remove(25);
	l->print();
	l->reverse();
	cout<<"...."<<endl;
	l->print();
	return 0;
}
