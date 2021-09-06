#include <stdio.h>
#include <stdbool.h>

/*
COL stands for the column (the block in which the text will be added), 2 for default
TXT stands for text
*/
const int COL = 2;
const char* TXT = "lorem ipsum";
int main(void)
{
	//Open files
	FILE *file = fopen("conts.csv", "r");
	FILE *out = fopen("contsOut.csv", "w");
	//First check
	if (file == NULL || out == NULL)
	{
		printf("Couldn't load");
		return 1;
	}
	//Define variables used in the while loop
	char c;
	int n, i = 0, col = COL;
	bool first = true;
	
	while (fread(&c, sizeof(char), 1, file))
	{
	n = ftell(file);
	//while we're in first line, print them all
	if (n < 358)
		{
			printf("%c", c);
			fwrite(&c, sizeof(char), 1, out);
		}
	else
	{
		if (c == ',')
		{
			i++;
			if (i == col)
			{
				//if we're on the right position, write them to file
				//and screen as well
				printf("%s", TXT);
				fprintf(out, "%s", TXT);
				i = 0;
				if (first)
				{
					col += (30 - COL);
					first = false;
				}
			}
		}
		printf("%c", c);
		fwrite(&c, sizeof(char), 1, out);
	}
	}
	//Close files
	fclose(file);
	fclose(out);
	printf("\n________________________\n");
	printf("|Successfully completed|");
	printf("\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
	return 0;
}
