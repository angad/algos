/*
 * problems.cpp
 *
 *  Created on: Oct 16, 2012
 *      Author: angadsingh
 */



#include<iostream>

using namespace std;

int hasDuplicate(char* str) {

//O(n^2)
//	int i;
//	int j;
//	for(i = 0; str[i+1]!=NULL; i++) {
//		for(j=i+1; str[j]!=NULL; j++) {
//			if(str[i] == str[j]) {
//				return 1;
//			}
//		}
//	}

//O(n)
	int set[256] = {0};
	int i;
	for(i = 0; str[i]!=NULL; i++) {
		if(set[str[i]] == 1) return 1;
		else set[str[i]] = 1;
	}
	return 0;
}

char* reverse(char* str) {
	char *end = str;
	char tmp;
	while(*end) {
		++end;
	}
	--end;
	while(str<end) {
		tmp = *str;
		*str++ = *end;
		*end-- = tmp;
	}
	return str;
}

char* removeDuplicates(char *str) {
	int set[256] = {0};
	int i; int j = 1;
	for(i = 1; str[i]!=NULL; i++) {
		if(set[str[i]] != 1) {
			str[j] = str[i];
			j++;
			set[str[i]] = 1;
		}
	}
	str[j] = NULL;
	return str;
}

int isAnagram(char* str1, char* str2) {

	bubblesort(str1);
	bubblesort(str2);

//	int set[256][2] = {0};
//	int i; int j = 1;
//	for(i=0, j=0; (str1[i]!=NULL && str2[j]!=NULL); i++, j++) {
//		if(set[str1[i]][0] != 1) {
//			set[str1[i]][0] = 1;
//		}
//	}
}

char* bubblesort(char* str) {
	int i; int j; char tmp;
	for(i=0; str[i]!=NULL; i++) {
		for(j=i; str[j]!=NULL; j++) {
			if(str[i] > str[j]) {
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
	return str;
}

int main() {

	char *str;
	gets(str);
	cout<<"hasDuplicate = "<<hasDuplicate(str)<<endl;
	reverse(str);
	cout<<"Reverse = "<<str<<endl;
	removeDuplicates(str);
	cout<<"Removed Duplicates = "<<str<<endl;
	bubblesort(str);
	cout<<"Sorted = "<<str<<endl;
	return 0;
}


