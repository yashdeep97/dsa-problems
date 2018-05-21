#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,m,r;
	scanf("%d %d %d",&m,&n,&r);
	int matrix[m][n];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("\n");
	int i = 0, j = 0;
	while((i < m/2) && (j < n/2)){		
		for (int k = 0; k < r; ++k)
		{
			int x = i, y = j;
			int pre = 0,post;
			for (x; x < m-i; ++x)
			{
				post = matrix[x][y];
				matrix[x][y] = pre;
				pre = post;
			}
			x--;
			y++;
			for (y; y < n-j; ++y)
			{
				post = matrix[x][y];
				matrix[x][y] = pre;
				pre = post;
			}
			y--;
			x--;
			for (x; x >= i; --x)
			{
				post = matrix[x][y];
				matrix[x][y] = pre;
				pre = post;
			}
			x++;
			y--;
			for (y; y >= j; --y)
			{
				post = matrix[x][y];
				matrix[x][y] = pre;
				pre = post;
			}
		}
		i++;
		j++;
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}