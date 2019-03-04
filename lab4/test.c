#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char* arr; 
	
	arr = (char*)malloc(sizeof(10));
	printf("%ld %ld %ld\n", sizeof(arr), sizeof(*arr), sizeof(&arr));
	

}
