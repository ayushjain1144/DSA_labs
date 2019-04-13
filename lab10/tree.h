#ifndef _TREE
#define _TREE


typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right;
	int balance : 2;

}tree;
tree* createTree();

void add_iter(tree* tr, int val);

void add_recur(tree* tr, int val);

tree* find(tree* tr, int val);

void delet_bt(tree* tr, int val);

void rotate(tree* bt, tree* x, tree* y, tree* z);
#endif
