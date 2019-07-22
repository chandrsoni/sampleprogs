/**
* the concept is to have right sibling instead of right child
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

class rooted_tree{
private:
	node* root;
};

int main(){}