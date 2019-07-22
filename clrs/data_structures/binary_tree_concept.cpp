/**
* each node has stored a 
* 	a). parent
*	b). left child
*	c). right child
*	d). value
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

#define Nil -999999

class node{
public:
	int value;
	node* parent;
	node* left;
	node* right;
	node(){
		value = Nil;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

class bin_tree{
private:
	node* root;
};

int main(){}