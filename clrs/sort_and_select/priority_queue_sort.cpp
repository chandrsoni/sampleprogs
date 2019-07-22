#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#define Minimum -999999



class priority_queue{
private:
	vector<int> A;
	void swap(int f_index,int s_index){
		int swap_int = A[f_index];
		A[f_index] = A[s_index];
		A[s_index] = swap_int;
		return;
	}
public:
	
	int maximum(){
		if(A.size() <= 0){return -1;}
		return A[0];
	}
	
	void max_heapify(int i){
		int n = A.size();
		if(2*i+1>=n)return;
		int largest_index = i;
		if(A[2*i+1] > A[largest_index])largest_index = 2*i+1;
		if(2*i+2 < n){if( A[2*i+2] > A[largest_index])largest_index = 2*i+2;}

		if (largest_index == i)
		{
			return;
		}
		swap(i,largest_index);
		max_heapify(largest_index);
		return;
	}
	
	int extract_max(){
		int result = A[0];
		A[0] = A[A.size()-1];
		A.pop_back();
		max_heapify(0);
		return result;
	}

	void increase_key(int pos,int val){
		if (pos >= A.size() || A[pos] > val)
		{
			printf("invalid change in input key\n");
			printf("%d %ld %d %d\n",pos,A.size(),val,A[pos] );
			return;
		}
		int parent = (pos+1)/2 - 1;
		A[pos] = val;
		while(pos>0 && A[parent]< A[pos]){
			swap(parent,pos);
			pos = parent;
			parent = (pos+1)/2 - 1;
		}
		return;
	}

	void insert(int value){
		A.push_back(Minimum);
		increase_key(A.size() - 1,value);
	}

	void print_queue(){
		while( A.size() >0)
		{
			printf("%d\n",extract_max() );
		}
		return;
	}
};


int main(){
	priority_queue A;
	// input
	printf("insert values and end with a -1\n");
	int n;scanf("%d",&n);
	while(n != -1){
		A.insert(n);
		scanf("%d",&n);
	}
	A.print_queue();
	return 0;
}
