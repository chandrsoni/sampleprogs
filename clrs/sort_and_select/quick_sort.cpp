#include <iostream>
#include <stdio.h>
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

void quick_sort(int* A,int begin,int end){
	/**
	* end exclusive begin inclusive
	*/
	if(end-begin<=1){
		return;
	}
	int small_pointer = begin;
	int part_by = A[end-1];
	for(int i=begin;i<end;i++){
		if(A[i]< part_by){
			swap(A,small_pointer,i);
			small_pointer++;
		}
	}
	swap(A,end-1,small_pointer);
	quick_sort(A,begin,small_pointer);
	quick_sort(A,small_pointer+1,end);
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
	// Quick Sort
	quick_sort(A,0,n);
	
	print_array(A,0,n);
	return 0;
}
