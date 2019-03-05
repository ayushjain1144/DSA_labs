#include "List.h"
#include<stdlib.h>
#include<time.h>
//int globalCounter = 0;
List createList(Student studArray, int arraySize)
{
	
	List l;
	l = (List)myalloc(sizeof(struct list));
	l->count = 0;
	l->first = NULL;
	l->last = NULL;	
	
	if(arraySize == 0)
		return l;
	Node temp;
	temp = (Node)myalloc(sizeof(struct node));
	temp->record = (Student)myalloc(sizeof(struct student));
	*(temp->record) = studArray[0];
	temp->next = NULL;
	
	l->first = temp;
	l->last = temp;
	l->count++;
	for(int i = 1; i < arraySize; i++)
	{
		Node temp1 = (Node)myalloc(sizeof(struct node));
		temp1->record = (Student)myalloc(sizeof(struct student));
		*(temp1->record) = studArray[i];
		temp1->next = l->first;
		
		l->count++;
		l->first = temp1;
		
	}

	return l;
		

}

void my_printList(List l)
{
	Node temp = l->first;
	
	while(temp!=NULL)
	{
		printf("name : %s, marks: %f\n", (temp->record)->name, (temp->record)->marks);
		temp = temp->next;
	
	}

}


void insertInOrder(List list, Node newNode)
{
	list->count+=1;
	
	Node temp = list->first;
	
	if(list->first == NULL)
	{
		newNode->next = NULL;
		list->first = newNode;
		list->last = newNode;
		return;
	}
	
	//insert at start
	if(((list->first)->record)->marks >= (newNode->record)->marks)
	{
		newNode->next = list->first;
		list->first = newNode;
		printf("here\n");
		return;
	}
	
	if(((list->last)->record)->marks <= (newNode->record)->marks)
	{
		newNode->next = NULL;
		list->last->next = newNode;
		list->last = newNode;
		return;
	}
	
	while(temp->next != NULL)
	{
		if(temp->next->record->marks > newNode->record->marks)
		{
			newNode->next = temp->next;
			temp->next = newNode;
			return;
		}
		temp = temp->next;
	}

}

List insertionSort(List list)
{
	
	if(list->first == NULL)
		return list;
	List newlist;
	newlist = (List)myalloc(sizeof(struct list));
	newlist->count = 0;
	newlist->first = NULL;
	newlist->last = NULL;
	
	
	Node ptr = list->first;
	while(ptr!= NULL)
	{
		Node temp = (Node)myalloc(sizeof(struct node));
		temp->record = ptr->record;
		temp->next = NULL;
		insertInOrder(newlist, temp);
		ptr = ptr->next;
	
	}
	
	return newlist;
	

}
void* myalloc(int size)
{
	globalCounter += size;
	
	int* ptr = (int*)malloc(size + sizeof(int));
	*ptr = size;
	return (((void*)ptr) + 4);

}

void myfree(void* ptr)
{
	int size = *(((int*)ptr) - 4);
	globalCounter -= size;
	
	free(ptr);
	return;
}
double measureSortingTime(List list)
{
	struct timeval t1, t2;
	double elapsedTime;
	
	gettimeofday(&t1, NULL);
	List newlist = insertionSort(list);	
	gettimeofday(&t2, NULL);
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime = (t2.tv_usec - t1.tv_usec) / 1000.0;
	return elapsedTime;

}
