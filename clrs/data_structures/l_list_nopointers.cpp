/**
* this is a doubly linked list with no use of pointers and a head sentinel
* array objects are as 
* 	1). next
*	2). key
*	3). prev
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

#define list_len 21
#define Nil -999999

class l_list{
private:
	int Array[list_len];
	int root;
	int length;
	int free_index;
public:
	l_list(){
		length = 0;
		root = Nil;
		for (int i = 0; i < list_len/3; ++i)
		{
			Array[3*i] = 3*i+3;
			Array[3*i+1] = Nil;
			Array[3*i+2] = 3*i - 3;
		}
		Array[2] = Nil;
		Array[list_len-3] = Nil;
		free_index = list_len-3;

		// create a head sentinel
		root = allocate();
		Array[root] = Nil;
		Array[root+1] = Nil;
		Array[root+2] = Nil;
		return;
	}

	int allocate(){
		int result = free_index;
		free_index = Array[free_index+2];
		if (free_index == Nil)
		{
			printf("list overflow\n");
			exit(1);
		}
		return result;
	}
	void free_object(int index){
		Array[free_index] = index;
		Array[index+2] = free_index;
		Array[index+1] = Nil;
		Array[index] = Nil;
		free_index = index;
		return;
	}

	void push_front(int value){
		int position = allocate();
		Array[position] = Array[root];		
		Array[position+1] = value;
		Array[position+2] = root;
		if (Array[root]!=Nil)
		{
			Array[Array[root]+2] = position;
		}
		Array[root] = position;
		length++;
		return;
	}

	void push_back(int value){
		if (length == 0)
		{
			push_front(value);
			return;
		}
		int index = Array[root];
		while(Array[index] != Nil){
			index = Array[index];
		}

		int position = allocate();
		Array[position] = Array[index];		
		Array[position+1] = value;
		Array[position+2] = root;
		if (Array[index]!=Nil)
		{
			Array[Array[index]+2] = position;
		}
		Array[index] = position;
		length++;
		return;
	}

	void print_list(){
		if (length == 0)
		{
			return;
		}
		int index = Array[root];
		while(Array[index] != Nil){
			printf("%d\n",Array[index+1] );
			index = Array[index];
		}
		printf("%d\n",Array[index+1] );
		return;
	}
};

int main(){
	l_list list;
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.print_list();
	return 0;
}