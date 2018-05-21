// **Important
#include <stdio.h>

void sort(int n, int arr[n], int pos[n]){
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;

				temp = pos[j];
				pos[j] = pos[j+1];
				pos[j+1] = temp;
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
	int originalPosition[n];
	int visited[n];
	for (int i = 0; i < n; ++i)
	{
		originalPosition[i] = i;
		visited[i] = 0;
	}
	sort(n,arr,originalPosition);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == 1 || originalPosition[i] == i)
		{
			continue;
		}

		int cycleSize = 0;
		int j = i;
		while(visited[j] != 1){
			visited[j] = 1;
			j = originalPosition[j];
			cycleSize++;
		}
		ans += (cycleSize-1);
	}
	printf("%d\n", ans);
	return 0;
}