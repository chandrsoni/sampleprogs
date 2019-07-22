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

void max_heapify(int* A,int i,int n){
	if(2*i+1>=n)return;
	int largest_index = i;
	if(A[2*i+1] > A[largest_index])largest_index = 2*i+1;
	if(2*i+2 < n){if( A[2*i+2] > A[largest_index])largest_index = 2*i+2;}

	if (largest_index == i)
	{
		return;
	}
	swap(A,i,largest_index);
	max_heapify(A,largest_index,n);
	return;
}

void build_max_heap(int* A,int n){
	for (int i = n/2; i>=0; i--)
	{
		max_heapify(A,i,n);
	}
	return;
}

void heap_sort(int* A,int n){
	build_max_heap(A,n);
	for (int i = n-1; i >= 1 ; i--)
	{
		swap(A,0,i);
		max_heapify(A,0,i);
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
	// Heap Sort
	heap_sort(A,n);
	
	print_array(A,0,n);
	return 0;
}
