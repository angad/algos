/*
 * tree.h
 *
 *  Created on: Oct 21, 2012
 *      Author: angadsingh
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>


class Tree {

public:
	struct node {
		int n;
		node* left;
		node* right;
	};
	node* root;

	Tree() {
		root = NULL;
	}

	~Tree() {
		delete root;
	}

	node* getRoot();
	void setRoot(node* root);
	node* add(node* root, int n);
	node* remove(node* root, int n);
//	LinkedList* inOrder();
//	LinkedList* preOrder();
//	LinkedList* postOrder();
	bool dfs(int n);
	bool bfs(int n);
	void print(node n[]);
	void printInLine(node *root);

};

#endif /* TREE_H_ */
