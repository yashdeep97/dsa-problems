#include <stdio.h>
int main()
{
	int c,n,p;
	scanf("%d %d %d", &c, &n, &p);
	long ans = 1;
	for (int i = 0; i < n; ++i)
	{
		ans = ans * c;
		ans = ans % p;
		
	}
	
	printf("%ld\n", ans);
	return 0;
}