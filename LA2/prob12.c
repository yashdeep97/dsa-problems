// does this qualify as O(logn) ?????????? see alternate
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,x;
	scanf("%d %d",&n,&x);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	int start = 0, end = n-1;
	int mid = (start+end)/2;
	while(arr[mid] != x){
		if (arr[mid] > x)
		{
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
		mid = (start+end)/2;
	}
	int count = 0;
	int i = mid;
	while(arr[i] == x){
		count++;
		i++;
	}
	i = mid-1;
	while(arr[i] == x){
		count++;
		i--;
	}
	printf("%d\n", count);
	return 0;
}