#include <stdio.h>
#include <stdlib.h>

struct queue{
    int data;
    int height;
    struct queue* next;
};

struct queue* insert(int x, int height, struct queue* tail){
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue*));
    temp->data = x;
    temp->height = height;
    temp->next = NULL;
    if (tail == NULL) {
        return temp;
    }
    tail->next = temp;
    return temp;
}

int found(struct queue* temp, int y){
    while (temp != NULL) {
        if (temp->data == y) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int difference(int a, int b){
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int p = a%10;
        int q = b%10;
        if (p!=q) {
            count++;
        }
        a = a/10;
        b = b/10;
    }
    if (count == 1) {
        return 1;
    }
    return 0;
}

struct queue* findChildren(int element, int h, struct queue* tail, int x, int y, int sieve[]){
    for (int i = x+1; i <= y; i++) {
        if (sieve[i] == 0 && difference(element,i)) {
            tail = insert(i,h,tail);
        }
    }
    return tail;
}

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    int sieve[10000];
    for (int i = 0; i < 10000; i++) {
        sieve[i] = 0;
    }
    for (int i = 2; i < 10000; i++) {
        for (int j = i+1; j < 10000; j++) {
            if (j%i == 0) {
                sieve[j] = -1;
            }
        }
    }
    int ans[t];
    for (int i = 0; i < t; i++) {
        int x,y;
        scanf("%d %d", &x,&y);
        struct queue* head = NULL;
        struct queue* tail = head;
        tail = insert(x, 0, tail);
        head = tail;
        struct queue* temp = head;
        while (found(temp,y) != 1) {
            int popped = head->data;
            int h = head->height;
            h++;
            temp = tail;
            tail = findChildren(popped,h,tail,x,y,sieve);
            head = head->next;
        }
        ans[i] = tail->height;
    }
    printf("\n");
    for (int i = 0; i < t; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
