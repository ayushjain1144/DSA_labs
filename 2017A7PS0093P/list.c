#include<stdio.h>
#include<stdlib.h>
#include "list.h"

/*This value which signifies our memory size, can be changed*/
#define MEM 51

/* Can't use '/' as NULL value as it can cause conflict because of its ascii value, means we can't decide whether it is memory location 47(ascii of '/') or NULL. */
#define NIL -1

list free_list;
list arr_of_list[5];
int arr[MEM];
int num_list = 0;
//only used at the start of our program to enter the whole array to free_list
void initialize_free_list()
{
	free_list.head = NIL;	
	for(int i = 0; i < MEM; i+=3)
	{
		push(i);
	
	}


}

//takes address of node to push
void push(int address)
{
	arr[address + 1] = free_list.head;
	free_list.head = address; 
}

//takes address of node to pop
int pop()
{
	if(free_list.head == NIL)
	{
		printf("FAILED! No more memory\n");
		return NIL;
	}
	
	int address_to_del = free_list.head;
	int address_now_last = arr[address_to_del +1];
	free_list.head = address_now_last;
	return address_to_del;

}

list create_list()
{
	list l;
	l.head = NIL;
	num_list++;
	return l;
	

}

//insertion in ascending order
list insert(list l, int key)
{
	int addr = pop();
	if(addr == NIL)
		return l;
	arr[addr] = key;
	int temp_addr = l.head;
	
	//if list is initially empty
	if(temp_addr == NIL)
	{
		arr[addr + 1] = NIL;
		arr[addr + 2] = NIL;
		l.head = addr;
		printf("SUCCESS\n");
		return l;
	
	}
	
	//if the data needs to be inserted at the start
	if(arr[temp_addr] >= key)
	{
		arr[addr + 1] = temp_addr;
		arr[addr + 2] = NIL;
		l.head = addr;
		printf("SUCCESS\n");
		return l;
	}
	
	
	while(arr[temp_addr + 1] != NIL)
	{
		temp_addr = arr[temp_addr + 1];
		int data = arr[temp_addr];
		if(data >= key)
		{
			int prev_addr = arr[temp_addr + 2];
			int next_of_prev_addr = prev_addr + 1;
			arr[next_of_prev_addr] = addr;
			arr[addr + 2] = prev_addr;
			arr[addr + 1] = temp_addr;
			arr[temp_addr + 2] = addr;
			printf("SUCCESS\n");
			return l;
		}
		
	}
	
	//This means the data needs to be inserted at the last
	arr[addr + 2] = temp_addr;
	arr[addr + 1] = NIL;
	arr[temp_addr + 1] = addr;
	printf("SUCCESS\n");
	return l; 

}

list delete(list l, int key)
{
	int temp_addr = l.head;
	
	//if list is empty
	if(temp_addr == NIL)
	{
		printf("FAILURE: List Empty!!\n");
		return l;
	}
	
	//if the key is to be deleted from head
	if(arr[temp_addr] == key)
	{
		int addr_of_next = arr[temp_addr + 1];
		l.head = addr_of_next;
		
		if(addr_of_next == NIL)
		{
			push(temp_addr);
			printf("SUCCESS\n");
			return l;
		}	
		arr[addr_of_next + 2] = NIL;
		push(temp_addr);
		printf("SUCCESS\n");
		return l;
	
	}
	
	
	while(arr[temp_addr + 1] != NIL)
	{
		temp_addr = arr[temp_addr + 1];
		int data = arr[temp_addr];
		if(data == key)
		{
			int prev_addr = arr[temp_addr + 2];
			int next_of_prev_addr = prev_addr + 1;
			int next_addr = arr[temp_addr + 1];
			if(next_addr == NIL)
			{
				arr[next_of_prev_addr] = NIL;
				push(temp_addr);
				printf("SUCCESS\n");
				return l;
			}
			arr[next_of_prev_addr] = next_addr;
			arr[next_addr + 2] = prev_addr;
			push(temp_addr);
			printf("SUCCESS\n");
			return l;
		}
		
	}
	
	//This means there was no node with the provided key
	
	printf("FAILURE: ELEMENT NOT THERE\n");
	return l;
}


int count_list(list l)
{
	int temp_addr = l.head;
	int count = 0;
	while(temp_addr != NIL)
	{
		count++;
		temp_addr = arr[temp_addr + 1];
	
	}
	return count;

}

int count_total(list arr_of_list[])
{
	int count = 0;
	for(int i = 0; i < num_list; i++)
	{
		count += count_list(arr_of_list[i]);	
	}
	
	return count;

}

void display_list(list l)
{
	int temp_addr = l.head;
	printf("key\tnext\tprev\n");
	while(temp_addr != NIL)
	{
		printf("%d\t%d\t%d\n", arr[temp_addr], arr[temp_addr + 1], arr[temp_addr + 2]);
		temp_addr = arr[temp_addr + 1];
	}

}

void display(list arr_of_list[])
{	
	if(num_list == 0)
	{
		printf("Presently there are no lists\n");
		return;
	}
	for(int i = 0; i < num_list; i++)
	{
		printf("Elements of list-%d are:\n", i+1);
		display_list(arr_of_list[i]);
		printf("\n\n");	
	}

}


void display_free()
{
	int temp_addr = free_list.head;
	if(temp_addr == NIL)
	{
		printf("[]\n");
		return;
	}	
	printf("[");
	while(arr[temp_addr + 1] != NIL)
	{
		printf("%d, ",temp_addr);
		temp_addr = arr[temp_addr + 1];
	}
	printf("%d]\n", temp_addr);
}

int isAdjacent(int target, int potential)
{
	if((potential - target) == 3)
		return 1;
	else
		return 0;	

}


void swap_free_list(int free_addr, int list_addr)
{	
	
	int prev_of_list = arr[list_addr + 2];
	int key = arr[list_addr];
	int next_of_list = arr[list_addr + 1];
	int next_of_free = arr[free_addr + 1];
	int prev_free = find_prev_free(free_addr);
	arr[free_addr + 1] = next_of_list;
	arr[free_addr + 2] = prev_of_list;
	arr[list_addr + 1] = next_of_free;
	arr[free_addr] = key;
	if(prev_of_list != NIL)
	{
		int next_of_prev = prev_of_list + 1;
		arr[next_of_prev] = free_addr;
	
	}
	else
	{
		//find whose list head it is and point it to new head
		for(int i = 0; i < num_list; i++)
		{
			if(arr_of_list[i].head == list_addr)
			{
				arr_of_list[i].head = free_addr;
				break;
			}
		}
	}
	
	if(next_of_list != NIL)
	{
		int prev_of_next_list = next_of_list + 2;
		arr[prev_of_next_list] = free_addr;
	}
	

	
	if(prev_free != NIL)
	{
		arr[prev_free + 1] = list_addr;
		 
	}
	else
	{
		free_list.head = list_addr;
	
	}
	
	
	return;

}
void defragment()
{
	int count = count_list(free_list);
	int temp_addr = free_list.head;
	
	// if there is only one free location or no free location
	if(arr[temp_addr + 1] == NIL || temp_addr == NIL)
		return;
		
	int arr_free_addr[count];
	for(int i = 0; i < count; i++)
	{
		arr_free_addr[i] = temp_addr;
		temp_addr = arr[temp_addr + 1];
	
	}
	
	insertion_sort(arr_free_addr, count);
	
	int end = arr_free_addr[0];
	
	for(int i = 1; i < count; i++)
	{
		//if it is neighbour of our free block, then no need to do anything
		
		if(isAdjacent(end, arr_free_addr[i]) == 1)
		{
			end = arr_free_addr[i];
		}
		//if not adjacent
		
		else
		{
			swap_free_list(arr_free_addr[i], end + 3);
			end += 3;
		
		}
	
	}
		

	


}

void insertion_sort(int arr[], int len)
{
	for(int i = 0; i < len; i++)
	{
		
		
		for(int j = i; j > 0; j--)
		{
			if(arr[j] < arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				
			}	
			else
				break;		
		
		}
	}	
	
}



int find_prev_free(int addr)
{
	int temp_addr = free_list.head;
	
	if(temp_addr == addr)
		return NIL;

	while(arr[temp_addr + 1] != NIL)
	{
		if(addr == arr[temp_addr + 1])
			return temp_addr;
			
		temp_addr = arr[temp_addr + 1];	 
	
	}
}





