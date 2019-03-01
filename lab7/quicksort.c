#include<stdio.h>

void swap(int* a, int* b);
int partition(int arr[], int p, int q);
void quicksort(int A[], int p, int q);

int main(void)
{
	int arr[7] = {-1, 9, 1, 7, 11, 5, 18};
	quicksort(arr, 0, 6);
	
	for(int i = 0; i < 7; i++)
		printf("%d ", arr[i]);

}


void quicksort(int A[], int p, int q)
{
	if(p < q)
	{
		int index = partition(A, p, q);
		quicksort(A, p, index - 1);
		quicksort(A, index + 1, q);
	}
	
	return;
}

// assuming pivot to be the last element
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

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

} 
