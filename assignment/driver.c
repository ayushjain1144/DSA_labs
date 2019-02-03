#include <stdio.h>
#include "list.h"


int main(void)
{
	initialize_free_list();
	int option = -1;
	do
	{
		printf("\n\nSelect an option: ");
		printf("\n1. Create a new list\n");
		printf("2. Insert a new element in a given list in sorted order\n");
		printf("3. Delete an element from a given list\n");
		printf("4. Count total elements excluding free list\n");
		printf("5. Count total elements of a list\n");
		printf("6. Display all lists\n");
		printf("7. Display free list\n");
		printf("8. Perform defragmentation\n");
		printf("9. Press 0 to exit\n\n\n");
		
		scanf("%d", &option);
		
		switch(option)
		{
			case(0):
				printf("Exitting............\n");
				break;
				
			case(1):
			{
				if(num_list + 1 > 5)
				{
					printf("FAILED! Maximum 5 lists can be made!\n");
					break;
				
				}
				list l = create_list();
				arr_of_list[num_list - 1] = l;
				
				printf("The sequence number of the newly created list is: %d\n", num_list);
				printf("Enter key value to be inserted in the newly creadted list-%d: ",num_list);
				int num;
				scanf("%d", &num);	
				arr_of_list[num_list - 1] = insert(l, num);
				
				break;
			}
			
			case(2):
			{
				printf("List you want to enter in: ");
				
				int n;
				int key;
				scanf("%d", &n);
				
				if(n <= 0 || n > num_list)
				{
					printf("No such list created!!\n");
					break;
				
				}
				
				printf("Enter the key value: ");
				scanf("%d", &key);
				list l = arr_of_list[n - 1];
				arr_of_list[n - 1] = insert(l, key);
				
				break;			
		
			}
			
			case(3):
			{
				printf("List you want to delete from: ");
				int n;
				int key;
				scanf("%d", &n);
				
				if(n <= 0 || n > num_list)
				{
					printf("No such list created!!\n");
					break;
				
				}
				
				printf("Enter the key value: ");
				scanf("%d", &key);
				list l = arr_of_list[n - 1];
				arr_of_list[n - 1] = delete(l, key);
				
				break;
	
			}
			
			case(4):
			{
				int count = count_total(arr_of_list);
				printf("Total number of nodes in all lists are %d.\n", count);
				break;
			}
			case(5):
			{
				printf("Enter the list number: ");
				int n;
				scanf("%d", &n);
				if(n <= 0 || n > num_list)
				{
					printf("No such list created!!\n");
					break;
				
				}
				list l = arr_of_list[n - 1];
				int count = count_list(l);
				
				printf("Total number of nodes in list %d are %d\n", n, count);
				break;
			
			}
			case(6):
			{
				display(arr_of_list);
				break;
			}
			
			case(7):
			{
				display_free();
				break;
			
			}
			
			case(8):
			{
				defragment();
				printf("SUCCESS\n");
				break;
			}
			
			default:
				printf("Invalid command, please try again!!\n");
			}			
	
	}while(option != 0);


}
