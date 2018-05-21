// Very very Important - Dynamic Programming
#include <stdio.h>
#include <limits.h>
#include <string.h>

int Palindrome(char str[], int i, int j){
    for (size_t x = 0; x <= j-i; x++) {
        if (str[i+x]!=str[j-x]) {
            return 0;
        }
    }
    return 1;
}

void printString(char str[],  int i, int j){
    for (size_t x = i; x <= j; x++) {
        printf("%c", str[x]);
    }
}

void PalPartition(char str[]){
    int n = strlen(str);
    int C[n][n];

    int i,j,k,l;
    for (i = 0; i < n; i++) {
        C[i][i] = 0;  //Single characters are palindromes
    }
    for (l = 2; l <= n; l++) {
        for (i = 0; i < n-l+1; i++) {
            j = i+l-1;
            if (Palindrome(str,i,j) == 1) {
                C[i][j] = 0;
            }
            else{
                C[i][j] = 10000;
                for (k = i; k <= j-1; k++) {
                    int x = C[i][k] + C[k+1][j] + 1;
                    if (x < C[i][j]) {
                        C[i][j] = x;
                    }
                }
            }
        }
    }

    printf("%d",C[0][n-1]+1);
    i = 0;
    j = 0;
    while (i<n) {

        int k = i;
        for (int x = i; x < n; x++) {
            if (C[i][x] == 0) {
                k = x;
            }
        }
        printf(", ");
        printString(str,i,k);
        i = k+1;
    }
    printf("\n");

}

int main(int argc, char const *argv[]) {
    char str[100];
    scanf("%s", str);
    PalPartition(str);
    return 0;
}
