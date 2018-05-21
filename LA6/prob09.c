#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void fillLinkedList(int n, int cycle){
	struct node *tail = head;
	for (int i = 0; i < n; ++i)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = rand()%100;
		temp->next = NULL;
		tail->next = temp;
		tail = tail->next;
	}
	if (cycle == 1)
	{
		tail->next = head;
	}
	return;
}

int checkCyclic(){
	struct node *tail = head->next;
	while(1){
		if (tail == head)
		{
			return 1;
		}
		if (tail == NULL)
		{
			return 0;
		}
		tail = tail->next;
	}
}

int main(int argc, char const *argv[])
{
	head = (struct node*)malloc(sizeof(struct node));
	int cycle,n;
	scanf("%d %d",&n,&cycle);  //Enter number of nodes and cyclic/acyclic
	n--;
	head->data = rand()%100;
	fillLinkedList(n,cycle);
	printf("%d\n", checkCyclic());
	return 0;
}