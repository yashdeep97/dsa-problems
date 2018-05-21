#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch, a;
	int i, j;
	FILE *fptr1, *fptr2;

	if ((fptr1 = fopen("test.txt", "r+" )) == NULL)
	{
		printf("Error in opening the file\n");
		exit(1);
	}
	ch = getc(fptr1);
	int flag = 0;
	while (ch != EOF)
	{	
		if(ch == '/' && ((a = getc(fptr1)) == '/'))
		{
			while (ch != '\n')
			{
				ch = getc(fptr1);
			}
			printf("\n");
		}

		else if (ch == '/' && a  == '*' )
		{
			while (ch != '*' && (a = getc(fptr1)) != '/')
			{

				ch = getc(fptr1);
			}
			ch = getc(fptr1);
			ch = getc(fptr1);
		}
		else
		{
			printf("%c", ch);
			//ch = getc(fptr1);
		}

		ch = getc(fptr1);
	}
	fclose(fptr1);
	return 0;
}