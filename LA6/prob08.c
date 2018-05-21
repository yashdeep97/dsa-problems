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

void swapPair(){
	struct node *current = head;
	struct node *temp;
	struct node* previous = NULL;
	while(current != NULL && current->next != NULL){
		temp = current->next;
		current->next = temp->next;
		temp->next = current;
		if (previous != NULL)
		{
			previous->next = temp;
		}
		else{
			head = temp;
		}
		previous = current;
		current = current->next;
	}
}

int main(int argc, char const *argv[])
{
	head = (struct node*)malloc(sizeof(struct node));
	int n; //number of elements in linked list + 1
	scanf("%d",&n);
	n--;
	head->data = rand()%100;
	fillLinkedList(n);
	printList();
	swapPair();
	printList();
	return 0;
}