#ifndef _LIST
#define _LIST

typedef struct node
{
	int data;
	struct node* next;
}node;

typedef struct linkedlist
{
	node* head;
	int capacity;

}linkedlist;

#endif
