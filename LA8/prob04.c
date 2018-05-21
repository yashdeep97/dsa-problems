#include <stdio.h>
#define max 1000000

int main(int argc, char const *argv[]) {
    int m;
    scanf("%d", &m);
    int matrix[m][m];
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            matrix[i][j] = x;
            if (x != 0) {
                count++;
            }
        }
    }

    int edges[count][3];
    int k = 0;
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                edges[k][0] = i;
                edges[k][1] = j;
                edges[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    int dist[m];
    int parent[m];
    dist[0] = 0;
    for (size_t i = 1; i < m; i++) {
        dist[i] = max;
    }
    for (size_t k = 0; k < m-1; k++) {
        for (size_t i = 0; i < count; i++) {
            if (dist[edges[i][1]] > dist[edges[i][0]] + edges[i][2]) {
                dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];
                parent[edges[i][1]] = edges[i][0];
            }
        }
    }
    int flag = 0;
    for (size_t i = 0; i < count; i++) {
        if (dist[edges[i][1]] > dist[edges[i][0]] + edges[i][2]) {
            flag = 1;
            break;
        }
    }
    printf("%d\n", flag);
    return 0;
}
