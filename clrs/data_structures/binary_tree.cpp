/**
* the idea is to represent the tree by its root node 
* and maintain other properties for the nodes itself
* 
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

	void operator=(node& n){
		value = n.value;
		parent = n.parent;
		left = n.left;
		right = n.right;
	}

	node* search(int x){
		if (this == NULL)
		{
			return NULL;
		}
		if (value == x)
		{
			return this;
		}
		else{
			if (value > x)
			{
				if (left != NULL)
				{
					return left -> search(x);
				}
				else{
					return NULL;
				}
			}
			else
			{
				if (right != NULL)
				{
					return right -> search(x);
				}
				else{
					return NULL;
				}
			}
		}
		return NULL;
	}

	void pre_order(){
		if (this == NULL)
		{
			return;
		}
		printf("%d\n", value );
		bool leaf = true;
		if ( left != NULL)
		{
			printf("left\n");
			left -> pre_order();
			leaf = false;
		}
		if (right != NULL)
		{
			printf("right\n");
			right -> pre_order();
			leaf = false;
		}
		if (leaf)
		{
			printf("leaf reached\n");
		}
		return;
	}

	node* tree_minimum(){
		if ( left == NULL )
		{
			return this;
		}
		else{
			return left -> tree_minimum();
		}
	}

	node* tree_maximum(){
		if ( right == NULL )
		{
			return this;
		}
		else{
			return right -> tree_maximum();
		}
	}

	node* successor(){
		if (right != NULL)
		{
			return right -> tree_minimum();
		}
		node* x = this;
		node* y = parent;
		while(y != NULL && x == y -> right){
			x = y;
			y = y -> parent;
		}
		return y;
	}
};

class bin_tree{

private:
	node* root;

public:
	bin_tree(){
		root = NULL;
	}

	void insert(int value){
		node* y = NULL;
		node* x = root;
		while(x != NULL){
			y = x;
			if (value < x-> value)
			{
				x = x->left;
			}
			else {
				x = x->right;
			}
		}
		node* new_node = new node();
		new_node -> value = value;
		new_node -> parent = y;
		if (y == NULL)
		{
			root = new_node;
		}
		else {
			if (value < y -> value)
			{
				y -> left = new_node;
			}
			else {
				y -> right = new_node;
			}
		}
	}

	node* search(int value){
		return root -> search(value);
	}

	void delete_node(node* value)
	{
		if (root == NULL)
		{
			printf("the tree is empty, exiting \n");
			exit(1);
		}
		node* x; // to be joined back
		node* y; // to be removed

		// either the node or its successor must have an empty left or right branch 
		if (value -> left == NULL || value -> right == NULL)
		{
			y = value;
		}
		else{
			y = value -> successor();
		}

		// to get the non empty side
		if (y -> left != NULL)
		{
			x = y -> left;
		}
		else{
			x = y -> right;
		}

		// make the non empty side's parent as the current node's parent 
		if (x != NULL)
		{
			x -> parent = y -> parent;
		}
		
		// substitute the non empty side for the node
		if (y -> parent == NULL)
		{
			root = x;
		}
		else{
			if (y == (y -> parent) -> left)
			{
				(y -> parent) -> left = x;	
			}
			else{
				(y -> parent) -> right = x;
			}
		}

		//replace the value of the removed node with the value to be removed
		if (y != value)
		{
			value -> value = y -> value;
		}
		delete y;

		return;
	}

	void delete_root(){
		delete_node(root);
	}

	void print_tree(){
		root -> pre_order();
		return;
	}

};

int main(){
	bin_tree x;
	x.insert(11);
	x.insert(2);
	x.insert(14);
	x.insert(1);
	x.insert(7);
	x.insert(5);
	x.insert(4);
	x.insert(8);
	x.insert(15);
	for (int i = 0; i < 16; ++i)
	{
		if (x.search(i) != NULL)
		{
			cout<< i<< "	"<< x.search(i) -> value<< endl;
		}
		else{
			cout<< i<< "	"<< x.search(i) << endl;
		}
	}
	x.print_tree();
}