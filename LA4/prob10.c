// **Important - Pancake Sort 
#include <stdio.h>

void reverse(int arr[], int x){
	int temp;
	for (int i = 0; i <= (x/2)-1; ++i)
	{
		temp = arr[i];
		arr[i] = arr[(x-i)-1];
		arr[(x-i)-1] = temp;
	}
}

int findMax(int x, int arr[]){
	int max = 0;
	for (int i = 0; i < x; ++i)
	{
		if (arr[i] > arr[max])
		{
			max = i;
		}
	}
	return max;
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
	int x = n;
	int index;
	while(x > 0){

		index = findMax(x,arr);
		reverse(arr,index+1);
		reverse(arr,x);
		x--;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}