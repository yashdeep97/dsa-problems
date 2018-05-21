#include <stdio.h>
#include <limits.h>

int angle(int x, int y, int x1, int y1, int x2, int y2){
    int sign = (x-x1)*(y2-y1) - (x2-x1)*(y-y1);
    printf("sign for(%d,%d): %d\n", x2, y2, sign);
    if (sign > 0) {
        return 0;
    }
    return 1;
}

int findMinX(int n,int points[n][2]){
    int min = 0;
    for (int i = 0; i < n; i++) {
        if (points[i][0] < points[min][0]) {
            min = i;
        }
    }
    return min;
}

void sortY(int n, int points[n][2]){
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (points[j][1] > points[j+1][1]) {
                int temp1 = points[j][0];
                int temp2 = points[j][1];
                points[j][0] = points[j+1][0];
                points[j][1] = points[j+1][1];
                points[j+1][0] = temp1;
                points[j+1][1] = temp2;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int points[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
    int min = findMinX(n,points);
    int tos = -1;
    int stack[n][2];
    tos++;
    stack[tos][0] = points[min][0];
    stack[tos][1] = points[min][1];
    points[min][1] = INT_MAX;
    sortY(n,points);
    n--;
    tos++;
    stack[tos][0] = points[0][0];
    stack[tos][1] = points[0][1];

    tos++;
    stack[tos][0] = points[1][0];
    stack[tos][1] = points[1][1];
    printf("testing: %d,%d\n", stack[tos][0],stack[tos][1]);
    for (int i = 2; i < n; i++) {
        if (angle(stack[tos-1][0],stack[tos-1][1],stack[tos][0],stack[tos][1],points[i][0],points[i][1]) == 1) {
            tos++;
            stack[tos][0] = points[i][0];
            stack[tos][1] = points[i][1];
        }
        else{
            stack[tos][0] = points[i][0];
            stack[tos][1] = points[i][1];
        }
    }
    printf("%d\n", tos+1);
    for (int i = 0; i <= tos; i++) {
        printf("(%d, %d) \n", stack[i][0],stack[i][1]);
    }
    return 0;
}
