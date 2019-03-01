#include<stdio.h>
#include<stdlib.h>

#include "merge.h"
int count = 0;
student* merge_sort(student ls[], int low, int high)
{

//	int left = 0............sz/2;
//	int right = sz/2 + 1 ....... sz
	student* ls_new = (student *)malloc(sizeof(student) * (high - low + 1));
	
	if(high == low)
	{
		ls_new[0] = ls[low];
		count++;
		printf("name: %s, number: %lf %d\n", ls_new[0].name, ls_new[0].number, count);
		return ls_new;
	}
	student* ls1 = merge_sort(ls, low, (low + high)/2);
	student* ls2 = merge_sort(ls, ((low + high)/2) + 1, high);
	
	merge(ls1, ((high - low + 1)/2), ls2, ((high-low + 1)/2), ls_new);
	for(int i = 0; i < high - low + 1; i++)
	{
				printf("name: %s, number: %lf\n", ls_new[i].name, ls_new[i].number);
		ls[i + low] = ls_new[i];
	
	} 
	return ls_new;


}
