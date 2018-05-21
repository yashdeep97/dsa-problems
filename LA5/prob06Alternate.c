#include<stdio.h>


long long int count_weights(long long int n,long long int k)
{
	if(k==0)
	return 1;
	
	else if(n==0)
	return 0;
	
	else
	{
		long long int even = count_weights(n/2,k);
		long long int odd = count_weights((n-1)/2,k-1);
		return even+odd;
	}
}

long long int big_enough(long long int n,long long int m,long long int k)
{
	long long int diff = count_weights(2*n,k) - count_weights(n,k);
	return diff >= m;
}

long long int solve(long long int m,long long int k)
{
	long long int low = 0;
	long long int high=1;
	while(!big_enough(high,m,k))
		high *=2;
	
	while(high - low>1)
	{
		long long int mid = (high+low)/2;
		if(big_enough(mid,m,k))
			high = mid;
		else
			low = mid;
	}
	return high;
}

int main()
{
	long long int m,k;
	scanf("%lld %lld",&m,&k);
	printf("%lld\n",solve(m,k));
	return 0;	
}

