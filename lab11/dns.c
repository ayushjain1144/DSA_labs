#include<stdio.h>
#include<stdlib.h>
#include "dnstree.h"

int main(void)
{

	Tree* t1 = createTree();
	while(1){
	int choice;
	int num;
	scanf("%d", &choice);
	
	
	
	if(choice == 1)
	{
		scanf("%d\n", &num);
		readdata(t1, num);
		printtree(t1->head->child);
		printf("\n");
	} 
	
	else if(choice == 2)
	{
		char* s = (char*)malloc(sizeof(char) * 100);
			scanf("%s", s);
			lookup(t1, s);
	}
	
	else
	{
		return 0;
	
	}
}
}
