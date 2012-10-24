/*
 * recursion.c
 *
 *  Created on: Oct 21, 2012
 *      Author: angadsingh
 */

#include <iostream>

using namespace std;

int generateNthFibonacci(int n, int a, int b) {
	if(n == 0) return b;

	return generateNthFibonacci(--n, b, a+b);
}

void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void print(char *s) {
	for(int i = 0; s[i]!=NULL; i++) {
		cout<<s[i];
	}
	cout<<endl;
}


int main() {
//	permutate("abcd", 0, 3);
	return 0;
}


