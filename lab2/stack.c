#include <stdio.h>


void push(struct linkedList* head, int ele)
{
	insertFirst(head, ele);	
	
}

struct node* pop(struct linkedList* head)
{
	deleteFirst(head);

}
