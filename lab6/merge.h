#ifndef __MERGE__
#define __MERGE__


typedef struct student{
	char name[20];
	double number;
}student;

void merge(student ls1[], int sz1, student ls2[], int sz2, student ls[]);
student* merge_sort(student ls[], int low, int high);

#endif
