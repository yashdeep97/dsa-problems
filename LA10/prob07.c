#include <stdio.h>
#include <math.h>

int countMax(int n, int j, int start, int end, int binary[n][32]){
    int count0 = 0;
    for (size_t i = start-1; i < end; i++) {
        if (binary[i][j] == 0) {
            count0++;
        }
    }
    if (count0 > (end-start+1)/2) {
        return 1;
    }
    return 0;
}

int toDecimal(int ans[32]){
    int x = 0;
    for (size_t i = 0; i < 31; i++) {
        x += ans[i]*pow(2,i);
    }
    return x;
}

int main(int argc, char const *argv[]) {
    int n, q;
    scanf("%d %d", &n,&q);
    int arr[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int queries[q][2];
    for (size_t i = 0; i < q; i++) {
        scanf("%d %d", &queries[i][0], &queries[i][1]);
    }
    int binary[n][32];
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < 32; j++) {
            binary[i][j] = arr[i]%2;
            arr[i] /= 2;
        }
    }
    printf("\n");
    int ansArray[q];
    for (size_t i = 0; i < q; i++) {
        int ans[32];
        for (size_t j = 0; j < 32; j++) {
            ans[j] = countMax(n, j, queries[i][0], queries[i][1], binary);
        }
        ansArray[i] = toDecimal(ans);
        printf("%d\n", ansArray[i]);
    }
    return 0;
}
