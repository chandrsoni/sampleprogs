/**
* this is a doubly linked list with sentinels (not circular)
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

#define _Minimum -999999

class node{
	public:
	int key;
	node* prev;
	node* next;

	node(){
		key = _Minimum;
		prev = NULL;
		next = NULL;
	}
	node(int set_key){
		key = set_key;
		prev = NULL;
		next = NULL;
	}

	void operator=(node& node){
		key = node.key;
		prev = node.prev ;
		next = node.next;
	}
};

class l_list{
private:
	int length;
	node* head_sentinel;
	node* tail_sentinel;

public:
	l_list(){
		length = 0;
		head_sentinel = new node();
		tail_sentinel = new node();
		head_sentinel -> next = tail_sentinel;
		tail_sentinel -> prev = head_sentinel;
		head_sentinel -> prev = NULL;
		tail_sentinel -> next = NULL;
	}

	bool search(int value){
		node* x = head_sentinel-> next;
		node* y = tail_sentinel-> prev;
		for (int i = 0; i < length/2; ++i)
		{
			if (x->key == value)
			{
				return true;
			}
			x= x->next;
			if (y->key == value)
			{
				return true;
				x = x->next;
			}
		}
		if (length % 2 == 1)
		{
			if (x-> key == value)
			{
				return true;
			}
		}
		return false;
	}

	void push_back(int value){
		node* new_node = new node(value);
		new_node -> prev = (tail_sentinel->prev);
		new_node -> next = tail_sentinel;
		(tail_sentinel -> prev) -> next = new_node;
		tail_sentinel -> prev = new_node;
		length++;
	}

	void push_front(int value){
		node* new_node = new node(value);
		new_node -> prev = head_sentinel;
		new_node -> next = head_sentinel -> next;
		(head_sentinel -> next) -> prev = new_node;
		head_sentinel -> next = new_node;
		length++;
	}

	int pop_front(){
		if (length == 0)
		{
			printf("list underflow\n");
			exit(1);
		}
		node* iter = head_sentinel -> next;
		head_sentinel->next = iter-> next;
		(iter -> next)->prev = head_sentinel;
		length--;
		return iter->key;
	}

	int pop_back(){
		if (length == 0)
		{
			printf("list underflow\n");
			exit(1);
		}
		node* iter = tail_sentinel -> prev;
		(iter -> prev)->next = tail_sentinel;
		tail_sentinel->prev = iter-> prev;
		length--;
		return iter->key;
	}

	void delete_first(int value){
		node* iter = head_sentinel -> next;
		for (int i = 0; i < length; ++i)
		{
			if (iter-> key == value)
			{
				(iter -> prev)->next = iter-> next;
				(iter -> next)->prev = iter-> prev;
				length--;
				return;
			}
			iter = iter -> next;
		}
		printf("nothing found to delete\n");
	}

	void delete_all(int value){
		node* iter = head_sentinel -> next;
		bool del = false;
		for (int i = 0; i < length; ++i)
		{
			if (iter-> key == value)
			{
				(iter -> prev)->next = iter-> next;
				(iter -> next)->prev = iter-> prev;
				length--;
				del = true;
			}
			iter = iter->next;
		}
		if (!del)
		{
		printf("nothing found to delete\n");		
		}
		return;
	}

	void print_list(){
		node* x= head_sentinel-> next;
		for (int i = 0; i < length; ++i)
		{
			printf("%d\n", x-> key);
			x=x->next;
		}
		return;
	}
};

int main(){
	l_list x;
	x.push_back(1);	
	x.push_front(0);	
	x.print_list();
	x.delete_all(1);
	x.print_list();
	if(x.search(0)){printf("found\n");}
	else{printf("not found\n");}
}