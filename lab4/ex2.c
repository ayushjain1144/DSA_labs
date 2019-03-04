#include<stdio.h>
#include<stdlib.h>

#include "alloc.h"

int count = 0;

void* myalloc(int size_in_bytes)
{
	count += size_in_bytes;
	return malloc(size_in_bytes);

}

void myfree(void* ptr, int size)
{
	count-=size;
	free(ptr);
	return;

}

/*
int main(void)
{	
	while(1)
	{
		int m = (rand() % (25000 - 10000 + 1)) + 10000;
		int* arr = (int *)myalloc(m * sizeof(int));
		if(arr == NULL)
			return 0;
		printf("First: %u, Last: %u\n", &arr[0], &arr[m - 1]);
		printf("Count: %d\n", count);
		myfree(arr, m * sizeof(int));
		printf("Count: %d\n", count);
	}
	

}
*/

