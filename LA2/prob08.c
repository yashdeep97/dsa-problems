#include <stdio.h>
#include <math.h>
int checkPrime(int x){
	for (int i = 2; i <= sqrt(x); ++i)
	{
		if (x%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int sum = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (n%i == 0)
		{
			if (checkPrime(i) == 1)
			{
				int temp = n;
				int count = 0;
				while(temp%i == 0){
					count++;
					temp = temp/i;
				}
				sum += count;
			}
		}	
	}
	printf("%d\n", sum);
	return 0;
}