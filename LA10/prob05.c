#include <stdio.h>

int isSafe(int n, int matrix[n][n], int row, int col){
    int i,j;
    for (i = 0; i < n; i++) {
        if (matrix[row][i] == 1) {
            return 0;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--,j--) {
        if (matrix[i][j] == 1) {
            return 0;
        }
    }
    for (i=row, j=col; j>=0 && i<n; i++, j--){
        if (matrix[i][j] == 1) {
            return 0;
        }
    }
    return 1;
}

int placeQueen(int n, int matrix[n][n], int col){
    if (col >= n) {
        return 1;
    }
    for (size_t i = 0; i < n; i++) {
        if (isSafe(n,matrix,i,col) == 1) {
            matrix[i][col] = 1;
            if (placeQueen(n, matrix, col+1) == 1) {
                return 1;
            }
            matrix[i][col] = 0;
        }
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    if (placeQueen(n, matrix, 0) == 0) {
        printf("Not possible\n");
        return 0;
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
