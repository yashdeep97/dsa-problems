#include <stdio.h>
int findCount(int n, int m, int x){
    int dp[n+1][x+1];
    for (size_t i = 0; i <= n; i++) {
        for (size_t j = 0; j <= x; j++) {
            dp[i][j] = 0;
        }
    }
    for (size_t j = 0; j <= x && j <= m; j++) {
        dp[1][j] = 1;
    }
    for (size_t i = 2; i <= n; i++) {
        for (size_t j = 1; j <= x; j++) {
            for (size_t k = 1; k <= m && k < j; k++) {
                dp[i][j] += dp[i-1][j-k];
            }
        }
    }
    // for (size_t i = 0; i <=n; i++) {
    //     for (size_t j = 0; j <= x; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return dp[n][x];
}

int main(int argc, char const *argv[]) {
    int n,m,x;
    scanf("%d %d %d", &n, &m, &x);

    int count = findCount(n,m,x);
    printf("%d\n", count);
    return 0;
}
