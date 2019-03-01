#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>

#include "merge.h"

void merge(student ls1[], int sz1, student ls2[], int sz2, student ls[])
{
	
	int i = 0;
	int j = 0;
	int k = 0;
	printf("Inside merge\n");
	while(i != sz1 && j != sz2)
	{
		if(ls1[i].number <= ls2[j].number)
		{
			ls[k] = ls1[i];
			i++;
			k++;
		}
		
		else
		{
			ls[k] = ls2[j];
			j++;
			k++;
		}
	}
	
	
	if(i == sz1 && j != sz2)
	{
		while(j != sz2)
		{
			ls[k] = ls2[j];
			j++;
			k++;
		}
		
	
	}
	
	if(i != sz1 && j == sz2)
	{
		while(i != sz1)
		{
		ls[k] = ls1[i];
		i++;
		k++;
		
		}
	
	}
	

}


