#include <stdio.h>
#include <string.h>

int checkParadox(int n, int arr[n][2], int statements[n][2], int index, int truthValue){
    if (arr[index][0] == 1) {
        if (truthValue != arr[index][1]) {
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        arr[index][0] = 1;
        arr[index][1] = truthValue;
        if (truthValue == 1){
            return checkParadox(n,arr,statements,statements[index][0],statements[index][1]);
        }
        else{
            if (statements[index][1] == 1) {
                return checkParadox(n,arr,statements,statements[index][0],0);
            }
            else{
                return checkParadox(n,arr,statements,statements[index][0],1);
            }
        }
    }
}

int remaining(int n, int arr[n][2]){
    for (size_t i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        int statements[n][2];
        int st;
        char truth[10];
        for (size_t i = 0; i < n; i++) {
            scanf("%d %[^\n]s", &st, truth);
            statements[i][0] = st-1;
            if (strcmp(truth,"true") == 0) {
                statements[i][1] = 1;
            }
            else{
                statements[i][1] = 0;
            }
        }

        int arr[n][2];
        for (size_t i = 0; i < n; i++) {
            arr[i][0] = 0;  //visited
        }
        int paradoxFlag = 0;
        int start = 0;
        while (1) {
            paradoxFlag = checkParadox(n, arr, statements, start, 1);
            start = remaining(n,arr);
            if (paradoxFlag == 1) {
                printf("PARA\n");
                break;
            }
            if (start == -1) {
                printf("NOT PARA\n");
                break;
            }
        }
        scanf("%d", &n);
    }
    return 0;
}
