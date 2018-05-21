// Very important
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int m,n;
	scanf("%d %d",&m,&n);
	int arr[m];
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&arr[i]);
	}
	int parts[m];
	int sumMin = 1;
	int sumMax = 1000;
	int sumMid;
	int flag = 0;
	int partitions;
	while(flag != 1){
		partitions = 0;
		sumMid = (sumMax + sumMin)/2;
		for (int i = 0; i < m; ++i)
		{
			parts[i] = 0;
		}
		int index = 0, sum = 0;
		while(index < m){
			sum += arr[index];
			if (sum > sumMid)
			{

				parts[index] = 1;
				sum = 0;
				index--;
				partitions++;
			}
			index++;
		}
		partitions++;
		if (partitions > n)
		{
			 sumMin = sumMid + 1;
		}
		else if (partitions < n)
		{
			sumMax = sumMid - 1;
		}
		else if (partitions == n)
		{
			flag = 1;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		if (parts[i] == 1)
		{
			printf("| ");
		}
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}