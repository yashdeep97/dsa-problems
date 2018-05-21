#include <stdio.h>

int main(int argc, char const *argv[])
{
	int m,p,n;
	scanf("%d %d", &m,&p);
	int A[m][p];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < p; ++j)
		{
			scanf("%d", &A[i][j]);
		}
	}
	scanf("%d %d", &p,&n);
	int B[p][n];
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &B[i][j]);
		}
	}
	int ans[m][n], final=0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int sum = 0;
			for (int k = 0; k < p; ++k)
			{
				sum += A[i][k]*B[k][j];
			}
			ans[i][j] = sum;
			final += sum;
		}
	}
	printf("%d\n", final);
	return 0;
}