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

void distort(int arr[], int start, int mid, int end)
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
    int x = 0;
    while(k <= end){
    	if (x%2 == 0)
    	{
    		arr[k] = L[i];
    		i++;	
    	}
    	else{
    		arr[k] = R[j];
    		j++;
    	}
    	x++;
    	k++;
    }
}

int mergeDistort(int arr[], int start, int end){
	if (start<end)
	{
		int mid = (start+end)/2;
		mergeDistort(arr,start,mid);
		mergeDistort(arr,mid+1,end);
		distort(arr,start,mid,end);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	mergeSort(arr,0,n-1);
	mergeDistort(arr,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}