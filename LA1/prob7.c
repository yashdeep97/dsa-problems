#include <stdio.h>
int main(int argc, char const *argv[])
{
	long long n;
	scanf("%lld",&n);
	int count=0;
	while(n != 0){
		if (n%2 == 1)
		{
			count++;
		}
		n /= 2;
		if (n == 1)
		{
			count++;
			n = 0;
		}
	}
	printf("%d\n", count);
	return 0;
}