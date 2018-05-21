#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))

int dp[1005][1005];
int max=1e9;

int main()
{
	int n,k,i,j,x;
	scanf("%d %d",&n,&k);
	for(i=1;i<=k;i++)
	{
		dp[i][1]=1;
		dp[i][0]=0;
	}
	for(i=1;i<=n;i++)
	{
		dp[1][i]=i;
	}
	for(i=2;i<=k;i++)
	{
		for(j=2;j<=n;j++)
		{
			dp[i][j]=max;
			for(x=1;x<=j;x++)
			{
				int a=1+MAX(dp[i-1][x-1],dp[i][j-x]);   //logic behind this?
				dp[i][j]=MIN(dp[i][j],a);
			}
		}
	}
    // for (size_t i = 0; i <= k; i++) {
    //     for (size_t j = 0; j <= n; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
	printf("%d\n",dp[k][n]);
	return 0;
}
