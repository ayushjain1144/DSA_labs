#include <stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(int argc, char* argv[])
{ 
	FILE* fileptr = fopen(argv[1], "r");
	
	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
	head->first = NULL;
	head->count = 0;
	
	int temp;	
	while(fscanf(fileptr, "%d", &temp) != EOF)
	{
		
		insertFirst(head, temp);
		
	}
	
	fclose(fileptr);
	
	
	
	printList(head);
	
	deleteFirst(head);
	printList(head);
	
	//for search operation
	
	int flag = 0;
	
	do{
	
	printf("Enter the element to search, to stop enter -190: ");
	scanf("%d", &flag);
	int search_result = search(head, flag);
	printf("%d\n", search_result);

	}while(flag != -190);
	
	
	int flag_del = 0;
	
	do{
	
	printf("Enter the element to delete, to stop enter -190: ");
	scanf("%d", &flag_del);
	delete(head, flag_del);
	
	printList(head);
	
	}while(flag_del != -190);
	
	
	
	FILE* fileoutptr = fopen("out.txt", "w");
	
	struct node* link = head->first;
	
	while(link != NULL)
	{
		fprintf(fileoutptr, "%d\n", link->element);
		link = link->next;
	
	}
	
	fclose(fileoutptr);


}
