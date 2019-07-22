/** 
* Stack implemented using arrays
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

#define _Max 999999

class stack{
	
	int st_array[_Max];
	int length;

public:
	
	stack(){
		length = 0;
	}
	
	void operator=(stack& cp_stack){
		length = cp_stack.length;
		for (int i = 0; i < length; ++i)
		{
			st_array[i] = cp_stack.st_array[i];
		}
	}

	void push(int value){
		if (length == _Max)
		{
			printf("Stack overflow\n");
			exit(1);
		}
		st_array[length] = value;
		length++;
	}

	int pop(){
		if (length == 0)
		{
			printf("stack underflow\n");
			exit(1);
		}
		length --;
		return st_array[length];
	}
};

int main(){
	stack s;
	s.push(1);
	s.pop();
}