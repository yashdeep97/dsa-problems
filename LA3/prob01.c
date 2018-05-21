#include <stdio.h>
#include <stdlib.h>
int findCost(int ht, int n, int heights[n], int costs[n]){
	int cost = 0;
	for (int i = 0; i < n; ++i)
	{
		int htDiff = abs(heights[i] - ht);
		cost += (costs[i]*htDiff);
	}
	return cost;
}

int main(){
	int T;
	scanf("%d", &T);
	int ans[T];
	for (int i = 0; i < T; ++i)
	{
		int N;
		scanf("%d", &N);
		int heights[N];
		int costs[N];
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &heights[j]);
		}
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &costs[j]);
		}
		int minHeight = 1234;
		int maxheight = -1;
		for (int j = 0; j < N; ++j)
		{
			if (heights[j] < minHeight)
			{
				minHeight = heights[j];
			}
			if (heights[j] > maxheight)
			{
				maxheight = heights[j];
			}
		}
		int mincost = 999999;
		for (int j = minHeight; j <= maxheight; ++j)
		{
			int temp = findCost(j,N,heights,costs);
			if (temp < mincost)
			{
				mincost = temp;
			}
		}
		ans[i] = mincost;
	}
	for (int i = 0; i < T; ++i)
	{
		printf("%d\n", ans[i]);
	}
}