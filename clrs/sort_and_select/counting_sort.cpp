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
	printf("input as n and k followed by numbers\n");
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	int A[n],C[k+1],i=0;
	// initialize the count array
	for (int i = 0; i <= k; ++i)
	{
		C[i]=0;
	}
	while(i<n){
		scanf("%d",&A[i]);
		if(A[i] > k)printf("input greater than the limit are discarded, please re-enter\n" );
		else {
			C[A[i]]++;	//counting sort
			i++;
		}
	}

	for (int i = 0; i <= k; ++i)
	{
		while(C[i]!=0){
			printf("%d\n",i);
			C[i]--;
		}
	}
	
	//print_array(A,0,n);
	return 0;
}
