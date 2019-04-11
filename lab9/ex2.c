#include<stdio.h>
#include<stdlib.h>
#include "hash.h"
#include "chain.h"
#include<string.h>

#define T_SIZE 5000
#define BASE 8531

Table* createTable(void)
{
	Table* t1 = (Table*)malloc(sizeof(Table));
	
	/*
	t1->arr = (char**)malloc(sizeof(char*) * T_SIZE);
	
	for(int i = 0; i < T_SIZE; i++)
	{
		t1->arr[i] = (char*) malloc(sizeof(char) * 20);
		t1->arr[i] = NULL;
	}
	
	*/
	
	t1->insertionCost = 0;
	t1->queryingCost = 0;
	
	
	for(int i = 0; i < 5000; i++)
		(t1->arr[i]).head = NULL;
		
		
	return t1;
	

}

int insertion(Table* t1, char** arr, int j)
{

	t1->elementCount++;
	int h = hash(arr[j], BASE, T_SIZE);
	
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->index = j;
	temp->count = 1;
	temp->next = NULL;
	
	//if no element is there
	if((t1->arr[h]).head == NULL)
	{
		(t1->arr[h]).head = temp;
		return  t1->insertionCost;
	}
	
	Node* loop = (t1->arr[h]).head;
	
	while(loop->next != NULL)
	{
		(t1->insertionCost)++;
		
		if(strcmp(arr[loop->index], arr[j]) == 0)
		{
			loop->count++;
			free(temp);
			return t1->insertionCost;
		}
		
		loop = loop->next;
	
	}
	
	//it was not in the list or in the last
	t1->insertionCost++;
	if(strcmp(arr[loop->index], arr[j]) == 0)
	{
		loop->count++;
		free(temp);
		return t1->insertionCost;
	}
	
	t1->insertionCost++;
	loop->next = temp;
	
	return t1->insertionCost;
		

}

int insertall(Table* t1, char* arr[])
{
	for(int i = 0; i < g_size; i++)
	{
		insertion(t1, arr, i);
	
	}
	
	return t1->insertionCost;

}

int lookup(Table* t1, char* str, char* arr[])
{
	int h = hash(str, BASE, T_SIZE);
	
	Node* temp = (t1->arr[h]).head;
	
	while(temp != NULL)
	{
		t1->queryingCost++;
		if(strcmp(arr[temp->index], str) == 0)
		{
		
			return t1->queryingCost;
		
		}
		
		temp = temp->next;
	
	}
	
	printf("String not present\n");
	return t1->queryingCost;

}

int lookupall(Table* t1, char* arr[], int m, int num_elem, char** book)
{
	t1->queryingCost = 0;
	
	int num = m * num_elem;
	
	for(int i = 0; i < num; i++)
	{
		lookup(t1, arr[i], book);
	
	}
	printf("querying_cost: %d\n", t1->queryingCost);
	return t1->queryingCost;
	

}
void printlist(Linkedlist l, char** arr)
{
	Node* temp = l.head;
	
	while(temp!= NULL)
	{
		printf("string: %s, count: %d\n", arr[temp->index], temp->count);
		temp = temp->next;
	}
	
	printf("\n");

}
void printTable(Table* t1, char** arr)
{
	for(int i = 0; i < 1000; i++)
	{
		printf("%d\n", t1->insertionCost); 
		printlist(t1->arr[i], arr);
	}	

}


void delete_from_hash(char** arr_del, Table* t1, char** book, int num_del)
{
	for(int i = 0; i < num_del; i++)
	{
		int h = hash(arr_del[i], BASE, T_SIZE);
		
		if((t1->arr[h]).head == NULL)
			continue;
		
		//if it is the first element
		if(strcmp(book[(t1->arr[h]).head->index], arr_del[i]) == 0)
		{
			Node* temp1 = (t1->arr[h]).head;
			(t1->arr[h]).head = (t1->arr[h]).head->next;
			free(temp1);
		}
		
		Node* temp = (t1->arr[h]).head;
		
		while(temp != NULL)
		{
			if(strcmp(book[temp->index], arr_del[i]) == 0)
			{
			
				if(temp->count > 1)
				{
					temp->count++;
					break;
				}
				Node* Next = temp->next;
				if(Next == NULL)
				{
					free(temp);
					break;
				
				}
				
				temp->index = Next->index;
				temp->count = Next->count;
				temp->next = Next->next;
				free(Next);
				break;
			}
			
			temp = temp->next;
		
		}
		
	
	}

}










