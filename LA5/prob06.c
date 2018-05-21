// Very very Important - TODO: (Also use Dynamic Programming)

#include <stdio.h>

long long int countOnes(long long int num){
	long long int c = 0;
	while(num != 0){
		if (num%2 == 1)
		{
			c++;
		}
		num /= 2;
	}
	return c;
}

long long int countNumsInRange(long long int n, long long int k){
	long long int count = 0;
	for (long long int i = 0; i < n; ++i)
	{
		if (countOnes(i) == k)
		{
			count++;
		}
	}
	return count;
}

long long int main(long long int argc, char const *argv[])
{
	long long int m,k;
	scanf("%lld %lld",&m,&k);
	long long int low = 1;
	long long int high = 10000;
	long long int mid, diff;
	while(low < high){
		mid = (high + low)/2;
		diff = countNumsInRange(2*mid, k) - countNumsInRange(mid, k);
		if (diff == m)
		{
			printf("%lld\n", mid);
			return 0;
		}
		else if (diff > mid)
		{
			low = mid;
		}
		else{
			high = mid;
		}
	}
	return 0;
}