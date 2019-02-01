#include<stdio.h>
#include<stdlib.h>
#include "list.h"

/*This value which signifies our memory size, can be changed*/
#define MEM 27

/* Can't use '/' as NULL value as it can cause conflict because of its ascii value, means we can't decide whether it is memory location 47(ascii of '/') or NULL. */
#define NIL -1

list free_list;
int arr[MEM];
int num_list = 0;

//only used at the start of our program to enter the whole array to free_list
void initialize_free_list()
{	
	for(int i = 0; i < mem; i+=3)
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
		exit(1);
	}
	
	int address_to_del = free_list.head;
	int address_now_last = arr[adress_to_del +1];
	arr[address_now_last + 1] = NIL;
	free_list.head = address_now_last;
	return adress_to_del;

}

list create_list()
{
	list l;
	l.head = NIL;
	num_list++;
	return list;

}

//insertion in ascending order
void insert(list l, int key)
{
	int addr = pop();
	arr[addr] = key;
	int temp_addr = list.head;
	
	//if list is initially empty
	if(temp_addr == NIL)
	{
		arr[addr + 1] = NIL;
		arr[addr + 2] = NIL;
		list.head = addr;
		return;
	
	}
	
	//if the data needs to be inserted at the start
	if(arr[temp_addr] >= key)
	{
		arr[addr + 1] = temp_addr;
		arr[addr + 2] = NIL;
		list.head = addr;
		return;
	}
	
	temp_addr = arr[temp_addr + 1];
	
	while(arr[temp_addr + 1] != NIL)
	{
		temp_addr = arr[temp_addr + 1];
		int data = arr[temp_addr];
		if(data >= key)
		{
			int prev_addr = arr[temp_addr + 2];
			int next_of_prev_addr = arr[prev_addr];
			arr[next_of_prev_addr] = addr;
			arr[addr + 2] = prev_addr;
			arr[addr + 1] = temp_addr;
			arr[temp_addr + 2] = addr;
			return;
		}
		
	}
	
	//This means the data needs to be inserted at the last
	arr[addr + 2] = temp_addr;
	arr[addr + 1] = NIL;
	arr[temp_addr + 1] = addr;
	
	return;

}
/*
void delete(list l, int n);

int count(list l);

void display();

void display_free();

void defragment();
*/



