#include <stdio.h>

int merge(int arr[], int start, int mid, int end)
{
	int count = 0;
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 =  end - mid;

    // create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++){
        L[i] = arr[start + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[mid + 1+ j];
    }
    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
        	for (int x = i; x < n1; ++x)
        	{
        		count++;
        		printf("(%d,%d) ", L[x], R[j]);
        	}
            arr[k] = R[j];
            j++;
        }
        k++;
    }
     while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}

int mergeSort(int arr[], int start, int end){
	int count = 0;
	if (start<end)
	{
		int mid = (start+end)/2;
		count += mergeSort(arr,start,mid);
		count += mergeSort(arr,mid+1,end);
		count += merge(arr,start,mid,end);
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n%d\n",mergeSort(arr,0,n-1));

	return 0;
}
