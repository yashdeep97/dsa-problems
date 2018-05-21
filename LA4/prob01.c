// Very Important

#include <stdio.h>

void bubbleSort(int n, int arr[n], int index[n]){
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;

				temp = index[j];
				index[j] = index[j+1];
				index[j+1] = temp;
			}
		}
	}
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
	int temp[n];
	for (int i = 0; i < n; ++i)
	{
		temp[i] = arr[i];
	}
	int index[n];
	for (int i = 0; i < n; ++i)
	{
		index[i] = i;
	}
	bubbleSort(n, temp, index);
	int distinct = 1;
	for (int i = 0; i < n-1; ++i)
	{
		if (temp[i] != temp[i+1])
		{
			distinct++;
		}
	}
	int matrix[distinct][2];
	int count = 1;
	int x = 0;
	matrix[0][0] = index[0];
	for (int i = 0; i < n; ++i)
	{
		if (temp[i] != temp[i+1])
		{
			matrix[x+1][0] = index[i+1];
			matrix[x][1] = count;
			x++;
			count = 1;
		}else{
			count++;
		}
	}
	for (int i = 0; i < distinct-1; ++i)
	{
		for (int j = 0; j < distinct - i - 1; ++j)
		{
			if (matrix[j][1] < matrix[j+1][1])
			{
				int temp = matrix[j][1];
				matrix[j][1] = matrix[j+1][1];
				matrix[j+1][1] = temp;

				temp = matrix[j][0];
				matrix[j][0] = matrix[j+1][0];
				matrix[j+1][0] = temp;
			}
			else if (matrix[j][1] == matrix[j+1][1] && matrix[j][0] > matrix[j+1][0])
			{
				int temp = matrix[j][0];
				matrix[j][0] = matrix[j+1][0];
				matrix[j+1][0] = temp;
			}
		}
	}
	int k = 0;
	for (int i = 0; i < distinct; ++i)
	{
		for (int j = 0; j < matrix[i][1]; ++j)
		{
			temp[k] = arr[matrix[i][0]];
			k++;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", temp[i]);
	}
	printf("\n");
	return 0;
}