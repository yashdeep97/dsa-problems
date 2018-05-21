#include <stdio.h>

void multiply(int m, int matrix[m][m]){
    int temp[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int k = 0; k < m; k++) {
                sum += (matrix[i][k]*matrix[k][j]);
            }
            temp[i][j] = sum;
        }
    }
    for (int i = 0; i < m; i++) {
        for (size_t j = 0; j < m; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

int main(int argc, char const *argv[]) {
    int m,k;
    scanf("%d %d", &m, &k);
    int matrix[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int x,y;
    scanf("%d %d", &x, &y);
    int paths = matrix[x][y];
    for (int i = 1; i < k; i++) {
        multiply(m,matrix);
        paths += matrix[x][y];
    }
    printf("%d\n", paths);
    return 0;
}
