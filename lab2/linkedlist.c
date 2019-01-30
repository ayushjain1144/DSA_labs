#include<stdio.h>
#include<stdlib.h>

#include "linkedlist.h"

void insertFirst(struct linkedList* head, int ele)
{
	struct node* link = (struct node*) malloc(sizeof(struct node));
	
	link->element = ele;
	link->next = head->first;
	head->first = link;
	head->count++;
}

struct node* deleteFirst(struct linkedList* head)
{
	if(head->count == 0)
	{
		printf("List is empty\n");
		return NULL;
	
	}
	struct node* temp = head->first;
	head->first = temp->next;
	head->count--;
	return temp;
}

void printList(struct linkedList* head)
{
	struct node* link = head->first;
	printf("%d\n",head->count);
	
	while(link != NULL)
	{
		
		printf("%d\n", link->element);
		link = link->next;
		
	
	}



}
int search(struct linkedList* head, int ele)
{
	struct node* link = head->first;
	while(link != NULL)
	{
		if(link->element == ele)
			return 1;
		link = link->next;
	}
	return 0;


}

struct node* delete(struct linkedList* head, int ele)
{
	struct node* link = head->first;
	struct node* temp;
	if(head->count == 0)
	{
		printf("List is empty\n");
		return NULL;
	
	}
	if(link->element == ele)
	{
		head->first = link->next;
		head->count--;
		return link;
		
	
	}
	while(link->next != NULL)
	{
		if(link ->next -> element == ele)
		{
			temp = link->next;
			link->next = temp->next;
			head->count--;
			return temp;
		
		}
		temp = link;
		link = temp->next;
	
	
	}
	
	if(link->element == ele)
	{
		temp->next = NULL;
		head->count--;
		return link;
		
	}
	
	printf("Error, no such element\n");
	return NULL;



}
	
