#include <stdio.h>
 int main(int argc, char const *argv[])
 {
 	long long x;
 	scanf("%lld", &x);
 	int arr[14];
 	for (int i = 13; i >= 0; --i)
 	{
 		arr[i] = x%10;
 		x /= 10;
 	}
 	int check = arr[13];
 	for (int i = 0; i < 6; ++i)
 	{
 		int temp = arr[i];
 		arr[i] = arr[12-i];
 		arr[12-i] = temp;
 	}
 	
 	for (int i = 0; i < 13; i += 2)
 	{
 		arr[i] *= 2;
 		if (arr[i] > 9)
 		{
 			int temp = arr[i]/10 + arr[i]%10;
 			arr[i] = temp;
 		}
 	}
 	// for (int i = 0; i < 14; ++i)
 	// {
 	// 	printf("%d", arr[i]);
 	// }
 	printf("\n");
 	int sum = 0;
 	for (int i = 0; i < 13; ++i)
 	{
 		sum += arr[i];
 	}
 	
 	sum += check;

 	if (sum%10 == 0)
 	{
 		printf("Credit card is valid\n");
 	}
 	else{
 		printf("Credit card is not valid\n");
 	}
 	return 0;
 }