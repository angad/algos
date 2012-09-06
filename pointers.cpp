/*
 * pointers.cpp
 *
 *  Created on: Sep 6, 2012
 *      Author: angadsingh
 */

#include<iostream>

int main() {

	int i = 3;
	int *p = &i;
	//declares p as an object of type "pointer to int"
	//whose initial value is the address of the object i

	//prints the address of i, stored in p
	std::cout<<p<<std::endl;

	//prints the value pointed by the address stored in p
	std::cout<<*p<<std::endl;

	i=5;
	std::cout<<*p<<std::endl;

	*p=7;
	std::cout<<*p<<std::endl;

	int &r = i;
	//declares r as an object of type "reference to int"
	//referring to i

	//&r prints the address
	std::cout<<&r<<std::endl;

	std::cout<<r<<std::endl;

	r = 9;
	std::cout<<i<<std::endl;


	return 0;
}


