#include <iostream>
#include <stdio.h>
using namespace std;

void print_array(int* A,int i,int n){
	if(i>=n)return;
	printf("%d\n",A[i]);
	print_array(A,i+1,n);
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
	
	print_array(A,0,n);
	return 0;
}
