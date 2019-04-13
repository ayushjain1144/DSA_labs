#include<stdio.h>
#include "tree.h"
#include<limits.h>
#include<stdlib.h>

tree* createTree()
{
	tree* tr = (tree*)malloc(sizeof(tree));
	tr->value = INT_MIN;
	tr->left = NULL;
	tr->right = NULL;
	tr->balance = 0;
	
	return tr;
}

void add_iter(tree* tr, int val)
{
	//if tree is emplty
	if(tr->value == INT_MIN)
	{
		tr->value = val;
		return;
	}
	
	tree* node = tr;
	
	tree* insert = (tree*)malloc(sizeof(malloc));
	insert->value = val;
	insert->left = NULL;
	insert->right = NULL;
	insert->balance = 0;
	
	while(1)
	{
		if(node->value > val)
		{
			if(node->left != NULL)
			{
				node = node->left;
				if(node->balance = 1)
				{
					node->balance = 0;
				}
				else
					node->balance = -1;
			}
				
			else
			{
				node->left = insert;
				node->balance -= 1;
			}	
				
		}
		
		else 
		{
			if(node->right != NULL)
			{
				node = node->right;
				if(node->balance = -1)
				{
					node->balance = 0;
				}
				else
					node->balance = 1;
			}
				
			else
			{
				node->right = insert;
				node->balance += 1;
			}
			
		
		}
		
		
	}	

}


void add_recur(tree* tr, int val)
{
	if(tr->value == INT_MIN)
	{
		tr->value = val;
		return;
	}
	
	tree* node = tr;
	
	tree* insert = (tree*)malloc(sizeof(malloc));
	insert->value = val;
	insert->left = NULL;
	insert->right = NULL;
	insert->balance = 0;
	
	if(tr->value > val && tr->left == NULL)
	{
		tr->left = insert;
		tr->balance -= 1;
		return;
	}
	
	if(tr->value <= val && tr->right == NULL)
	{
		tr->right = insert;
		tr->balance += 1;
		return;
	}
	
	if(node->value < val)
	{
		add_recur(node->left, val);
		return;
	}
	else
	{
		add_recur(node->right, val);
		return;
	}	
	
}

tree* find(tree* tr, int val)
{
	if(tr == NULL)
	{
		return NULL;
	}
	if(tr->value == val)
	{
		return tr;
	}
	
	
	if(tr->value > val)
	{
		return find(tr->right, val);
	
	} 
	
	else 
		return find(tr->left, val);
}


void delet_bt(tree* tr, int val)
{
	if(tr == NULL)
		return;
		
	tree* loc = find(tr, val);
	if(loc == NULL)
	{
		printf("Element not there\n");
		return;
	}
	
	//leaf
	
	if(loc->left == NULL && loc->right == NULL)
	{
		free(loc);
		return;
		
	}
	
	//if only one child
	
	if(loc->left == NULL)
	{
		tree* del = loc->right;
		loc->value = loc->right->value;
		loc->left = loc->right->left;
		loc->right = loc->right->right;
		loc->balance = loc->right->balance;
		free(loc->right);
		
	}
	
	else if(loc->right == NULL)
	{
		tree* del = loc->left;
		loc->value = loc->left->value;
		loc->left = loc->left->left;
		loc->right = loc->left->right;
		loc->balance = loc->left->balance;
		free(loc->left);
	
	
	}
	
	// if two children
	
	// find next successor
	
	tree* succ = loc->right;
	while(succ -> left != NULL)
	{
		succ = succ->left;
	
	}
	
	loc->value = succ->value;
	//balance lite
	free(succ);
	
	return;
	
	
	
}

void copy(tree* src, tree* dest)
{
	dest->value = src->value;
	dest->left = src->left;
	dest->right = src->right;
	dest->balance = src->balance;
}

void rotate(tree* bt, tree* x, tree* y, tree* z)
{
	tree* a = (tree*)malloc(sizeof(tree));
	tree* b = (tree*)malloc(sizeof(tree));
	tree* c = (tree*)malloc(sizeof(tree));
	
	
	copy(x, a);
	copy(y, b);
	copy(z, c);
	
	tree* t0 = x->left;
	tree* t1 = x->right;
	
	tree* t2;
	tree* t3;
	
	if(z->balance = -1)
	{
		t2 = y->right;
		t3 = z->right;
		
		b->left = a;
		b->right = c;
		a->left = t0;
		a->right = t1;
		c->left = t2;
		c->right = t3;
	
	}
	
	else
	{
	
		t2 = y->left;
		t3 = z->left;
		
		b->left = c;
		b->right = a;
		a->left = t0;
		a->right = t1;
		c->left = t3;
		c->right = t2;
		
	
	}
	
	copy(b, y);
	free(z);
	free(x);
	free(b);
	
	return;
	


	
	
	

}
















