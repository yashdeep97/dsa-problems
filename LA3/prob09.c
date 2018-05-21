#include <stdio.h>
#include <string.h>

void sort(int n, char arr[n][20]){
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (strlen(arr[j]) > strlen(arr[j+1]))
			{
				char temp[20];
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j+1]);
				strcpy(arr[j+1],temp);
			}
			else if (strlen(arr[j]) == strlen(arr[j+1]))
			{
				int k = 0;
				while(k < strlen(arr[j])){
					if ((int)arr[j][k] != (int)arr[j+1][k])
					{
						if ((int)arr[j][k] > (int)arr[j+1][k])
						{
							char temp[20];
							strcpy(temp, arr[j]);
							strcpy(arr[j], arr[j+1]);
							strcpy(arr[j+1],temp);
						}
						k = strlen(arr[j]);
					}
					k++;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	char arr[n][20];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", arr[i]);
	}
	sort(n,arr);
	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", arr[i]);
	}
	printf("\n");
	return 0;
}