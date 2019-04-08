#include<stdio.h>
#include<stdlib.h>

int hash(char* arr, int base, int t_size);
int collision_count(char* arr[], int num, int base, int t_size);
char** parser(char* f_name);
int g_size = 0;
int main(void)
{
	parser("aliceinwonderland.txt");

}

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
	
	

	while(fscanf(fp, "%*[^a-zA-z]%[^ \n\t]", arr[g_size]) == 1)
	{
		g_size++;
		printf("%s %d\n", arr[g_size-1], g_size);
		if(g_size == capacity)
		{
			arr = (char**)realloc(arr, 2 * capacity);
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
