#ifndef _BANK
#define _BANK

int* p1, * p2;


typedef struct bank
{
	long long int card_num;
	char bank_code[10];
	int mon;
	int year;
	char first[20];
	char last[20];

}bank;

void insertion_sort(bank arr[], int size);
void swap(bank* a, bank* b);
void insertInOrder(bank* arr, int num, bank b);

bank* readRecords(FILE* f1, int* mem);

#endif
