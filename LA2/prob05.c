#include <stdio.h>

int main(){
	int matrix[6][6];
	int nonZero = 0;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			scanf("%d", &matrix[i][j]);
			if (matrix[i][j] != 0)
			{
				nonZero++;
			}
		}
	}
	if (nonZero < 10)
	{
		int row[nonZero],col[nonZero],value[nonZero];
		int index = 0;
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (matrix[i][j] != 0)
				{
					row[index] = i;
					col[index] = j;
					value[index] = matrix[i][j];
					printf("%d %d %d\n", row[index], col[index], value[index]);
					index++;
				}
			}
		}

		for (int i = 0; i < 6; ++i)
		{
			for (int j = i; j < 6; ++j)
			{
				int temp = matrix[j][i];
				matrix[j][i] = matrix[i][j];
				matrix[i][j] = temp;
			}
		}

		int trow[nonZero],tcol[nonZero],tvalue[nonZero];
		index = 0;
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (matrix[i][j] != 0)
				{
					trow[index] = i;
					tcol[index] = j;
					tvalue[index] = matrix[i][j];
					printf("%d %d %d\n", trow[index], tcol[index], tvalue[index]);
					index++;
				}
			}
		}
	}
	return 0;
}