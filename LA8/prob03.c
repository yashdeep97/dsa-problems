#include <stdio.h>

int main(int argc, char const *argv[]) {
    int m;
    scanf("%d", &m);
    int matrix[m][m];
    char temp;
    scanf("%c", &temp);
    char readString[2*m-1];
    for (int i = 0; i < m; i++) {
        scanf("%[^\n]%*c", readString);
        for (int j = 0; j < m; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            }
            else if (readString[2*j] == 'N') {
                matrix[i][j] = -1;
            }
            else{
                matrix[i][j] = (int)readString[2*j] - 48;
            }
        }
    }
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < m; j++) {
            matrix[i][j] *= -1;
        }
    }
    
    for (size_t k = 0; k < m; k++) {
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < m; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j] && matrix[i][k]!=1 && matrix[k][j]!=1) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    int max = matrix[0][0];
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < m; j++) {
            if(matrix[i][j] < max){
                    max = matrix[i][j];
            }
        }
    }
    printf("%d\n", -1*max);
    return 0;
}
