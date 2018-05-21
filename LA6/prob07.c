#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void fillLinkedList(int n){
	struct node *tail = head;
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

void printList(){
	struct node *current = head;
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
	return;
}


void insertAtBeg(struct node *element){
	// printf("%d\n", element->data);
	element->next = head;
	head = element;
	return;
}

void reverse(){
	struct node *tail = head->next;
	struct node *temp = head;
	while(tail != NULL){
		temp->next = tail->next;
		insertAtBeg(tail);
		tail = temp->next;
	}
}

int main(int argc, char const *argv[])
{
	head = (struct node*)malloc(sizeof(struct node));
	int n = rand()%10;
	head->data = rand()%100;
	fillLinkedList(n);
	printList();
	reverse();
	printList();
	return 0;
}