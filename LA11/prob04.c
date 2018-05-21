// modify for multiple test cases
#include<stdio.h>
#include<limits.h>
int dp[100][100];
int a[100];

int min(int a,int b)
{
	return (a<b)?a:b;
}

int sum(int s,int e)
{
	int i,ans=0;
	for(i=s;i<=e;i++)
	{
		ans+=a[i];
		ans=ans%100;
	}
	return ans;
}
int solve(int i,int j)
{
	if(i>=j)
     return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	else
	{
		int k;
		dp[i][j]=INT_MAX;
		for(k=i;k<=j;k++)
		{
			dp[i][j]=min(dp[i][j],solve(i,k)+solve(k+1,j)+sum(i,k)*sum(k+1,j));
		}
		return dp[i][j];
	}

}

int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dp[i][j]=-1;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int ans = solve(0,n-1);
	printf("%d\n",ans);
	return 0;
}
