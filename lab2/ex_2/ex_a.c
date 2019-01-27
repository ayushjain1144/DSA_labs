# include <stdio.h>
# include <stdlib.h>
int main(int argc, char * argv[])
{
	if(argc != 3)
	{
		printf("Specify the required number of arguments");
		exit(1);
	}
	
	FILE * infptr = fopen(argv[1], "r");
	FILE * outfptr = fopen(argv[2], "w");
	
	if(infptr == NULL)
	{
		printf("Error in reading file");
		exit(2);
	
	
	}
	if(outfptr == NULL)
	{
		printf("Error in writing to file");
		exit(3);
	
	
	}
	char c;
	while((c = fgetc(infptr)) != EOF)
	{
		fprintf(outfptr, "%c", c);
	
	
	}
	
	fclose(infptr);
	fclose(outfptr);	



}
