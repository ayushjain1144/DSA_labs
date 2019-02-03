#ifndef LIST_H
#define LIST_H

typedef struct{
	
	int arr[3];
}node;

typedef struct{
	int head;

}list;

extern int num_list;
extern list arr_of_list[5];
list create_list();

list insert(list l, int key);

list delete(list l, int key);

int count_list(list l);

int count_total(list arr_of_list[]);

void display(list arr_of_list[]);

void display_free();

void defragment();

void initialize_free_list();

void push(int address);

int pop();

void insertion_sort(int arr[], int len);

int find_prev_free(int addr);


#endif
