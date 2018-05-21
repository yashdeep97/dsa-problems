#include <stdio.h>
#include <limits.h>

int numops(int n)
{
	int result = 0;
	result += n/5;
	n %= 5;
	result += n/3;
	n %= 3;
	result += n;
	return result;
}

int main()
{
	int i,j;
	int n;
	int min = INT_MAX;
	int max = INT_MIN;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(min>a[i])
			min=a[i];
		if(max<a[i])
			max = a[i];
	}
	int ops = 0;
	int minops = INT_MAX;
	for(i=0;i<5;i++)
	{
		for(j=0;j<n;j++)
			ops += numops(a[j]-min+i);
		if(minops > ops)
			minops = ops;
		ops = 0;
	}
	printf("%d\n",minops);
}
