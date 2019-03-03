#include<stdio.h>
#include "multiq.h"

Queue* loadData(char* f)
{
	FILE* fptr = fopen(f, "r");
	int task_id; 
	int pri;
	Queue* mq = createMQ(10);
	while(!feof(fptr))
	{
		scanf("%d", &task_id);
		scanf("%d", &pri);
		
		Task t;
		t.taskid = task_id;
		t.pri = pri;
		mq = addMQ(mq, t);
		
	
	}
	
	return mq;
}

Queue* testDel(Queue* mq, int num)
{
	for(int i = 0; i < num; i++)
	{
		mq = delNextMQ(mq);
	}
	return mq;
}
