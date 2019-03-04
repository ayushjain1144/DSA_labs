#include<stdio.h>
#include "alloc.h"
#include "cycle.h"
#include "linkedlist.h"

int testCyclic(linkedlist* l)
{
	node* hare;
	node* tort;
	
	tort = l->head;
	if(tort == NULL || tort->next == NULL)
		return 0;
	
	hare = tort->next;
	
	while(hare != tort)
	{
		if(hare -> next == NULL || (hare->next)->next == NULL)
			return 0;
		hare = 	(hare->next)->next;
		if(tort -> next == NULL)
			return 0;
		tort = tort -> next;	
	
	}	
	
	return 1;
}
