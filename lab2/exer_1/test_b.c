# include <stdio.h>

int main(int argc, char * argv[])
{
	argv[0] = (argv[0]) + 2;
	
	for(int i = 0; i < argc; i++)
	{
		printf("%s ", argv[i]);
	
	
	}
	printf("\n");

}
