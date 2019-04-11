#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "hash.h"
#include "chain.h"
#include<string.h>

int main(void)
{
	srand(time(0));
	char** arr = parser("aliceinwonderland.txt");
	profiling(arr);
	Table* t1 = createTable();
	insertall(t1, arr);
	//printf("%d\n", arr[73]);
	printTable(t1, arr);
	
	char* brr[4];
	
	for(int i = 0; i < 4; i++)
	{
		brr[i] = (char*)malloc(sizeof(char) * 20);
	}
	
	strcpy(brr[0], "is");
	strcpy(brr[1], "was");
	strcpy(brr[2], "hmdwb");
	printf("hash: %d\n", hash(brr[2], 8531, 5000));
	strcpy(brr[3], "wonderland");
	
	lookupall(t1, brr, 1, 4, arr);
	
	/*
	char** del_arr = parser("stopwords.txt");
	
	printf("%s\n", del_arr[428]);
	
	delete_from_hash(del_arr, t1, arr, 429);
	printTable(t1, arr);
	*/
	char** del_arr = stop_parser();
	delete_from_hash(del_arr, t1, arr, 429);
	printTable(t1, arr);
	
	
	

}
