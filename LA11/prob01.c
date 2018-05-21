#include <stdio.h>

int max(int a, int b){
    return a>b ? a : b;
}

int profit(int n, int beg, int end, int wines[n], int cache[n][n]){
    if (beg > end) {
        return 0;
    }
    if (cache[beg][end] != -1) {
        return cache[beg][end];
    }
    int year = n - (end - beg);
    cache[beg][end] = max(
        profit(n,beg+1,end,wines,cache) + wines[beg]*year,
        profit(n,beg,end-1,wines,cache) + wines[end]*year
    );
    return cache[beg][end];
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int wines[n];
    int cache[n][n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &wines[i]);
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cache[i][j] = -1;
        }
    }
    printf("%d\n", profit(n,0,n-1,wines,cache));
    return 0;
}
