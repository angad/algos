/*
 * sorting.cpp
 *
 *  Created on: Oct 21, 2012
 *      Author: angadsingh
 */

#include <iostream>

using namespace std;



void merge(int *a,int low,int pivot,int high)
{
    int h,i,j,b[50],k;
    h=low;
    i=low;
    j=pivot+1;

    while((h<=pivot)&&(j<=high)) {
        if(a[h]<=a[j]) b[i]=a[h++];
        else b[i]=a[j++];
        i++;
    }

    if(h>pivot)
    	for(k=j; k<=high; k++) b[i++]=a[k];
    else
        for(k=h; k<=pivot; k++) b[i++]=a[k];

    //copy b to a
    for(k=low; k<=high; k++) a[k]=b[k];
}

void mergesort(int *a, int low,int high) {
    int pivot;
    if(low<high) {
        pivot = (low + high) / 2;
        mergesort(a, low, pivot);
        mergesort(a, pivot+1, high);
        merge(a, low, pivot, high);
    }
}

int partition(int *a, int start, int end) {
	//get the position of the pivot
	//elements on the left should be less than the pivot
	//elements on the right should be more than the pivot

	int m = (start + end) / 2;
	int pivot = a[m];
	int temp;
	int i = start; int j = end;
	while(i < j) {
		while(a[i] <= pivot && i<=end) i++;
		while(a[j] >= pivot && j>=start) j--;
		if(i < j) {
			//swap
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	a[start] = a[j];
	a[j] = pivot;
	return j;
}

void quicksort(int *a, int start, int end) {
	int m;
	if(start < end) {
		m = partition(a, start, end);
		quicksort(a, start, m-1);
		quicksort(a, m, end);
	}
}



int main() {

	int a[] = {12,10,43,23,-78,45,123,56,98,41,90,24,9,8,7,6,5,4,3,2,1};
    int num = sizeof(a)/sizeof(int);
    int t = clock();
    mergesort(a, 0, num-1);
    cout<<"Time taken = "<<(clock()-t)<<endl;
    for(int i=0; i<num; i++)
        cout<<a[i]<<" ";
    cout<<endl;


    int b[] = {12,10,43,23,-78,45,123,56,98,41,90,24,9,8,7,6,5,4,3,2,1};
    num = sizeof(b)/sizeof(int);
    cout<<endl<<num<<" ";
    t = clock();
    quicksort(b, 0, num-1);
    cout<<"Time taken = "<<(clock()-t)<<endl;
    for(int i=0; i<num; i++)
        cout<<b[i]<<" ";
    cout<<endl;


    return 0;
}
