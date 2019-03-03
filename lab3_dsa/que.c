#include "que.h"
#include<stdlib.h>


//bool isEmptyQ(Queue q);

Queue* newQ()
{
	Queue* q;
	q = (Queue*)malloc(sizeof(Queue));
	q->first = NULL;
	q->last = NULL;
	return q;


}


int isEmptyQ(Queue* q)
{
	if(q->first == NULL)
		return 1;
	else
		return 0;	


}

void delQ(Queue* q)
{
	if(isEmptyQ(q))
	{
		printf("Empty queue\n");
		return;
	}
	struct node* temp = q->first;
	q->first = temp->next;
	free(temp);

}

int front(Queue* q)
{
	if(isEmptyQ(q))
	{
		printf("Queue is empty\n");
		return -1;
	}
	return (q->first)->element;

}

void addQ(Queue* q, int ele)
{
	struct node* link = (struct node*)malloc(sizeof(struct node));
	link->element = ele;
	
	if(isEmptyQ(q))
	{
		link->next = NULL;
		q->first = link;
		q->last = link;
		return;
	
	}
	
	(q->last)->next = link;
	q->last = link;


}

int lengthQ(Queue* q)
{
	struct node* link = q->first;
	int count = 0;
	while(link != NULL)
	{
		count++;
		link = link->next;
	
	}
	return count;
	
}

/*
Just for testing purposes.

int main(void)
{
	Queue q = newQ();
	printf("Is empty: %d\n", isEmptyQ(q));
	q = delQ(q);
	
	int front_ele = front(q);
	printf("Front element: %d\n", front_ele);
	
	q = addQ(q, 1);
	printf("Length of queue: %d\n", lengthQ(q));
	
	q = addQ(q, 2);
	printf("Length of queue: %d\n", lengthQ(q));
	
	q = addQ(q, 3);
	printf("Length of queue: %d\n", lengthQ(q));
	
	q = delQ(q);
	
	printf("Length of queue: %d\n", lengthQ(q));
	
	front_ele = front(q);
	printf("Front element: %d\n", front_ele);
	
	printf("Is empty: %d\n", isEmptyQ(q));



}

*/
