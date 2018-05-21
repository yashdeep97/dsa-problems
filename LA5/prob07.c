#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int join[n], leave[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&join[i]);
		scanf("%d",&leave[i]);
	}
	int time = 1;
	int receive[n];
	for (int i = 0; i < n; ++i)
	{
		if (time < join[i])
		{
			time++;
		}
		else if (time <= leave[i])
		{
			receive[i] = time;
			time++;
		}
		else{
			receive[i] = 0;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", receive[i]);
	}
	printf("\n");
	return 0;
}