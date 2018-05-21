#include <stdio.h>

int main(int argc, char const *argv[])
{
	int posMatrix[8][8];
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			scanf("%d", &posMatrix[i][j]);
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		int count = 0;
		for (int j = 0; j < 8; ++j)
		{
			if (posMatrix[i][j] == 1)
			{
				count++;
			}
		}
		if (count > 1)
		{
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		int count = 0;
		for (int j = 0; j < 8; ++j)
		{
			if (posMatrix[j][i] == 1)
			{
				count++;
			}
		}
		if (count > 1)
		{
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		int count = 0;
		for (int j = 0; j <= i; ++j)
		{
			if (posMatrix[i-j][j] == 1)
			{
				count++;
			}
		}
		if (count > 1)
		{
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		int count = 0;
		for (int j = 0; j <= i; ++j)
		{
			if (posMatrix[7-i+j][7-j] == 1)
			{
				count++;
			}
		}
		if (count > 1)
		{
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		int count = 0;
		for (int j = 0; j <= i; ++j)
		{
			if (posMatrix[7-i+j][j] == 1)
			{
				count++;
			}
		}
		if (count > 1)
		{
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		int count = 0;
		for (int j = 0; j <= i; ++j)
		{
			if (posMatrix[i-j][7-j] == 1)
			{
				count++;
			}
		}
		if (count > 1)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}