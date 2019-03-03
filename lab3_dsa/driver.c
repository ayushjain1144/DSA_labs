#include<stdio.h>
#include<sys/time.h>
#include "multiq.h"

void loadData(FILE* fptr, Queue** mq)
{
	
	int task_id; 
	int pri;
	while(fscanf(fptr, "%d,%d", &task_id, &pri) != EOF)
	{
		//2fscanf(fptr, "%d", &pri);
		printf("Read that: %d %d\n", task_id, pri);
		Task t;
		t.taskid = task_id;
		t.pri = pri;
		addMQ(mq, t);
		
	
	}
	
}


int main(void)
{
	struct timeval t1, t2;
	double elapsedTime;
	
	gettimeofday(&t1, NULL);
	
	FILE* fptr = fopen("input10000.txt", "r");
	Queue** mq = createMQ(10);
	loadData(fptr, mq);
	
	
	gettimeofday(&t2, NULL);
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time is %fms.\n", elapsedTime);
	
	return 0;
}
