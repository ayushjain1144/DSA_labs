/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}

void printSeqList(SeqList seq)
{
	int pointer = seq.head;
	int size = seq.size;
	if(size == 0)
		return;
	while(pointer != -1)
	{
		printJob(st[pointer].ele);
		pointer = st[pointer].next;
	
	}

}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{
	
	int size = sl.size;
	int head = sl.head;
	if(size == 0)
	{
	
	st[head].ele = j;
	st[head].next = -1;
	sl.size++;
	return sl;
	}
	
	int freeloc = nextfreeloc++;
	// check if the job is shorter than head
	if(compare(j, st[head].ele) == LESSER || compare(j, st[head].ele) == EQUAL)
	{
		sl.head = freeloc;
		sl.size++;
		st[freeloc].ele = j;
		st[freeloc].next = head;
		return sl;
		}
	
	int pointer = head;
	
	while(st[pointer].next != -1)
	{
		
		Job curr = st[st[pointer].next].ele;
		if(compare(j, curr) == LESSER || compare(j, curr) == EQUAL)
		{
			
			st[freeloc].ele = j;
			st[freeloc].next = st[pointer].next;
			st[pointer].next = freeloc;
			sl.size++;
			return sl;
				
		
		}
		pointer = st[pointer].next;
		
	
	}	
	
	// tackling the last node
	
	st[pointer].next = freeloc;
	st[freeloc].next = -1;
	st[freeloc].ele = j;	
	sl.size++;
	return sl;
}
  
void insertelements (JobList list , int size, SeqList s[3])
{

	for(int i = 0; i < size; i++)
	{
		if(list[i].pri == 0)
			insert(list[i], s[0]);
		else if(list[i].pri == 1)
			insert(list[i], s[1]);
		else
			insert(list[i], s[2]);
	
	
	}

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{
	int i = 0;
	for(int j = 2; j >= 0; j--){
		int pointer = s[j].head;
		int size = s[j].size;
		if(size == 0)
			continue;
	while(pointer != -1)
	{
		ele[i] = st[pointer].ele;
		pointer = st[pointer].next;
	
	}
	}
}


void printJobList(JobList list, int size)
{
	for(int i = 0; i < size; i++)
		printJob(list[i]);
}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printSeqList(seq[0]);   
 printSeqList(seq[1]);
 printSeqList(seq[2]);
 copy_sorted_ele (seq , list); 
}



