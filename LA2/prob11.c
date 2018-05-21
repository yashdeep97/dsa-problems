#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	int swapped[2];
	int pos[2];
	int count = 0;
	for (int i = 0; i < n-1; ++i)
	{
		if (arr[i] > arr[i+1] && count == 0)
		{
			swapped[count] = arr[i];
			pos[count] = i;
			count++;
			swapped[count] = arr[i+1];
			pos[count] = i+1;
		}
		if (arr[i] > arr[i+1] && i != pos[0])
		{
			swapped[count] = arr[i+1];
			pos[count] = i+1;
			printf("%d\n",i);
			break;
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		printf("number: %d  position: %d \n", swapped[i],pos[i]);
	}
	return 0;
}