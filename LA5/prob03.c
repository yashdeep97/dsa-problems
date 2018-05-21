#include <stdio.h>

int findMax(int rows, int cols, int mid, int matrix[rows][cols]){
	int maxIndex = 0;
	for (int i = 0; i < rows; ++i)
	{
		if (matrix[maxIndex][mid] < matrix[i][mid])
		{
			maxIndex = i;
		}
	}
	return maxIndex;
}

int findPeak(int rows, int cols, int matrix[rows][cols], int mid){
	int maxIndex = findMax(rows,cols,mid,matrix);
	int max = matrix[maxIndex][mid];
	if (mid == 0 || mid == cols-1)
	{
		return max;
	}

	if (max >= matrix[maxIndex][mid-1] && max >= matrix[maxIndex][mid+1]){
		return max;
	}

	if (max < matrix[maxIndex][mid-1])
		return findPeak(rows, cols, matrix, mid - mid/2);

	return findPeak(rows, cols, matrix, mid + mid/2);
}

int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d %d", &n, &m);
	int matrix[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("%d\n", findPeak(n,m,matrix,m/2));
	return 0;
}