#include <stdio.h>

int sort(int n, int nop[n]){
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (nop[j] < nop[j+1])
			{
				int temp = nop[j];
				nop[j] = nop[j+1];
				nop[j+1] = temp;
			}
		}
	}
}

int distictPlayersLeft(int n, int nop[n]){
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (nop[i] > 0)
		{
			count++;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int m, n;
	scanf("%d %d",&n,&m);
	int nop[n];
	int teams = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&nop[i]);
	}
	
	int playersLeft = distictPlayersLeft(n,nop);
	while(playersLeft >= m){
		sort(n,nop);
		int j = 0;
		for (int i = 0; i < n; ++i)
		{
			if (j == m)
			{
				break;
			}
			if (nop[i]!=0)
			{
				nop[i]--;
				j++;
			}
		}
		
		teams++;
		playersLeft = distictPlayersLeft(n,nop);
		
	}
	printf("%d\n", teams);
	return 0;
}