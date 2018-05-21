#include <stdio.h>
int main()
{
	long n, ans = 1, mod = 1;
	scanf("%ld",&n);
	for (int i = 0; i < 10; ++i)
	{
		mod = mod*10;
	}
	for (int i = 0; i < n; ++i)
	{
		ans = ans * 2;
		ans = ans%mod;
	}
	printf("%ld\n", ans);
	return 0;
}