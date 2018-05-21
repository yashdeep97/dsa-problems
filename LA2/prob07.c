#include <stdio.h>
//#include <string.h>

int main()
{
	int key;
	printf("Enter Encrytion key: ");
	scanf("%d", &key);
	char t;
	scanf("%c",&t);
	printf("String: ");
	char str[100];
	scanf("%[^\n]%*c", str);

	// printf("%s\n", str);
	char fence[key][100];
	int i = 0;
	int index = 0;
	while(str[i] != '\0'){
		for (int j = 0; j < key; ++j)
		{
			if (str[i] == ' ')
			{
				i++;
			}		
			fence[j][index] = str[i];
			fence[j][index + 1] = '\0';
			i++;
		}
		index++;
	}
	for (int i = 0; i < key; ++i)
	{
		printf("%s", fence[i]);
	}
	printf("\n");
	return 0;
}