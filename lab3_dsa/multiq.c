#include<stdio.h>
#include<stdlib.h>

#include "que.h"
#include "multiq.h"

int num = 10;

Queue** createMQ(int num)
{


	Queue** mq = (Queue**) malloc(num * sizeof(Queue*));
	
	
	
	for(int i = 0; i < num; i++)
	{
		mq[i] = newQ();
	
	}
	return mq;
	
	
	
}

//make sure that priority p is less than num in main(also neg)
void addMQ(Queue** mq, Task t)
{
	int priority_idx = t.pri - 1;
	
	printf("Priority INdex: %d\n", priority_idx);
	addQ(mq[priority_idx], t.taskid);
	

}


int nextMQ(Queue** mq)
{
	return front(mq[0]);
	
}


void delNextMQ(Queue** mq)
{
	delQ(mq[0]);

}

int isEmptyMQ(Queue** mq)
{
	
	for(int i = 0; i < num; i++)
	{
		if(!isEmptyQ(mq[i]))
			return 0;
	
	}
	return 1;
}

int sizeMQ(Queue** mq)
{
	int count = 0;
	for(int i = 0; i <num; i++)
	{
	
		count += lengthQ(mq[i]);
	}
	
	return count;
}


int sizeMQbyPriority(Queue** mq, int p)
{
	return lengthQ(mq[p]);
}

Queue getQueueFromMQ(Queue** mq, int priority)
{
	return *(mq[priority - 1]);

}

