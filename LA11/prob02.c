#include <stdio.h>

int sumCoins(int node, int n, int coins[n], int adj[n][n]){
    int sum = 0;
    for (size_t i = node+1; i < n; i++) {
        if (adj[node][i] == 1) {
            for (size_t j = i+1; j < n; j++) {
                if (adj[i][j] == 1) {
                    sum += sumCoins(j,n,coins,adj);
                }
            }
        }
    }

    return coins[node] + sum;
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int coins[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    int adj[n][n];
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    int x, y;
    for (size_t i = 0; i < n-1; i++) {
        scanf("%d %d", &x, &y);
        adj[x-1][y-1] = 1;
        adj[y-1][x-1] = 1;
    }
    int max = 0;
    for (size_t i = 0; i < n; i++) {
        int x = sumCoins(i,n,coins,adj);
        if (x > max) {
            max = x;
        }
    }
    printf("%d\n", max);
    return 0;
}
