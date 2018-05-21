#include <stdio.h>

int checkZero(int n, int arr[]){
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 0)
		{
			count++;
		}
	}
	if (count == n)
	{
		return 1;
	}
	return 0;
}

int findFreq(int n,int arr[],int num){
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (num == arr[i])
		{
			arr[i] = 0;
			count++;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int cards[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&cards[i]);
	}
	int x = 0;
	int flag = 0;
	while(checkZero(n,cards) != 1 && flag != 1){
		for (int i = 0; i < n; ++i)
		{
			if (cards[i] != 0)
			{
				int freq = findFreq(n,cards,cards[i]);
				if (freq%2 == 1)
				{
					flag = 1;
					break;
				}
			}
		}
		x++;
	}
	if (flag == 1)
	{
		printf("Vishal\n");
	}
	else{
		printf("Tanmay\n");
	}
	return 0;
}