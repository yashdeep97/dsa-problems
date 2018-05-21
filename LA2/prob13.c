// see alternate
#include <stdio.h>
#include <stdlib.h>

int distance(int a,int b,int c){
	return (abs(a-b)+abs(b-c)+abs(a-c));
}

int main(int argc, char const *argv[])
{
	int a[10] = {-10,2,3,4,5,6,7,8,9,12};
	int b[10] = {-9,-5,-2,0,5,7,9,11,14,16};
	int c[10] = {-1,4,6,8,10,12,14,16,18,20};
	int i=0, j=0, k=0;
	int arr[30];
	int label[30];
	for (int x = 0; x < 30; ++x)
	{
		if ((a[i]<=b[j] || j==10) && (a[i]<=c[k] || k==10) && i<10)
		{
			arr[x] = a[i];
			i++;
			label[x] = 0;
		}
		else if ((b[j]<=a[i] || i==10) && (b[j]<=c[k] || k==10) && j<10)
		{
			arr[x] = b[j];
			j++;
			label[x] = 1;
		}
		else{
			arr[x] = c[k];
			k++;
			label[x] = 2;
		}
	}
	int p = a[0],q = b[0], r = c[0];
	int min = distance(p,q,r);
	for (int i = 0; i < 30; ++i)
	{
		if (label[i] == 0 )
		{
			if (min > distance(arr[i],q,r))
			{
				p = arr[i];
				min = distance(p,q,r);
			}
		}
		else if (label[i] == 1)
		{
			if (min > distance(p,arr[i],r))
			{
				q = arr[i];
				min = distance(p,q,r);
			}
		}
		else if (label[i] == 2){
			if (min > distance(p,q,arr[i]))
			{
				r = arr[i];
				min = distance(p,q,r);
			}
		}
	}
	for (int i = 0; i < 30; ++i)
	{
		printf("(%d,%d) ", arr[i],label[i]);
	}
	printf("\n");
	printf("%d %d %d\n", p,q,r);
	printf("%d\n", min);
	return 0;
}