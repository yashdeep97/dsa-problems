#include <stdio.h>

int median(int n, int arr[n]){
    if (n%2 == 0) {
        return (arr[n/2] + arr[n/2-1])/2;
    }
    return arr[n/2];
}

int max(int a, int b){
    return a>b ? a : b;
}

int min(int a, int b){
    return a>b ? b : a;
}

int findMedian(int n, int arr1[], int arr2[]){
    if (n==1) {
        return (arr1[0]+arr2[0])/2;
    }
    if (n==2) {
        return (max(arr1[0],arr2[0]) + min(arr1[1],arr2[1]))/2;
    }
    int m1 = median(n,arr1);
    int m2 = median(n,arr2);
    if (m1 == m2) {
        return m1;
    }
    if (m1 < m2) {
        if (n%2 == 0) {
            return findMedian(n-n/2+1, arr1+n/2-1, arr2);
        }
        return findMedian(n-n/2, arr1+n/2, arr2);
    }
    if (n%2 == 0) {
        return findMedian(n-n/2+1, arr1, arr2+n/2-1);
    }
    return findMedian(n-n/2, arr1, arr2+n/2);

}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int arr1[n];
    int arr2[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    printf("%d\n", findMedian(n,arr1,arr2));
    return 0;
}
