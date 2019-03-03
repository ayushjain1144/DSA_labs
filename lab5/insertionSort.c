#include<stdio.h>
#include "bank.h"

void insertInOrder(bank* arr, int num, bank b)
{
	arr[num] = b;

	for(int i = 0; i < num; i++)
	{
		if(arr[i].card_num > b.card_num)
		{
			swap(&arr[i], &arr[num]);
		}
	
	}
	
}

void swap(bank* a, bank* b)
{  
	bank temp = *a;
	*a = *b;
	*b = temp;
	
	
}
void insertion_sort(bank arr[], int size)
{
	int a;
	p1 = &a;
	if(size > 1)
	{
		insertion_sort(arr, size-1);
		insertInOrder(arr, size - 1 , arr[size-1]);
	}
	int b;
	p2 = &b;
	

}


