/*
 * linkedList.h
 *
 *  Created on: Sep 6, 2012
 *      Author: angadsingh
 */

#ifndef BST_H_
#define BST_H_

struct node {
	int n;
	node *left;
	node *right;
};

class Bst {
	
	node* root;
public:
	Bst(node* root) {
		this.root = root;
	}

	Bst(node* root, int n) {
		root->n = n;
		root->left = NULL;
		root->right = NULL;
		this.root = root;
	}

	~Bst() {

	}

	node* findNode(node* root, int n);

	void insert(node* root, int n);

	node* remove(node* root, int n);

	void printTree(node* root);


};


#endif /* BST_H_ */
