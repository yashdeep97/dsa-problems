#include <stdio.h>
#include <string.h>
#include <math.h> 
int main()
{
	int n;
	scanf("%d", &n);
	char str[100];
	int ans[n];
	int len;
	for (int x = 0; x < n; ++x)
	{
		scanf("%s", str);
		len = (int)strlen(str);

		int temp = sqrt(len);
		if (temp*temp != len)
		{
			ans[x] = 0;
		}
		else{
			char matrix[temp][temp];
			int k = 0;
			for (int i = 0; i < temp; ++i)
			{
				for (int j = 0; j < temp; ++j)
				{
					matrix[i][j] = str[k];
					k++; 
				}
			}
			int flag = 1;
			for (int i = 0; i < temp; ++i)
			{
				for (int j = i+1; j < temp; ++j)
				{
					 if (matrix[i][j] != matrix[j][i])
					 {
					 	flag = 0;
					 	i = temp;
					 	j = temp;
					 	break;
					 }
				}
			}

			if (flag == 1)
			{
				for (int i = 0; i < temp; ++i)
				{
					for (int j = 0; j < temp; ++j)
					{
						 if (matrix[i][j] != matrix[temp-j-1][temp-i-1])
						 {
						 	flag = 0;
						 	i = temp;
						 	j = temp;
						 	break;
						 }
					}
				}
			}
			ans[x] = flag;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (ans[i] == 1)
		{
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}