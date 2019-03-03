#include<stdio.h>
#include "bank.h"
#include<sys/time.h>

int main(int argc, char* argv[])
{	

	char c;
	if(argc != 2)
	{
		printf("INvalid inputs\n");
		return 2;
	} 
	FILE* f1 = fopen(argv[1], "r");
	if(f1 == NULL)
	{
		printf("Couldn't open\n");
		return 1;
	
	}
	
	
	struct timeval t1, t2;
	double elapsedTime;
	
	gettimeofday(&t1,NULL);
	int mem = 20;
	bank* arr = readRecords(f1, &mem);
	fclose(f1);
	
	FILE* fp2 = fopen("unsorted.txt", "w");
	FILE* fp1 = fopen("sorted.txt", "w");
	for(int j = 0; j < mem; j++)
		fprintf(fp2, "%llu\n", arr[j].card_num);
	insertion_sort(arr, mem);
	for(int j = 0; j < mem; j++)
		fprintf(fp1, "%llu\n", arr[j].card_num);
		
		
		
	gettimeofday(&t2, NULL);
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time is %lfms\n", elapsedTime);
	FILE* fp = fopen("insertion_sort_time.txt", "a");
	if(fp == NULL)
	{
		printf("Not opening\n");
		return 3;
	
	}
	char d;
	int diff = (int)(p1 - p2);
	fprintf(fp, "%s: %lf %d\n", argv[1], elapsedTime, diff);
	fclose(fp);
	
	

}
