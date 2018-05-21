#include <stdio.h>
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    char str[n+1];
    scanf("%s", str);
    int alphabet[26];
    for (size_t i = 0; i < 26; i++) {
        alphabet[i] = 0;
    }
    for (size_t i = 0; i < n; i++) {
        alphabet[(int)str[i] - 97]++;
    }
    int oddCount = 0;
    for (size_t i = 0; i < 26; i++) {
        if (alphabet[i]%2 == 1) {
            oddCount++;
        }
    }
    if (oddCount > 1) {
        printf("-1\n");
        return 0;
    }
    if (oddCount == 1 && n%2 == 0) {
        printf("-1\n");
        return 0;
    }


    int posArray[n];
    int k = 0;
    for (size_t i = 0; i < 26; i++) {
        int j = 0;
        if (alphabet[i]%2 == 1) {
            while ((int)str[j] != (i+97)) {
                j++;
            }
            posArray[n/2] = j;
            j++;
            alphabet[i]--;
        }
        while(alphabet[i] > 0) {
            for (j; j < n; j++) {
                if ((int)str[j] == (i+97)) {
                    if (alphabet[i]%2 == 0) {
                        posArray[k] = j;
                    }
                    else{
                        posArray[(n-k)-1] = j;
                    }
                    k++;
                    alphabet[i]--;
                }
            }
        }
    }
    for (size_t i = 0; i < n; i++) {
        posArray[i]++;
        printf("%d ", posArray[i]);
    }
    printf("\n");
    return 0;
}
