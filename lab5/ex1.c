#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
static int* p1;
static int* p2;
typedef struct bank
{
	long long int card_num;
	char bank_code[10];
	int mon;
	int year;
	char first[20];
	char last[20];

}bank;
void insertion_sort(bank arr[], int size);
void swap(bank* a, bank* b);
void insertInOrder(bank* arr, int num, bank b);
int mem = 20;
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
	readRecords(f1, &mem);
	fclose(f1);
	
	FILE* fp2 = fopen("unsorted.txt", "w");
	FILE* fp1 = fopen("sorted.txt", "w");
	for(int j = 0; j < i; j++)
		fprintf(fp2, "%llu\n", arr[j].card_num);
	insertion_sort(arr, i);
	for(int j = 0; j < i; j++)
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
