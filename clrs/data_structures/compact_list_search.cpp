/**
* This is a list search algorithm 
* but for sequential access we're using arrays
* (also i don't see any possible implementation 
* for lists)
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;


void print_array(int* A,int i,int n){
	if(i>=n)return;
	printf("%d\n",A[i]);
	print_array(A,i+1,n);
}


int compact_list_search(int* A,int to_find,int n){
	int i = 0,j;
	while(i<n && A[i]<to_find){
		srand(time(NULL));
		j = rand()%n;
		if (i<j && A[j]<= to_find)
		{
			if (A[j] == to_find)
			{
				return j;
			}
			i = j;
		}
		i++;
	}
	if (i<n && A[i] == to_find)
	{
		return i;
	}
	return -1;
}

int main(){
	// input
	printf("input as n followed by numbers in sorted order followed by number to find\n");
	int n;
	scanf("%d",&n);
	int A[n],i=0;
	while(i<n){
		scanf("%d",&A[i]);
		if (i != 0)
		{
			if (A[i]<A[i-1])
			{
				printf("inputs are not sorted, please re-enter the last input\n");
				i--;
			}
		}
		i++;
	}
	scanf("%d",&i);
	// Quick Sort
	printf("%d\n",compact_list_search(A,i,n));
	
	//print_array(A,0,n);
	return 0;
}