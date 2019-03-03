#include<stdio.h>
#include "stack.h"
void swap(int* a, int* b);
int partition(int arr[], int p, int q);
void quicksort(int A[], int p, int q);

int main(void)
{
	int arr[7] = {7, 6, 5, 4, 3, 2, 1};
	quicksort(arr, 0, 6);
	
	for(int i = 0; i < 7; i++)
		printf("%d ", arr[i]);

}

int partition(int arr[], int p, int q)
{
	int pivot = arr[q];
	int i = p;
	int j = q - 1;
	
	while(i <= j)
	{
		if(arr[i] <= pivot)
			i++;
		
		
		else if(arr[j] > pivot)
			j--;
			
		else
			swap(&arr[i], &arr[j]);
		
		
	
	}
	
	swap(&arr[i], &arr[q]);
	
	return i;
}


void quicksort(int A[], int p, int q)
{
	stack* s = createStack();
	push(s, p);
	push(s, q);
	
	while(!isEmpty(s))
	{	
		int right = pop(s);
		int left = pop(s);
		int index = partition(A, left, right);
		
		
		if(left < index - 1)
		{
			push(s, left);
		
			push(s, index - 1);
		}
		if(right > index + 1)
		{	
			push(s, index + 1);
			push(s, right);
		}
	}
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

} 

