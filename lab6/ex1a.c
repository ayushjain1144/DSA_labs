#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "merge.h"



int main(int argc, int argv[])
{
	if(argc != 2)
	{
		printf("inappropriate arguments\n");
		exit(1);
	}
	
	FILE* fp = fopen("1024.txt", "r");
	
	if(fp == NULL)
	{
		printf("Error in opening file\n");
		exit(2);
	}
	student s;
	student arr[1024];
	int i = 0;
	while(fscanf(fp, "%[^,],%lf\n", s.name, &s.number) != EOF)
	{
		//printf("name: %s, num: %lf\n", s.name, s.number);
	
		arr[i] = s;	
		i++;			
	
	}
	
	student* arr_new = merge_sort(arr, 0, 1023);
	
	
	
	FILE* fout = fopen("out2.txt", "w");
	for(int i = 0; i < 1023; i++)
	{
		fprintf(fout, "name: %s, num: %lf\n", arr[i].name, arr[i].number);
	}
	fclose(fp);
	fclose(fout);
}




