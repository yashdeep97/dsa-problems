#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char given[] = "goodbye";
	char str[100];
	scanf("%s", str);
	int count = 0, i = 0;
	while(count != strlen(given) && str[i] != '\0'){
		if (str[i] == given[count])
		{
			count++;
		}
		i++;
	}
	if (count == strlen(given))
	{
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}