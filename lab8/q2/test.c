#include<stdio.h>

int main(void)
{
	int n = 0;
	while(n != -1)
	{
		scanf("%d", &n);
		printf("%d\n", n);
	}
}

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey)
{
	KeyStruct keysarr;
	keysarr = (KeyStruct)malloc(sizeof(struct keyStruct));
	keysarr->Keys = (int*)malloc(sizeof(int) * lsSize);
	keysarr->keysSize = 0;
	
	int arr[hikey - lowkey] = {0};
	for(int i = 0; i< lsSize; i++)
	{
		arr[Ls[i]]++;
	
	}
	int j = 0;
	for(int i = 0; i < hikey - lowkey; i++)
	{
		if(arr[i] != 0)
		{
			(keysarr->Keys)[j] = i;
			(keysarr->keysSize)++;
			j++;
		}
	}
	
	return keysarr;

}
