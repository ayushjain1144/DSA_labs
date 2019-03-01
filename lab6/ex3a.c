#include<stdio.h>
#include<stdlib.h>
#include "merge.h"

void partial_sort(FILE* fptr, int k);
void mergesort(FILE* big, int k);
void mergefile(FILE* f1, FILE* f2);
int temp = 0;

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("wrong arguments\n");
		exit(0);
	
	}
	FILE* fptr = fopen(argv[1], "r");
	
	if(fptr == NULL)
	{
		printf("Error in openeing file\n");
		exit(1);
	}
	
	
	
	mergesort(fptr, 1024);
	
	
	
	fclose(fptr);


}

void partial_sort(FILE* fptr, int k)
{
	//k = 100
	student arr[k];
	student s;
	int i = 0;
	int count = 1;
	char filename[15];
	while(fscanf(fptr, "%[^,],%lf\n", s.name, &s.number) != EOF)
	{
		//printf("name: %s, num: %lf\n", s.name, s.number);
	
		arr[i] = s;	
		i++;
		if(i == k)
		{
			student* arr_new = merge_sort(arr, 0, k-1);
			sprintf(filename, "sortout%d.txt", count);
			FILE* fout = fopen(filename, "w");
			for(int j = 0; j < k; j++)
			{
				fprintf(fout, "%s,%lf\n", arr[j].name, arr[j].number);
				
			}
			i = 0;
			count++;
			fclose(fout);
		}			
	}
	

}

void mergefile(FILE* f1, FILE* f2)
{
	student s1, s2;
	temp = temp+1;
	char filename[15];
	sprintf(filename, "output%d.txt", temp);
	FILE* fout = fopen(filename, "w");
	int flag = 0;
	int count1 = 0;
	int count2 = 0;
	if(fscanf(f1, "%[^,],%lf\n", s1.name, &s1.number) == EOF)
	{
		flag = 1;
		
	}
	if(fscanf(f2, "%[^,],%lf\n", s2.name, &s2.number) == EOF)
	{
		flag = 2;
		
	}
	while(1)
	{
	
		
		if(s1.number <= s2.number)
		{
			fprintf(fout, "%s,%lf\n", s1.name, s1.number);
			count1++;
			if(fscanf(f1, "%[^,],%lf\n", s1.name, &s1.number) == EOF)
			{
				flag = 1;
				break;
			}
		}
		
		else
		{
			fprintf(fout, "%s,%lf\n", s2.name, s2.number);
			count2++;
			if(fscanf(f2, "%[^,],%lf\n", s2.name, &s2.number) == EOF)
			{
				flag = 2;
				break;
			}
		
		}
	}
	
	if(flag == 1)
	{
		fprintf(fout, "%s,%lf\n", s2.name, s2.number);
		count2++;
		while(fscanf(f2, "%[^,],%lf\n", s2.name, &s2.number) != EOF)
		{
			fprintf(fout, "%s,%lf\n", s2.name, s2.number);
			count2++;
		}
	
	}
	else
	{
		fprintf(fout, "%s,%lf\n", s1.name, s1.number);
		count1++;
		while(fscanf(f1, "%[^,],%lf\n", s1.name, &s1.number) != EOF)
		{
			fprintf(fout, "%s,%lf\n", s1.name, s1.number);
			count1++;
		}
	
	}
	
	printf("count 1: %d, count2: %d\n", count1, count2);
	fclose(fout);
	
	

}

void mergesort(FILE* big, int k)
{	

	FILE* fout = fopen("mergeout.txt", "w");
	partial_sort(big, k);
	
	int count  = 3;
	char filename[15];
	char prevfile[15];
	for(int i = 0; i < 10240/k; i++)
	{	
		if(i == 0)
		{
			FILE* f1 = fopen("sortout1.txt", "r");
			FILE* f2 = fopen("sortout2.txt", "r");
			mergefile(f1,f2);
			i+=1;
			fclose(f1);
			fclose(f2);
			continue;
			
		}
		
		sprintf(filename, "sortout%d.txt", count);
		sprintf(prevfile, "output%d.txt", temp);
		FILE* f2 = fopen(filename, "r");
		FILE* f1 = fopen(prevfile, "r");
		mergefile(f1, f2);
		count++;
		fclose(f2);
		fclose(f1);
	}
	


}
