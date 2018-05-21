#include <stdio.h>
#include <string.h>

void sort(int n, char strings[n][100], int binCount[n]){
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (binCount[j] > binCount[j+1])
			{
				int t = binCount[j];
				binCount[j] = binCount[j+1];
				binCount[j+1] = t;

				char temp[100];
				strcpy(temp, strings[j]);
				strcpy(strings[j], strings[j+1]);
				strcpy(strings[j+1],temp);
			}
		}
	}
}

int countOnes(int n){
	int count = 0;
	while(n != 0){
		if (n%2 == 1)
		{
			count++;
		}
		n /= 2;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	char strings[n][100];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",strings[i]);
	}

	int sum[n];
	for (int i = 0; i < n; ++i)
	{
		int s = 0;
		int x = 0;
		while(strings[i][x] != '\0'){
			s += (int)strings[i][x];
			x++;
		}
		sum[i] = s;
	}

	int binCount[n];
	for (int i = 0; i < n; ++i)
	{
		binCount[i] = countOnes(sum[i]);
	}
	sort(n, strings, binCount);
	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", strings[i]);
	}
	return 0;
}