#include <stdio.h>

int checkBeauiful(int x, int n){
	int div = 0;
	for (int i = 1; i <= x; ++i)
	{
		if (x%i == 0)
		{
			div++;
		}
	}
	if (div == n)
	{
		return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int a,b,n;
	scanf("%d %d %d",&a,&b,&n);
	int count = 0;
	for (int i = a; i <= b; ++i)
	{
		count += checkBeauiful(i,n);
	}
	printf("%d\n", count);
	return 0;
}