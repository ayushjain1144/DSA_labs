#include<stdio.h>
#include<stdlib.h>

#include "merge.h"

student* merge_sort(student ls[], int low, int high)
{
	
	int sz = high - low + 1;
	int key = 1;

	while(key != sz)
	{
		int num = sz/key;
		student arr[2 * key];
		student ls1[key];
		student ls2[key];
		for(int i = 0; i < num; i+=2)
		{
			for(int n = i * key, j = 0; j < key ; j++)
			{
				ls1[j] = ls[n + j];
			}
			for(int n = (i + 1) * key, j = 0; j < key ; j++)
			{
				ls2[j] = ls[n + j];
			}
			merge(ls1, key, ls2, key, arr);
			for(int k = 0; k < 2 * key; k++)
			{
				ls[i * key + k] = arr[k];
			}
		
		}
		
		key *= 2;
	
	
	}

	return ls;
}

