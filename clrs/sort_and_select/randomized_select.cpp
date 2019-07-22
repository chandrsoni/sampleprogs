#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

int randomized_select(int* A,int begin,int end,int j){
	if(end-begin <= 0){
		return -1;
	}
	if(end-begin == 1){
		return A[begin];
	}
	int small_pointer = begin;
	srand(time(NULL));
	int loc = (rand()%(end-begin))+begin;
	swap(A,loc,end-1);
	int part_by = A[end - 1];
	for(int i=begin;i<end;i++){
		if(A[i]< part_by){
			swap(A,small_pointer,i);
			small_pointer++;
		}
	}
	swap(A,end-1,small_pointer);
	if (small_pointer == j)
	{
		return A[small_pointer];
	}
	else {
		if (j > small_pointer)
		{
			return randomized_select(A,small_pointer+1,end,j);
		}
		else{
			return randomized_select(A,begin,small_pointer,j);
		}
	}
}

int main(){
	printf("input as n and i follwed by the numbers\n");
	int n,i;
	scanf("%d",&n);
	scanf("%d",&i);
	int A[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		scanf("%d",&A[i]);
	}
	printf("%d\n",randomized_select(A,0,n,i));
	return 0;
}
