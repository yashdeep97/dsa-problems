#include <stdio.h>

int bubbleSort(int n, int arr[n]){
	int swaps = 0;
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swaps++;
			}
		}
	}
	return swaps;
}

int insertionSort(int n,int arr[n])
{
	int swaps = 0;
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
           swaps++;
       }
       arr[j+1] = key;
   }
   return swaps;
}

int selectionSort(int n, int arr[n]){
	int swaps = 0;
	for (int i = 0; i < n-1; ++i)
	{
		int min = arr[i];
		int index = i;
		for (int j = i; j < n; ++j)
		{
			if (min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
		arr[i] = min;
		swaps++;
	}
	return swaps;
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
	int temp[n];
	for (int i = 0; i < n; ++i)
	{
		temp[i] = arr[i];
	}
	int bubbleSortSwaps, insertionSortSwaps, selectionSortSwaps;
	bubbleSortSwaps = bubbleSort(n,temp);
	for (int i = 0; i < n; ++i)
	{
		temp[i] = arr[i];
	}
	insertionSortSwaps = insertionSort(n,temp);
	for (int i = 0; i < n; ++i)
	{
		temp[i] = arr[i];
	}
	selectionSortSwaps = selectionSort(n,temp);
	if (bubbleSortSwaps <= insertionSortSwaps && bubbleSortSwaps <= selectionSortSwaps)
	{
		printf("Bubble Sort : %d\n", bubbleSortSwaps);
	}
	else if (insertionSortSwaps > bubbleSortSwaps && insertionSortSwaps >= selectionSortSwaps)
	{
		printf("Insertion Sort : %d\n", insertionSortSwaps);
	}
	else{
		printf("Selection Sort : %d\n", selectionSortSwaps);
	}
	return 0;
}