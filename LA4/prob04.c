#include <stdio.h>

int findMax(int n, int arr[n]){
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

int findIndex(int n, int arr[n]){
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[index] < arr[i])
		{
			index = i;
		}
	}
	return index;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int entryTime[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&entryTime[i]);
	}
	int exitTime[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&exitTime[i]);
	}
	int max = findMax(n,exitTime);
	int time[max + 1];
	for (int i = 0; i <= max; ++i)
	{
		time[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = entryTime[i]; j <= exitTime[i]; ++j)
		{
			time[j]++;
		}
	}
	printf("%d\n", findIndex(max+1,time));
	return 0;
}