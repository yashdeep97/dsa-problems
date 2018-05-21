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
		temp->data = i+2;
		temp->next = NULL;
		tail->next = temp;
		tail = tail->next;
	}
	tail->next = head;
	return;
}

int evaluation(int m){
	struct node *tail = head;
	while(tail->next != tail){
		int count = 1;
		while(count < m-1){
			tail = tail->next;
			count++;
		}
		tail->next = (tail->next)->next;
		tail = tail->next;
	}
	return tail->data;
}

int main(int argc, char const *argv[])
{
	head = (struct node*)malloc(sizeof(struct node));
	int m,n;
	scanf("%d %d",&n,&m);
	n--;
	head->data = 1;
	fillLinkedList(n);
	printf("%d\n", evaluation(m));
	return 0;
}