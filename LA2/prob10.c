#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n,k;
	scanf("%d %d", &n, &k);
	char smallNum[n];
	char largeNum[n];
	smallNum[n] = '\0';
	largeNum[n] = '\0';
	int distinct = k-1;
	
	int i = 1;
	while(i<=n){
		if (distinct <= 1)
		{
			smallNum[n-i] = '0';
		}
		else{
			smallNum[n-i] = distinct + '0';
			distinct--;
		}
		i++;
	}
	smallNum[0] = '1';
	printf("%s ", smallNum);
	
	i = 0;
	while(i <= n-k){
		largeNum[i] = '9';
		i++;
	}
	int c = 1;
	while(i < n){
		largeNum[i] = (9-c) + '0';
		i++;
		c++;
	}
	printf("%s\n", largeNum);
	return 0;
}