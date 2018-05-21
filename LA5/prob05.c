// *** Very very important ***
#include <stdio.h>

int findMedian(int arr[],int start, int n){
	for (int i = start; i < (start + n - 1); ++i)
	{
		for (int j = start; j < (start + n - 1) - i; ++j)
		{
			int temp;
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	return arr[start + (n/2)];
}
//*** Partition fuction - refer quick sort
// could be done using a seperate array(simpler)
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// It searches for x in arr[l..r], and partitions the array 
// around x.
int partition(int arr[], int l, int r, int x)
{
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
 
    // Standard partition algorithm
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{
    int n = r-l+1; // Number of elements in arr[l..r]

    // Divide arr[] in groups of size 5, calculate median
    // of every group and store it in median[] array.
    int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
    for (i=0; i<n/5; i++)
        median[i] = findMedian(arr,l+i*5, 5);
    if (i*5 < n) //For last group with less than 5 elements
    {
        median[i] = findMedian(arr,l+i*5, n%5); 
        i++;
    }    

    // Find median of all medians using recursive call.
    // If median[] has only one element, then no need
    // of recursive call
    int medOfMed = (i == 1)? median[i-1]:
                             kthSmallest(median, 0, i-1, i/2);

    // Partition the array around a random element and
    // get position of pivot element in sorted array
    int pos = partition(arr, l, r, medOfMed);

    // If position is same as k
    if (pos-l == k-1)
        return arr[pos];
    if (pos-l > k-1)  // If position is more, recur for left
        return kthSmallest(arr, l, pos-1, k);

    // Else recur for right subarray
    return kthSmallest(arr, pos+1, r, k-pos+l-1);

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
	int medOfmed = kthSmallest(arr,0,n-1,n/2);
	printf("%d\n", medOfmed);
	return 0;
}