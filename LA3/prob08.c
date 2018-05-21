#include <stdio.h>

void merge(int arr[], int start, int mid, int end)
{
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
}

int mergeSort(int arr[], int start, int end){
	if (start<end)
	{
		int mid = (start+end)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}

int main(int argc, char const *argv[])
{
	int m,n;
	scanf("%d %d",&m,&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	int result[n];
	int i = 0;
	while(i < m){
		result[i] = -1;
		i++;
	}
	while(i<n){
		int temp[m];
		for (int j = 0; j < m; ++j)
		{
			temp[j] = arr[i-m+j];
		}
		mergeSort(temp,0,m-1);
		double median;
		if (m%2 == 1)
		{
			median = (double)temp[m/2];
		}
		else{
			median = (double)(temp[(m-1)/2] + temp[m/2])/2.0;
		}
		if ((3*median) >= arr[i])
		{
			result[i] = 0;
		}
		else{
			result[i] = 1;
		}
		i++;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}