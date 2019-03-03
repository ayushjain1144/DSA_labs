#ifndef _MULTIQ
#define _MULTIQ
#include "que.h"

/*
typedef struct
{
	Queue* q;


}MultiQ;
*/

extern int num;
typedef struct
{
	int taskid;
	int pri;

}Task;

Queue** createMQ(int num);

void addMQ(Queue** mq, Task t);

int nextMQ(Queue** mq);

void delNextMQ(Queue** mq);

int isEmptyMQ(Queue** mq);

int sizeMQ(Queue** mq);

int sizeMQbyPriority(Queue** mq, int p);

Queue getQueueFromMQ(Queue** mq, int priority);



#endif

