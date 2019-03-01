#include<stdio.h>

void func(int *arr)
{
	printf("%d, %d\n",arr[0], arr[1]);
	return;
}
int main(void)
{
	int arr[50] = {1};
	func(arr);
}
