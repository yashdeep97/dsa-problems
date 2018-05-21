#include <stdio.h>

int main(int argc, char const *argv[]) {
    int m,n;
    scanf("%d %d", &n,&m);
    int edges[m][2];
    for (size_t i = 0; i < m; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    int nodes[n];
    for (size_t i = 0; i < n; i++) {
        nodes[i] = i;
    }
    for (size_t i = 0; i < m; i++) {
        int a = nodes[edges[i][0]-1];
        int b = nodes[edges[i][1]-1];
        nodes[edges[i][1]-1] = a;
        for (size_t j = 0; j < n; j++) {
            if (nodes[j] == b) {
                nodes[j] = a;
            }
        }
    }
    int distinct = 1;
    for (size_t i = 0; i < n-1; i++) {
        if (nodes[i]!=nodes[i+1]) {
            distinct++;
        }
    }
    printf("%d\n",distinct);
    return 0;
}
