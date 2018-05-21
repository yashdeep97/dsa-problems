#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		int num = i;
		int flag = 0;
		while(num != 0){
			int digit = num%10;
			if (digit == 1 || digit == 7 || digit == 9)
			{
				flag = 0;
			}else{
				flag = 1;
				break;
			}
			num /= 10;
		}
		if (flag == 0)
		{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
