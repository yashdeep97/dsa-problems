#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int i){
  struct node* temp = (struct node*)malloc(sizeof(struct node*));
  temp->data = i;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

void printList(struct node* head){
  printf("%d ", head->data);
  struct node* current = head->right;
  while (current != head) {
    printf("%d ", current->data);
    current = current->right;
  }
  printf("\n");
  return;
}


struct node* findLast(struct node* head){
  struct node* temp = head;
  while (temp->right!=head) {
    temp = temp->right;
  }
  return temp;
}

struct node* concat(struct node* leftList, struct node* rightList){
  if (leftList == NULL) {
    return rightList;
  }
  if (rightList == NULL) {
    return leftList;
  }

  struct node* leftLast = findLast(leftList);
  struct node* rightLast = findLast(rightList);
  leftLast->right = rightList;
  rightList->left = leftLast;

  leftList->left = rightLast;
  rightLast->right = leftList;

  return leftList;
}

struct node* convertTreeToList(struct node* root){
  if (root == NULL) {
    return NULL;
  }
  struct node* left = convertTreeToList(root->left);
  struct node* right = convertTreeToList(root->right);

  root->left = root;
  root->right = root;
  return concat(concat(left,root),right);
}

void printTree(struct node* root){
  if (root == NULL) {
    return;
  }
  printTree(root->left);
  printf("%d ", root->data);
  printTree(root->right);
  return;
}

int main(int argc, char const *argv[]) {
  struct node *root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(5);
  root->left->left = newNode(1);
  root->left->right = newNode(3);
  printTree(root);
  printf("\n" );
  struct node* head = convertTreeToList(root);
  printList(head);
  return 0;
}
