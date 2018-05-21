#include <stdio.h>

int checkMajority(int arr[], int start, int end, int element){
    int count = 0;
    for (size_t i = start; i <= end; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    if (count > ((end - start) + 1)/2) {
        return 1;
    }
    return 0;
}

int majority(int arr[], int start, int end){
    if (start == end) {
        return arr[start];
    }
	int mid = (start+end)/2;
	int leftMajor = majority(arr,start,mid);
	int rightMajor = majority(arr,mid+1,end);
	if (leftMajor == -1 && rightMajor == -1) {
        return -1;
    }
    else if (leftMajor != -1 && rightMajor != -1) {
        if (checkMajority(arr,start,end,leftMajor) == 1) {
            return leftMajor;
        }
        else if (checkMajority(arr,start,end,rightMajor) == 1) {
            return rightMajor;
        }
        else{
            return -1;
        }
    }
    else if (leftMajor != -1) {
        if (checkMajority(arr,start,end,leftMajor) == 1) {
            return leftMajor;
        }
        else{
            return -1;
        }
    }
    else{
        if (checkMajority(arr,start,end,rightMajor) == 1) {
            return rightMajor;
        }
        else{
            return -1;
        }
    }

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
	int x = majority(arr,0,n-1);
    if (x == -1) {
        printf("NONE\n");
        return 0;
    }
    printf("%d\n", x);
	return 0;
}
