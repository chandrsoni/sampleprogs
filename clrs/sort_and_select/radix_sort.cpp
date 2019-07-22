#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

void print_array(int* A,int i,int n){
	if(i>=n)return;
	printf("%d\n",A[i]);
	print_array(A,i+1,n);
}

void swap(int* A,int f_index,int s_index){
	int swap_int=A[f_index];
	A[f_index]=A[s_index];
	A[s_index]=swap_int;
	return;
}

int get_digit(int num,int digit){
	return abs(((num>>digit)<<31)>>31);
}

void radix_insertion_sort(int* A,int n,int degree){
	// insertion sort
	if(n<2) {return;}
	int j,swap,key;
	for(int i=0;i<n;i++){
		j=i-1;
		key=A[i];
		while(j>=0 && get_digit(A[j],degree)>get_digit(key,degree)){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
	}
	return;
}

int main(){

	// input
	printf("input as n followed by numbers\n");
	int n;
	scanf("%d",&n);
	int A[n],i=0;
	while(i<n){
		scanf("%d",&A[i]);
		i++;
	}
	/**
	* radix sort:
	* We will use insertion sort but with the radix sort modification
	* also we will use binary representation for comparision as 
	* obtaining the digits is easy
	*/

	// insertion sort
	if(n<2) {print_array(A,0,n);return 0;}
	int j,swap,key;
	for(i=0;i<n;i++){
		j=i-1;
		key=A[i];
		while(j>=0 && A[j]>key){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
	}

	for (int i = 0; i < 32	; ++i)
	{
		/* code */
		radix_insertion_sort(A,n,i);
	}
	print_array(A,0,n);
	return 0;
}
