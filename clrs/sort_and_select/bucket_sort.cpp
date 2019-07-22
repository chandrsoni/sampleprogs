#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void insert_into_vector(vector<int>& A,int value){
	bool insert = false;
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] > value)
		{
			/* code */
			A.insert(A.begin()+i,value);
			insert = true;
			break;
		}
	}
	if(!insert){
		A.push_back(value);
	}
}

void print_array(int* A,int i,int n){
	if(i>=n)return;
	printf("%d\n",A[i]);
	print_array(A,i+1,n);
}

void print_vector(vector<int>& A){
	for (int i = 0; i < A.size(); ++i)
	{
		printf("%d\n",A[i]);
	}
	return;
}

int main(){
	// input
	printf("input as n followed by limit and number of buckets followed by the numbers\n");
	int n,lim,bucket,input;
	scanf("%d",&n);
	scanf("%d",&lim);
	scanf("%d",&bucket);
	vector<int> buc_list[bucket];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		scanf("%d",&input);
		if(input>=lim){printf("limit reached last input discarded, input again!\n");i--;continue;}
		int j = (input*bucket)/lim;
		//insert into bucket buc_list[i]
		insert_into_vector(buc_list[j],input);
	}
	for (int i = 0; i < bucket; ++i)
	{
		/* code */
		print_vector(buc_list[i]);
	}
	//print_array(A,0,n);
	return 0;
}
