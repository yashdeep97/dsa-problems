// Very important - Stable Counting Sort 
/* Can also be done using 2 arrays containg givent nos. and their corresponding 
number of factors and the sort numberOfFactors array using any comparison based
sort and change the 1st array accordingly*/
#include <stdio.h>
#include <math.h>

int factors(int n){
	int count = 0;
	double sqr = sqrt(n);
	for (int i = 1; i <= sqr; ++i)
	{
		if ((double)i == sqr)
		{
			count++;
		}
		else if (n%i == 0)
		{
			count += 2;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	int numberOfFactors[100];
	for (int i = 0; i < 100; ++i)
	{
		numberOfFactors[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		numberOfFactors[factors(arr[i])]++;
	}
	for (int i = 0; i <= 100; ++i)
	{
		if (i != 0)
		{
			numberOfFactors[i] += numberOfFactors[i-1];
		}
	}
	int output[n];
	for (int i = n-1; i >= 0; --i)
	{
		output[ numberOfFactors[ factors(arr[i]) ] - 1 ] = arr[i];
		numberOfFactors[ factors(arr[i]) ]--;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", output[i]);
	}
	printf("\n");
	return 0;
}