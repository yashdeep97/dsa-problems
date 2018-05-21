#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;
struct node *tail;

void fillLinkedList(int n){
	tail = head;
	for (int i = 0; i < n; ++i)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = rand()%100;
		temp->next = NULL;
		tail->next = temp;
		tail = tail->next;
	}
	return;
}

void printList(struct node* a){
  struct node* current = a;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
  return;
}

struct node* merge(struct node* a, struct node* b){
  struct node* temp;
  if (a->data < b->data) {
    temp = a;
    a = a->next;
  }
  else{
    temp = b;
    b = b->next;
  }
  struct node* current = temp;
  temp->next = NULL;
  while (a!=NULL && b!=NULL) {
    if (a->data < b->data) {
      current->next = a;
      a = a->next;
    }
    else{
      current->next = b;
      b = b->next;
    }

    current = current->next;
    current->next = NULL;
  }
  while (a!=NULL) {
    current->next = a;
    a = a->next;
    current = current->next;
    current->next = NULL;
  }
  while (b!=NULL) {
    current->next = b;
    b = b->next;
    current = current->next;
    current->next = NULL;
  }
  return temp;
}

struct node* mergeSort(struct node* start){
  if (start->next == NULL) {
    return start;
  }
  struct node* fast = start;
  struct node* slow = start;
  struct node* temp = NULL;
  while (fast != NULL && fast->next!=NULL) {
    temp = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  temp->next = NULL;
  start = mergeSort(start);
  slow = mergeSort(slow);

  return merge(start,slow);
}

int main(int argc, char const *argv[])
{
	head = (struct node*)malloc(sizeof(struct node));
	int n;
	scanf("%d",&n);
	n--;
	head->data = rand()%100;
	fillLinkedList(n);
	printList(head);
  	head = mergeSort(head);
  	printList(head);
	return 0;
}
