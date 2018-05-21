#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=20;
const int MOD=123456;

int n;
int a[N][N], cache[N][1LL<<N];

int dp(int i, int mask)
{
	if(i==n+1)
		return 0;
	int &ans=cache[i][mask];
	if(ans!=-1)
		return ans;
	ans=1e9;
	for(int j=0;j<n;j++)
	{
		if((mask&(1<<j))==0)
		{
			ans=min(ans, a[i][j+1] + dp(i+1, mask|(1LL<<j)));
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	int ans=dp(1, 0);
	cout<<ans;
}