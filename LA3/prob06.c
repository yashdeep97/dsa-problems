#include <stdio.h>

int selectionSort(int start, int n, int arr[n]){
	int swaps = 0;
	for (int i = start; i < n-1; ++i)
	{
		int min = arr[i];
		int index = i;
		for (int j = i; j < n; ++j)
		{
			if (min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
		arr[i] = min;
		swaps++;
	}
	return swaps;
}

int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d %d",&n,&m);
	int x[n], y[m];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&x[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&y[i]);
	}
	int k = 0, temp;
	for (int i = 0; i < m; ++i)
	{
		for (int j = k; j < n; ++j)
		{
			if (x[j] == y[i])
			{
				temp = x[k];
				x[k] = x[j];
				x[j] = temp;
				k++;
			}
		}
	}
	int start = k;
	selectionSort(start,n,x);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
	return 0;
}