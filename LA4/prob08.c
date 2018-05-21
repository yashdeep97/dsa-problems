#include <stdio.h>

void bubbleSort(int n, int arr[n]){
	for (int i = 0; i < n-1; i+=2)
	{
		for (int j = 0; j < n-i-1; j+=2)
		{
			if (arr[j] > arr[j+2])
			{
				int temp = arr[j];
				arr[j] = arr[j+2];
				arr[j+2] = temp;
			}
		}
	}
}
void bubbleReverseSort(int n, int arr[n]){
	for (int i = 1; i < n-1; i+=2)
	{
		for (int j = 1; j < n-i-1; j+=2)
		{
			if (arr[j] < arr[j+2])
			{
				int temp = arr[j];
				arr[j] = arr[j+2];
				arr[j+2] = temp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	bubbleSort(n,arr);
	bubbleReverseSort(n,arr);
	int temp;
	for (int i = 0; i < n/2; ++i)
	{
		for (int j = i+1; j < n-i; j+=2)
		{
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}