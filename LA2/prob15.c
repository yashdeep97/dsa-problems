#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int x;
	scanf("%d",&x);
	for (int i = 0; i < x; ++i)
	{
		n = n*n;
		int count = 0;
		int array[10];
		while(n!=0){
			array[count] = n%10;
			n /= 10;
			count++;
		}
		int num = array[count/2]*10 + array[(count/2)+1]*100 + array[(count/2)-1];
		printf("%d\n", num);
		n = num;
	}
	return 0;
}