#ifndef _QUEUE
#define _QUEUE
#include <stdio.h>
#include<stdbool.h>


struct node{
	int element;
	struct node* next;

};

typedef struct
{
	struct node* first;
	struct node* last;
	

}Queue;




Queue* newQ();


int isEmptyQ(Queue* q);

void delQ(Queue* q);

int front(Queue* q);

void addQ(Queue* q, int ele);

int lengthQ(Queue* q);

#endif
