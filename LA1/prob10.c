// important
#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int factorial[100];
	for (int i = 0; i < 100; ++i)
	{
		factorial[i] = 0;
	}
	factorial[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		int carry = 0;
		for(int j = 0; j < 100; j++)
		{
			int x = factorial[j]*i + carry;
			factorial[j] = (x)%10;
			carry = x/10;

		}
	}
	int i = 99;
	while(factorial[i] == 0){
		i--;
	}
	while(i>=0){
		printf("%d", factorial[i]);
		i--;
	}
	printf("\n");
	return 0;

}
