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
	
	// Bubble Sort
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(A[i]>A[j])swap(A,i,j);
		}
	}
	
	print_array(A,0,n);
	return 0;
}
