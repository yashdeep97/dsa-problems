#include<stdio.h>
#include<string.h>
#define INF 1000000

int n,m,x;
int clr[100][100];
int cnt[100];
int w[100];
int c[100];
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

int dp[100][100];

int solve(int id,int cap)
{
	int i;
	if(cap<0)
		return INF;
	if(id==m+1)
		return cap;
	if(dp[id][cap]!=-1)
		return dp[id][cap];
	int ans=INF;
	for(i=0;i<cnt[id];i++)
	{
		ans=min(ans,solve(id+1,cap-w[clr[id][i]]));
	}
	return dp[id][cap]=ans;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	int temp = 0;
	int arr[t];
	while(t--)
	{
		memset(clr,0,sizeof(clr));
		memset(cnt,0,sizeof(cnt));
		memset(w,0,sizeof(w));
		memset(c,0,sizeof(c));
		memset(dp,-1,sizeof(dp));
		scanf("%d %d %d",&n,&m,&x);
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		for(i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
			clr[c[i]][cnt[c[i]]++]=i;
		}
			arr[temp] = solve(1,x);
			temp++;

	}
	for (size_t i = 0; i < temp; i++) {
		if(arr[i]==INF)
		{
			printf("%d\n",-1);
		}
		else
		{
			printf("%d\n",arr[i]);
		}
	}
	return 0;
}
