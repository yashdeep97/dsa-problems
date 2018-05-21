#include <stdio.h>

int allNines(int n, int arr[n]){
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 9)
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

int isPalindrome(int n, int arr[n]){
	for (int i = (n/2 - 1); i >= 0; --i)
	{
		if (arr[i] != arr[(n-i)-1])
		{
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int digits = 0;
	int temp = n;
	while(temp != 0){
		temp /= 10;
		digits++;
	}
	temp = n;
	int num[digits];
	for (int i = digits-1; i >= 0; --i)
	{
		num[i] = temp%10;
		temp /= 10;
	}
	if (allNines(digits,num) == 1)
	{
		printf("%d\n", n+2);
		return 0;
	}
	else if (isPalindrome(digits,num) == -1)
	{

		int carry = 1;
		int x;
		if (digits%2 == 1) x = digits/2;
		else x = (digits/2) - 1;
		while(x >= 0)
		{
			num[x] += carry;
			carry = num[x]/10;
			num[x] %= 10;
			num[(digits-x)-1] = num[x];
			x--;	
		}
	}
	else{
		int pos = isPalindrome(digits,num);
		if (num[pos] > num[(digits - pos) - 1])
		{
			while(pos >= 0){
				num[(digits - pos) - 1] = num[pos];
				pos--;
			}
		}
		else{
			int carry = 1;
			int x;
			if (digits%2 == 1) x = digits/2;
			else x = (digits/2) - 1;
			while(x >= 0)
			{
				num[x] += carry;
				carry = num[x]/10;
				num[x] %= 10;
				num[(digits-x)-1] = num[x];
				x--;	
			}
		}
	}
	for (int i = 0; i < digits; ++i)
	{
		printf("%d", num[i]);
	}
	printf("\n");
	return 0;
}