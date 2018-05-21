#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
    struct node* left;
    struct node* right;
};

int findPos(int start, int end, char inorder[], char data){
    for (size_t i = start; i <= end; i++) {
        if (inorder[i] == data) {
            return i;
        }
    }
}

struct node* createTree(int instart, int inend, char inorder[], char postorder[], int *pIndex){
    if (instart > inend) {
        return NULL;
    }

    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp->data = postorder[*pIndex];
    (*pIndex)--;    //Be careful here
    int pos = findPos(instart, inend, inorder, temp->data);

    temp->right = createTree(pos+1, inend, inorder, postorder, pIndex);
    temp->left = createTree(instart, pos-1, inorder, postorder,pIndex);

    return temp;
}

void preOrder(struct node* node){
    if (node == NULL) {
        return;
    }
    printf("%c ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main(int argc, char const *argv[]) {
    int n;
    char inorder[100];
    char postorder[100];
    scanf("%s", inorder);
    scanf("%s", postorder);
    n = strlen(inorder);
    int pIndex = n-1;
    struct node* head = createTree(0, n-1, inorder, postorder, &pIndex);
    preOrder(head);
    printf("\n");
    return 0;
}
