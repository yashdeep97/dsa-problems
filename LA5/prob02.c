#include <stdio.h>

int lcm(int i, int n){
	int multiple = n;
	int x = 1;
	while((multiple*x)%i != 0){
		x++;
	}
	return multiple*x;
}

int main(int argc, char const *argv[])
{
	int t,n;
	scanf("%d",&t);
	int arr[t];
	for (int j = 0; j < t; ++j)
	{
		scanf("%d",&n);
		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			sum += lcm(i,n);
		}
		arr[j] = sum;
	}
	for (int i = 0; i < t; ++i)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}