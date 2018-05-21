#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	int left = 0;
	int right = n-1;
	int temp;
	while(left < right){
		if (arr[left]%2 == 0)
		{
			left++;
		}
		else if (arr[right]%2 == 1)
		{
			right--;
		}
		else if (arr[left]%2 == 1 && arr[right]%2 == 0)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}