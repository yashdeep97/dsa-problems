#include <stdio.h>

int hashTable[10];

int search(int s){
    int hashIndex = s%10;
    int i = 0;
    while(hashTable[hashIndex] != s && i<11){
        ++i;
        hashIndex = (s + (i*i))%10;
    }
    if (i>10) {
        return -1;
    }
    else{
        return hashIndex;
    }
}

void insert(int x){
    int hashIndex = x%10;
    int i = 0;
    while(hashTable[hashIndex] != -1){
        ++i;
        hashIndex = (x + (i*i))%10;
    }
    hashTable[hashIndex] = x;
    printf("Done\n");
    return;
}

void print(){
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
    return;
}

void delete(int d){
    int index = search(d);
    if (index!=-1) {
        hashTable[index] = -1;
    }
    return;
}

int main(int argc, char const *argv[]) {
    for (size_t i = 0; i < 10; i++) {
        hashTable[i] = -1;
    }
    int input;
    scanf("%d", &input);
    while (input != -1) {
        if (input == 1)
        {
            int in;
            scanf("%d", &in);
            insert(in);
        }
        else if (input == 2) {
            int del;
            scanf("%d", &del);
            delete(del);
        }
        else if (input == 3) {
            int ser;
            scanf("%d", &ser);
            printf("Position of element: %d\n", search(ser));
        }
        else if (input == 4) {
            print();
        }
        scanf("%d", &input);
    }
    return 0;
}
