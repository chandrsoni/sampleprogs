#include <iostream>
#include <stdio.h>
using namespace std;

void print_array(int* A,int i,int n){
	if(i>=n)return;
	printf("%d\n",A[i]);
	print_array(A,i+1,n);
}

void merge(int* A, int p,int q,int r){
	int L[q-p],N[r-q];
	for(int i=0;i<q-p;i++){
		L[i]=A[i+p];
	}
	for(int i=0;i<r-q;i++){
		N[i]=A[i+q];
	}
	int i=p,j=0,k=0;
	while(i<r){
		if(j>=q-p){
			// Effecient
			while(i<r){
				A[i]=N[k];
				k++;
				i++;
			}
			break;
		}
		if(k>=r-q){
			while(i<r){
				A[i]=L[j];
				i++;
				j++;
			}
			break;
		}
		if(L[j]<N[k]){
			A[i]=L[j];
			j++;
		}else{
			A[i]=N[k];
			k++;
		}
		i++;
	}
	return;
}

void merge_sort(int* A,int begin,int end){
	if(end-begin<=1){
		return;
	}
	int mid=(end+begin)/2;
	
	merge_sort(A,begin,mid);
	merge_sort(A,mid,end);
	merge(A,begin,mid,end);
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
	// Merge Sort
	merge_sort(A,0,n);
	
	print_array(A,0,n);
	return 0;
}
