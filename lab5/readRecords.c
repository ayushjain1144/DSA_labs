#include<stdio.h>
#include<stdlib.h>
#include "bank.h"

bank* readRecords(FILE* f1, int* mem)
{
	bank* arr;
	arr = (bank*)malloc(*mem * sizeof(bank));
	
	int i = 0;
	bank b;
		
	
	while(fscanf(f1, "%*c%llu,%[^,],%d/%d,%[^,],%[^\"]%*c\n",&b.card_num,b.bank_code,&b.mon,&b.year,b.first,b.last) != EOF)
	{	
		
		
		if( i >= *mem)
		{
			arr = (bank*)realloc(arr, *mem * 2 * sizeof(bank));
			*mem = *mem*2;
		}	
		
		arr[i] = b;
		//insertInOrder(arr, i, b);
		i++;
		*mem = i;
		 	
	}
	
	return arr;
	
	

}
