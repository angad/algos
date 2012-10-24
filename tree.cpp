/*
 * tree.cpp
 *
 *  Created on: Oct 21, 2012
 *      Author: angadsingh
 */

#include <iostream>
#include "tree.h"
#include "queue.h"

using namespace std;

//bst
Tree::node* Tree::add(Tree::node* root, int n) {
	if(root == NULL) {
		root = new node();
		root->n = n;
	} else if(root-> n > n) {
		if(root->left == NULL){
			root->left = new node();
			root->left->n = n;
		} else add(root->left, n);
	} else {
		if(root->right == NULL ) {
			root->right = new node();
			root->right->n = n;
		} else add(root->right, n);
	}
	return root;
}

void Tree::printInLine(Tree::node* root) {
	Queue<Tree::node> *q;
	q->enqueue(*root);



}


Tree::node* Tree::remove(Tree::node* root, int n) {
	if(root == NULL)
		return NULL;

	if(root->n == n) {
		root = root->left;


	}

	return root;
}

bool Tree::dfs(int n) {

	if(root == NULL) return false;
	node* visited[] = {};
	node* path[] = {};
	int v = 0;
	int p = 0;

	bool found = false;
	path[p++] = root;

	//...
	//....
	//....

	return false;
}


//in-order printing
void Tree::print(node *root) {
	if(root == NULL) return;
	else {
		print(root->left);
		cout<<root->n<<" ";
		print(root->right);
	}
}

Tree::node* Tree::getRoot() {
	return root;
}

void Tree::setRoot(node* r) {
	root = r;
}

int main() {
	Tree *bst = new Tree();
	Tree::node* rt = bst->getRoot();
	rt = bst->add(rt, 2);
	rt = bst->add(rt, 4);
	rt = bst->add(rt, 6);
	rt = bst->add(rt, 8);
	rt = bst->add(rt, 1);
	rt = bst->add(rt, 3);
	rt = bst->add(rt, 5);
	rt = bst->add(rt, 11);
	rt = bst->add(rt, 9);
	rt = bst->add(rt, 10);
	rt = bst->add(rt, 12);
	rt = bst->add(rt, 7);

//	int n=0;
//	while(n!=20) {
//		n++;
//		cin>>n;
//		bst->add(rt, n);
//		rt = bst->getRoot();
//		bst->print(rt);
//	}

	bst->print(rt);
	cout<<endl;

	return 0;
}
