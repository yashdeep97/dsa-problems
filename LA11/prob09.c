#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
int min(int x, int y)
{
	if(x<y)
		return x;
	else return y;
}
int main()
{
	int i,j;
	char a[100];
	char b[100];
	scanf("%s\n",a);
	scanf("%s",b);
	int lena=strlen(a);
	int lenb=strlen(b);
	int dp[101][101];
	for(i=0;i<=lena;i++)
	{
		for(j=0;j<=lenb;j++)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
		}
	}
	printf("%d\n",dp[lena][lenb]);
	return 0;
}
