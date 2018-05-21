// Too long, take lite :-(

#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int A[n][n];
    int B[n][n];
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    return 0;
}
