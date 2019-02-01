#include <stdio.h>
#include "list.h"

int main(void)
{
	initialize_free_list();	
	int n = -1;
	do
	{
		printf("Select an option: ");
		scanf("%d", &n);
		
		switch(n)
		{
			case(0):
				printf("Exitting............\n");
				break;
			case(1):
				list = create_list();
				printf("The sequence number of the newly created list is: %d", num_list);
				printf("Enter key value to be inserted in the newly creadted list-%d: ",num_list);
				int num;
				scanf("%d", &num);	
				insert(list, num);
				printf("SUCCESS\n");
				break;
			
			default:
				printf("Invalid command, please try again!!\n");
						
	
	}while(n != 0)


}
