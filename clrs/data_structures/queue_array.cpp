/** 
* Queue implemented using arrays
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

#define _Max 10

class queue{
	int q_array[_Max]; // actual capacity is _Max - 1
	int head;
	int tail;
public:
	queue(){
		head = tail = 0;
	}
	void enqueue(int value){
		if ((head-tail+ _Max) % _Max == 1)
		{
			printf("queue overflow\n");
			exit(1);
		}
		q_array[tail] = value;
		tail++;
		if (tail == _Max)
		{
			tail = 0;
		}
		return;
	}
	int dequeue(){
		if (head == tail)
		{
			printf("queue underflow\n");
			exit(1);
		}
		int value = q_array[head];
		head++;
		if (head == _Max)
		{
			head = 0;
		}
		return value;
	}
};

int main(){
	queue q;
}