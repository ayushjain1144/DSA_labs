#ifndef __CHAIN
#define __CHAIN

typedef struct node
{
	int index;
	int count;
	struct node* next;

}Node;

typedef struct linkedlist
{
	Node* head;
	
}Linkedlist;

typedef struct table
{
	Linkedlist arr[5000];
	int elementCount;
	int insertionCost;
	int queryingCost;
	
}Table;

Table* createTable(void);
int insertion(Table* t1, char** arr, int j);

int insertall(Table* t1, char* arr[]);
int lookup(Table* t1, char* str, char* arr[]);
int lookupall(Table* t1, char* arr[], int m, int num_elem, char** book);
void printlist(Linkedlist l, char** arr);
void printTable(Table* t1, char** arr);
void delete_from_hash(char** arr_del, Table* t1, char** book, int num_del);

void delete_from_hash(char** arr_del, Table* t1, char** book, int num_del);

#endif
