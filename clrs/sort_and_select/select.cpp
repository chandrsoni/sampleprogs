/**
* this code is only to understand the working of select process
* so it is only applicable for median of 5^x number of inputs
*/

#include <iostream>
#include <vector>
#include <algorithm> 
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void print_array(int* A,int i,int n){
	if(i>=n)return;
	printf("%d\n",A[i]);
	print_array(A,i+1,n);
}

void swap(vector<int>& A,int f_index,int s_index){
	int swap_int=A[f_index];
	A[f_index]=A[s_index];
	A[s_index]=swap_int;
	return;
}

int select(vector<int>& A,int j){
	if(A.size() == 1){
		return A[0];
	}
	std::vector<int> v;
	for (int i = 0; i < A.size()/5; ++i)
	{
		sort(A.begin()+5*i,A.begin()+5*(i+1));
		v.push_back(A[5*i+2]);
	}
	int remaining = A.size() % 5;
	if (remaining != 0)
	{
		v.push_back(A[5*(A.size()/5)+(remaining)/2-1]);
	}
	int part_by = select(v,((v.size()+1)/2)-1);
	int loc = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		if(A[i] == part_by){
			loc = i;
			break;
		}
	}
	swap(A,loc,A.size()-1);
	int small_pointer = 0;
	for(int i=0;i<A.size();i++){
		if(A[i]< part_by){
			swap(A,small_pointer,i);
			small_pointer++;
		}
	}
	swap(A,A.size()-1,small_pointer);
	if (small_pointer == j)
	{
		return A[small_pointer];
	}
	else {
		/*
		if (j > small_pointer)
		{
			return select(A+small_pointer+1,j-small_pointer-1);
		}
		else{
			return select(A,j);
		}
		*/
		printf("else part\n");
		return -1;
	}
}

int main(){
	printf("input as n and i follwed by the numbers\n");
	int n,i,input;
	scanf("%d",&n);
	scanf("%d",&i);
	vector<int> A;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		scanf("%d",&input);
		A.push_back(input);
	}
	printf("%d\n",select(A,i));
	return 0;
}
