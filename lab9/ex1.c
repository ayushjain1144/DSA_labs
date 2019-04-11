#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<time.h>
#include "hash.h"

int g_size = 0;

int hash(char* arr, int base, int t_size)
{
	int sum = 0;

	while(*arr != '\0')
	{
		sum += *arr;
		arr++;
	}
	
	int h = (sum%base)%t_size;
	
	return h;
}

int collision_count(char* arr[], int num, int base, int t_size)
{
	int table[t_size];
	for(int i = 0; i < t_size; i++)
	{
		table[i] = -1;
	}
	
	int col = 0;
	
	for(int i = 0; i < num; i++)
	{
		int h = hash(arr[i], base, t_size);
		if(table[h] == -1)
		{
			table[h] = 1;
			
		
		}
		
		else
		
			col++;
	
	}
	
	return col;
}

char** parser(char* f_name)
{
	FILE* fp = fopen(f_name, "r");
	if(fp == NULL)
	{
		printf("error in opneing file\n");
		exit(1);
	}
	int capacity = 100;
	char** arr = (char**)malloc(sizeof(char*) * capacity);
	
	for(int i = 0; i < capacity; i++)
	{
		
		arr[i] = (char*)malloc(sizeof(char) * 50);
	
	}
	
	

	while(fscanf(fp, "%*[^a-zA-z]%[^ \n\t,.;-?)(:/'!]", arr[g_size]) == 1)
	{
		g_size++;
		//printf("%s %d\n", arr[g_size-1], g_size);
		if(g_size == capacity)
		{
			arr = (char**)realloc(arr, 2 * capacity * sizeof(char*));
			for(int i = capacity; i < capacity*2; i++)
			{
				arr[i] = (char*)malloc(sizeof(char) * 50);
	
			}
			capacity *= 2;
		}	
		
		
		
	}
	//printf("%c %c %c\n", fgetc(fp), fgetc(fp), fgetc(fp));
	
	return arr;

}

int isprime(int n)
{
	for(int i = 2; i < sqrt(n); i++)
	{
		if(n%i == 0)
			return 0;
	}
	
	return 1;

}

int prime_generator(int low, int high)
{
	
	int r;
	
	do
	{
		
		r = rand()%(high - low + 1) + low;
		
	}while(isprime(r) == 1);
	
	return r;

}

void profiling(char** arr)
{
	int t_size[] = {5000, 50000, 500000};
	int base[] = {prime_generator(5000, 10000), prime_generator(5000, 10000),
				prime_generator(5000, 10000), prime_generator(5000000, INT_MAX), prime_generator(5000000, INT_MAX), prime_generator(5000000, INT_MAX),  prime_generator(50000, 100000),
				prime_generator(50000, 100000), prime_generator(50000, 100000),
				prime_generator(50000000, INT_MAX), prime_generator(50000000, INT_MAX), prime_generator(50000000, INT_MAX),
				prime_generator(500000, 1000000), prime_generator(500000, 1000000), prime_generator(500000, 1000000),
				prime_generator(500000000, INT_MAX),
				prime_generator(500000000, INT_MAX),
				prime_generator(500000000, INT_MAX)};
				
	int count = g_size;
	int best_t = 0;
	int best_b = 0;
	
	for(int i = 0; i < 18; i++)
	{
		
		int temp = collision_count(arr, g_size, base[i], t_size[i/6]);
		printf("Count for base %d and table %d is: %d\n", base[i], t_size[i/6], temp);

		if(temp < count)
		{
			best_t = t_size[i/6];
			best_b = base[i];
		}
	}
	
	printf("The best parameters are - table: %d, base: %d\n", best_t, best_b);
	
	return;
}

char** stop_parser()
{
	FILE* f1 = fopen("stopwords.txt", "r");
	
	char** arr = (char**) malloc(sizeof(char*) * 429);
	for(int i = 0; i < 429; i++)
	{
		arr[i] = (char*) malloc(sizeof(char) * 20);
	
	}
	
	int i = 0;
	while(fscanf(f1, "%s", arr[i]) == 1)
	{
		
	
	}
	return arr;
}









