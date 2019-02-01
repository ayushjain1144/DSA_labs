#ifndef LIST_H
#define LIST_H

typedef struct{
	
	int arr[3];
}node;

typedef struct{
	int head;

}list;

list create_list();

void insert(list l, int key);

void delete(list l, int n);

int count(list l);

void display();

void display_free();

void defragment();

list initialize_free_list();


#endif
