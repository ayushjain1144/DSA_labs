#include<stdio.h>
#include "alloc.h"
#include "linkedlist.h"
#include "cycle.h"

int testCyclic(linkedlist* l)
{
	node* start = l->head;
	node* curr = start;
	node* prev = NULL;
	node* ahead;
	while(curr != NULL)
	{
		ahead = curr->next;
		curr->next = prev;
		prev = curr;
		curr = ahead;
		
		if(curr == start)
			return 1;
		
	}
	
	return 0;
	
}
