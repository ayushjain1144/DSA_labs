#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
typedef struct bank
{
	long long int card_num;
	char* bank_code;
	int mon;
	int year;
	char* first;
	char* last;

}bank;

void swap(bank* a, bank* b);
void insertInOrder(bank* arr, int num, bank b);
int mem = 20;
int main(int argc, char* argv[])
{	
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
	
	bank* arr;
	arr = (bank*)malloc(20 * sizeof(bank));
	
	int i = 0;
	struct timeval t1, t2;
	double elapsedTime;
	
	gettimeofday(&t1,NULL);
	
	while(fgetc(f1) != EOF)
	{	
		
		if( i >= mem)
		{
			arr = (bank*)realloc(arr, mem * 2 * sizeof(bank));
			mem = mem*2;
		}	
		bank b;
		b.card_num = 0;
		b.bank_code = (char*) malloc(sizeof(10));
		b.first = (char*) malloc(sizeof(20));
		b.last = (char*) malloc(sizeof(20));
		b.mon = 0;
		b.year = 0;

		insertInOrder(arr, i, b);
		i++;
		 	
	}
	fclose(f1);
	for(int j = 0; j < i; j++)
		printf("%llu\n", arr[j].card_num);
	gettimeofday(&t2, NULL);
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time is %lfms\n", elapsedTime);
	FILE* fp = fopen("out_with_insert.txt", "a");
	if(fp == NULL)
	{
		printf("Not opening\n");
		return 3;
	
	}
	fprintf(fp, "%s: %lf\n", argv[1], elapsedTime);
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
