# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include<ctype.h>

int isnumber(char * s);

int main(int argc, char * argv[])
{
	for(int i = 0; i < argc; i++)
	{
		if(isnumber(argv[i]))
		{	
			int conv = atoi(argv[i]);
			printf("%d\n", conv);
	
		}
	}

	


}
int isnumber(char * s)
{
	for(int i = 0; i < strlen(s); i++)
	{
		if(!isdigit(s[i]))
			return 0;	
	}
	
	return 1;

}
