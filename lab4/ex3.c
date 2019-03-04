#include<stdio.h>
#include "alloc.h"
#include "linkedlist.h"
#include<stdlib.h>
#include "cycle.h"
#include<time.h>

linkedlist* createList(int n)
{

	//initialize the list
	linkedlist* l;
	l = (linkedlist*)myalloc(sizeof(linkedlist));
	l->capacity = 0;
	l->head = NULL;
	node* temp = l->head;
	srand(time(0));
	for(int i = 0; i < n; i++)
	{
		
		int ele = (rand()/100000)*10;
		node* key = (node*)myalloc(sizeof(node));
		key->data = ele;
		key->next = NULL;
		if(temp == NULL)
		{
			l->head = key;
			temp = l->head;
		}
		else
		{
			temp->next = key;
			temp = temp->next;
		}
		l->capacity +=1;
			
	}
	
	
	return l;
}

linkedlist* createCycle(linkedlist* ls)
{
	int toss = rand()%2;
	printf("Toss: %d\n", toss);
	if(toss == 0)
	{
		return ls;
	}
	
	else
	{
		int size_of_list = ls->capacity;
		int random = rand()%size_of_list;
		//random = 9;
		printf("bcb : %d\n", random);
		node* temp = ls->head;
		node* rand_node;
		int i = 0;
		while(temp->next != NULL)
		{
			if(i == random)
			{
				rand_node = temp;
			}
			temp = temp->next;
			i++;
		}
		if(i == size_of_list - 1)
		{
			rand_node = temp;
		}
		temp->next = rand_node;
		
		return ls;
		
	
	
	}

}

void printList(linkedlist* l)
{
	node* temp = l->head;
	
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		
		temp = temp->next; 
	}
}

void makeCircularList(linkedlist* l)
{
	if(testCyclic(l) == 0)
	{
		node* temp = l->head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = l->head;
		
		if(testCyclic(l) == 1)
			printf("Success\n");
			
	}
	
	else
	{
	node* hare;
	node* tort;
	
	tort = l->head;
	
	
	hare = tort->next;
	
	while(hare != tort)
	{
		
		hare = 	(hare->next)->next;
		
		tort = tort -> next;	
	
	}	
	hare = l->head;
	while(hare!= tort)
	{
		node* temp = hare->next;
		myfree(hare, sizeof(node));
		l->head = temp;
		hare = temp;
		tort = tort->next;
	}
	if(testCyclic(l) == 1)
			printf("Success is yours\n");
	}
	

}
int main(void)
{
	linkedlist* l = createList(10);
	printList(l);
	l = createCycle(l);
	/*
	if(testCyclic(l) == 0)
		printf("Linear\n");
	else
		printf("Cyclic\n");	
	*/
	
	makeCircularList(l);
	node* temp = l->head;
	for(int i = 0; i < 9; i++)
	{
		temp = temp->next;
	}
	
	if(temp->next == l->head)
	{
		printf("Done\n");
	}
	
	FILE* f_space = fopen("heap_space.txt", "a");
	
	fprintf(f_space, "space for %d: %d\n", 10, count);
	
	fclose(f_space);
	


}
