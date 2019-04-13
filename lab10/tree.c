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

tree* find_p(tree* tr, int val)
{
	
	if(tr == NULL)
	{
		return NULL;
	}
	tree* parent = tr;
	
	if(tr->value == val)
	{
		return NULL;
	}
	
	if(tr->left == NULL && tr->right == NULL)
		return NULL;
	
	if((tr->left != NULL && tr->left->value == val) || (tr->right != NULL && tr->right->value == val))	
		return tr;
	
	
	if(tr->value > val)
	{	
		
		return find_p(tr->right, val);
	
	} 
	
	else 
		return find_p(tr->left, val);
}

int get_height(tree* tr)
{
	
	if(tr == NULL)
		return 0;
		
	int t_l;
	int t_r;	
	t_l = get_height(tr->left);
	t_r = get_height(tr->right);

	if(t_l > t_r)
		return t_l + 1;
	else
		return t_r + 1;	
}

int get_balance(tree* tr)
{
	return get_height(tr->right) - get_height(tr->left);

}

/*
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
				
				if(node->balance = 1)
				{
					node->balance = 0;
				}
				else
					node->balance = -1;
				node = node->left;
					
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

*/
void add(tree* tr, int val)
{
	if(tr->value == INT_MIN)
	{
		tr->value = val;
		return;
	}
	
	tree* node = tr;
	
	tree* insert = (tree*)malloc(sizeof(tree));
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
		add(node->right, val);
		node->balance = get_balance(node);
		
	}
	else
	{
		add(node->left, val);
		node->balance = get_balance(node);
		
	}
	
	tree* x, *y, *z;
	
	if(tr->balance > 1)
	{
		z = tr;
		y = tr->right;
		if(y->value < val)
			x = y->right;
		else
			x = y->left;
		
		rotate(tr, x, y, z);	
				
			
	}	
	
	else if(tr->balance < -1)
	{
		z = tr;
		y = tr->left;
		
		if(y->value < val)
			x = y->right;
		else
			x = y->left;
			
		rotate(tr, x, y, z);		
	
	
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


tree* delet_bt(tree* tr, int val)
{
	if(tr == NULL)
		return tr;
		
	
		
	tree* loc = tr;
	
	if(tr->value > val)
	{
		tr->left = delet_bt(tr->left, val);
		tr->balance = get_balance(tr);
	}
	
	else if(tr -> value < val)
	{
		tr->right = delet_bt(tr->right, val);
		tr->balance = get_balance(tr);
		
	}
	
	else{
	
	
	//leaf
	
	if(loc->left == NULL && loc->right == NULL)
	{
		
		
		free(loc);
		return NULL;
		
		
	}
	
	//if only one child
	
	else if(loc->left == NULL)
	{
		loc = loc->right;
	
		
	}
	
	else if(loc->right == NULL)
	{
		loc = loc->left;
	
	
	}
	
	// if two children
	
	// find next successor
	else
	{
		tree* succ = loc->right;
		//tree* parent = loc;
		while(succ->left != NULL)
		{
			//parent = succ;
			succ = succ->left;
			
	
		}
		
		loc->value = succ->value;
		loc->right = delet_bt(loc->right, succ->value);
		
	
	}
	
	
	
}
tree* x, *y, *z;
	if(loc->balance > 1)
	{
		z = tr;
		y = loc->right;
		if(y->value < val)
			x = y->right;
		else
			x = y->left;
		
		rotate(loc, x, y, z);	
				
			
	}	
	
	else if(loc->balance < -1)
	{
		z = loc;
		y = loc->left;
		
		if(y->value < val)
			x = y->right;
		else
			x = y->left;
			
		rotate(loc, x, y, z);		
	
	
	}
	
	return loc;

		
	
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
	tree* a, *b, *c, *t0, *t1, *t2, *t3;
	
	if(!(z->left == y || z->right ==y ) && (y->left == x || y->right == x) )
	{
		printf("Error\n");
		return;
	}
	
	
	if(z->left == y)
	{
		c = z;
		t3 = z->right;
		
		if(y->left == x)
		{
			b = y;
			a = x;
			t0 = x->left;
			t1 = x->right;
			t2 = y->right;
		}
		
		else
		{
			b = x;
			a = y;
			t0 = y->left;
			t1 = x->left;
			t2 = x->right;
		
		}
	
	}
	
	else
	{
		a = z;
		t0 = z->left;
		
		if(y->left == x)
		{
			c = y;
			b = x;
			
			t1 = x->left;
			t2 = x->right;
			t3 = y->right;
		
		}
		
		else
		{
			c = x;
			b = y;
			t1 = y->left;
			t2 = x->left;
			t3 = x->right;
		
		}
	
	
	}
	
	
	
	tree* copy_a = (tree*)malloc(sizeof(tree));
	tree* copy_c = (tree*)malloc(sizeof(tree));
	tree* copy_b = (tree*)malloc(sizeof(tree));
	
	
	
	copy(a, copy_a);
	copy(c, copy_c);
	copy(b, copy_b);
	
	copy_a->left = t0;
	copy_a->right = t1;
	copy_c->left = t2;
	copy_c->right = t3;
	
	
	
	copy_b->left = copy_a;
	copy_b->right = copy_c;
	
	copy(copy_b, z);
	
	
	
	z->balance = get_balance(z);
	
	z->left->balance = get_balance(z->left);
	
	z->right->balance = get_balance(z->right);
	
	
	
	
		
}

void print_node(tree* tr)
{
	if(tr == NULL)
		return;
	
	printf("value: %d, balance: %d ", tr->value, tr->balance);
	return;	

}

void print_inorder(tree* tr)
{
	
	if(tr == NULL)
		return;	
	
	print_inorder(tr->left);
	print_node(tr);
	print_inorder(tr->right);
	

}

int main(void)
{
	int n;
	scanf("%d", &n);
	
	tree* tr = createTree();
	
	for(int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val); 
		add(tr, val);
			
	}
	
	print_inorder(tr);
	printf("--------------------------------------\n");
	
	delet_bt(tr, 50);
	print_inorder(tr);
	printf("--------------------------------------\n");
	
	delet_bt(tr, 30);
	print_inorder(tr);
	printf("--------------------------------------\n");
	
	
	delet_bt(tr, 80);
	print_inorder(tr);
	printf("--------------------------------------\n");
	
	
	delet_bt(tr, 60);
	print_inorder(tr);
	printf("--------------------------------------\n");
	
	delet_bt(tr, 40);
	print_inorder(tr);
	printf("--------------------------------------\n");
	
	
	delet_bt(tr, 20);
	print_inorder(tr);
	printf("--------------------------------------\n");
	
	
	
	print_inorder(tr);

}


















