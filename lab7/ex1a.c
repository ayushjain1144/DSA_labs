#include<stdio.h>
#include "stack.h"
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>

typedef struct emp
{
	char name[10];
	int empID;

}emp;

void swap(emp* a, emp* b);
int partition(emp arr[], int p, int q);
void quicksort(emp A[], int p, int q, int S);
void insertion_sort(emp arr[], int size);
int estimateCutoff(emp arr[], int size);
void sort(emp arr[], int p, int q, int S);
double * testRun(emp arr[], int size);

int main(int argc,  char* argv[])
{
	if(argc != 3)
	{
		printf("Invalid argumnets\n");
		exit(1);
	}
	
	FILE* fp = fopen(argv[1], "r");
	FILE* fp1 = fopen(argv[2], "w");
	if(fp == NULL || fp1 == NULL)
	{
		printf("Error in opening file\n");
		exit(2);
	}
	int s;
	int power = 0; 
	printf("Enter power: ");
	scanf("%d", &power);
	emp emp1;
	int num = (int)pow(10.0, power);
	emp arr[num];
	
	
	for(int i = 0; i < num; i++)
	{
		fscanf(fp, "%s%d\n", emp1.name, &emp1.empID);
		arr[i] = emp1;
		
	
	}
	fclose(fp);
	int cutoff = estimateCutoff(arr, num);
	//quicksort(arr, 0, 9, s);
	//insertion_sort(arr, 10);
	
	FILE* frec = fopen("record.txt", "a");
	
	
	struct timeval t1, t2;
	double elapsedTime;
	
	gettimeofday(&t1, NULL);
	
	sort(arr, 0, num - 1, cutoff);
	
	gettimeofday(&t2, NULL);
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	
	fprintf(frec, "%d: %lf\n", num, elapsedTime);
	
	fclose(frec);
	for(int j = 0; j < num; j++)
	{
		printf("%d\n", arr[j].empID);
		fprintf(fp1, "%s %d\n", arr[j].name, arr[j].empID);
	}
	fclose(fp1);
	
	

}
void sort(emp arr[], int p, int q, int S)
{
	int size = q - p + 1;
	quicksort(arr, p, q, S);
	insertion_sort(arr, size);
}
int partition(emp arr[], int p, int q)
{
	int pivot = arr[q].empID;
	int i = p;
	int j = q - 1;
	
	while(i <= j)
	{
		if(arr[i].empID <= pivot)
			i++;
		
		
		else if(arr[j].empID > pivot)
			j--;
			
		else
			swap(&arr[i], &arr[j]);
		
		
	
	}
	
	swap(&arr[i], &arr[q]);
	
	return i;
}


void quicksort(emp A[], int p, int q, int S)
{
	stack* s = createStack();
	push(s, p);
	push(s, q);
	
	while(!isEmpty(s))
	{	
		int right = pop(s);
		int left = pop(s);
		int index = partition(A, left, right);
		
		int size_left = index - left;
		int size_right = right - index;
		if(left < index - 1 && size_left > S)
		{
			push(s, left);
		
			push(s, index - 1);
		}
		if(right > index + 1 && size_right > S)
		{	
			push(s, index + 1);
			push(s, right);
		}
	}
}

void insertion_sort(emp arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = i; j >= 1; j--)
		{ 
			if(arr[j-1].empID > arr[j].empID)
			{
				swap(&arr[j], &arr[j-1]);
			}
			else
				break;	
		}		
	}
}
void swap(emp* a, emp* b)
{
	emp temp = *a;
	*a = *b;
	*b = temp;

}

double * testRun(emp arr[], int size)
{
	struct timeval t1, t2, t3;
	double elapsedTime;
	
	double* measurements = (double*)malloc(sizeof(double)* 2);
	emp arr1[size];
	emp arr2[size];
	
	for(int i = 0; i < size; i++)
	{
		arr1[i] = arr[i];
		arr2[i] = arr[i];
	}
	gettimeofday(&t1, NULL);
	quicksort(arr1, 0, size - 1, 0);
	gettimeofday(&t2, NULL);
	insertion_sort(arr2, size);
	gettimeofday(&t3, NULL);
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime+= (t2.tv_usec - t1.tv_usec) / 1000.0;
	measurements[0] = elapsedTime;
	elapsedTime = (t3.tv_sec - t2.tv_sec) * 1000.0;
	elapsedTime+= (t3.tv_usec - t2.tv_usec) / 1000.0;
	measurements[1] = elapsedTime;
	
	return measurements;

}

int estimateCutoff(emp arr[], int size)
{
	double * max;
	
	
	
	int mid = size;
	
	while(max[0] - max[1] > 0.001)
	{
		mid = mid/2;
		max = testRun(arr, mid);
		
	
	
	}
	return mid;

}




