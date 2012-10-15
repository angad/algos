#include <iostream>
#include "bst.h"

using namespace std;



void Bst::insert(node* root, int n) {

	if(root == NULL) {
		cout<<"Root is NULL"<<endl;
		Bst(root, n);
		return;
	}

	if(root->n > n) {
		cout<<"testing "<<root->n<<endl;
		insert(root->left, n);
	} else {
		cout<<"testing "<<root->n<<endl;
		insert(root->right, n);
	}
}

void Bst::printTree(node* root) {
	if(root == NULL) {
		cout<<"Tree is empty"<<endl;
	} else {
		cout<<"node->n = "<<root->n<<endl;
		cout<<"Left Tree"<<endl;
		printTree(root->left);
		cout<<"Right Tree"<<endl;
		printTree(root->right);
	}
}


int main() {

	node root;
	Bst *t = new Bst(&root, 10);
	t->insert(&root, 5);
	t->printTree(&root);

	return 0;
}
