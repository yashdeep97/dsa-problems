#include <stdio.h>
#include <string.h>

void printPermutations(int i, int len, int ascii[], char perm[]) {
    if (i == len) {
        return;
    }
    for (size_t j = 0; j < 128; j++) {
        if (ascii[j] != 0) {
            perm[i] = (char)j;
            ascii[j]--;
            printPermutations(i+1,len,ascii,perm);
            ascii[j]++;
            if (i == len-1) {
                printf("%s\n", perm);
            }
        }
    }
    return;
}

int main(int argc, char const *argv[]) {
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    int ascii[128];
    for (size_t i = 0; i < 128; i++) {
        ascii[i] = 0;
    }
    for (size_t i = 0; i < len; i++) {
        ascii[(int)str[i]]++;
    }
    char permutation[len];
    printPermutations(0,len,ascii,permutation);
    return 0;
}
