#include "qsort.h"
#include<stdio.h>
#include<stdlib.h>

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}


int* readData(char* fileName)
{
	FILE* fp = fopen(fileName, "r");
	if(fp == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	int num;
	fscanf(fp, "%d\n", &num);
	size = num;
	int* arr = (int *)malloc(sizeof(int) * num);
	
	for(int i = 0; i < num; i++)
	{
		fscanf(fp, "%*[^\t]%d\n", &arr[i]);
		
	}
	
	return arr;
	
	
}

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey)
{
	KeyStruct keysarr;
	keysarr = (KeyStruct)malloc(sizeof(struct keyStruct));
	keysarr->Keys = (int*)malloc(sizeof(int) * lsSize);
	keysarr->keysSize = 0;
	
	int arr[hikey - lowkey] = {0};
	for(int i = 0; i< lsSize; i++)
	{
		arr[Ls[i]]++;
	
	}
	int j = 0;
	for(int i = 0; i < hikey - lowkey; i++)
	{
		if(arr[i] != 0)
		{
			(keysarr->Keys)[j] = i;
			(keysarr->keysSize)++;
			j++;
		}
	}
	
	return keysarr;

}

int part2Loc(int* Ls, int lo, int hi, int piv)
{
	int size = hi - lo + 1;
	int p = lo;
	int q = hi;
	
	while(1)
	{
		while(Ls[p] <= pivot p <= q)
			p++;
		while(Ls[q] > pivot && p<=q)
			q--;
				
		swap(&Ls[p], &Ls[q]);
	}

}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey)
{
	KeyStruct k = extractKeys(Ls, size, koKey, hiKey);
	int lo = 0;
	int hi = size - 1;
	int idx = partition(Ls, lo, hi, k->Keys[0]);
	for(int i = 0; i < k->keysSize; i++)
	{
		hi = idx - 1;
		lo = idx + 1;
		partition
	}	

}
void swap(int * a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}
