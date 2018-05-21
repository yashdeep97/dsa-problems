// very important
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	int	*matrix = (int *)malloc(n*n*sizeof(int));
	int x = 1;
	int xhighlimit = n;
	int yhighlimit = n;
	int xlowlimit = 0;
	int ylowlimit = 0;
	int i = 0;
	int j = 0;
	while(x <= n*n){
		
		for (j; j < xhighlimit; ++j)
		{
			*(matrix + i*n + j) = x;
			x++;
		}
		printf("Hello\n");
		j--;
		i++;
		for (i; i < yhighlimit; ++i)
		{
			*(matrix + i*n + j) = x;
			x++;
		}
		i--;
		j--;
		for (j; j >= xlowlimit ; --j)
		{
			*(matrix + i*n + j) = x;
			x++;
		}
		j++;
		--i;
		xlowlimit++;
		ylowlimit++;
		for (i; i >= ylowlimit ; --i)
		{
			*(matrix + i*n + j) = x;
			x++;
		}
		i++;
		j++;
		xhighlimit--;
		yhighlimit--;
		
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (*(matrix + i*n + j)/10 == 0)
			{
				printf(" %d ", *(matrix + i*n + j));
			}
			else printf("%d ", *(matrix + i*n + j));
		}
		printf("\n");
	}

	return 0;
}