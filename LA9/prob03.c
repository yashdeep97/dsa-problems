// with quick sort
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
    struct node* pre;
};

void printList(struct node* head){
    while (head!=NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct node* partition(struct node* start, struct node* end){
    int temp1 = start->next;
    while (temp!=end) {
        while (temp1->val <= start->val) {
            temp1 = temp1->next;
        }
        while (end->val >= start->val) {
            end = end->pre;
        }
        // swap temp1 and end
    }
    // swap temp1 and start
    return temp1;
}

void quickSort(struct node* start, struct node* end){
    if (start != end) {
        struct node* pi = partition(start, end);
        quickSort(start,pi->pre);
        quickSort(pi->next,end);
    }
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    struct node* head = (struct node*)malloc(sizeof(struct node*));
    struct node* tail = head;
    head->val = rand()%1000;
    head->next = NULL;
    head->pre = NULL;
    n--;
    for (size_t i = 0; i < n; i++) {
        struct node* temp = (struct node*)malloc(sizeof(struct node*));
        temp->next = NULL;
        temp->val = rand()%1000;
        tail->next = temp;
        tail = temp;
    }
    printList(head);
    quickSort(head, tail);
    printList(head);
    return 0;
}
