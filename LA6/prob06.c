#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *pre;
};

struct node* insertBeg(struct node *head){
	int x;
	scanf("%d",&x);
	struct node *beg = (struct node*)malloc(sizeof(struct node));
	beg->pre = NULL;
	beg->data = x;
	beg->next = head;
	head->pre = beg;
	return beg;
}

struct node* insertLast(struct node *tail){

	int x;
	scanf("%d",&x);
	struct node *end = (struct node*)malloc(sizeof(struct node));
	tail->next = end;
	end->pre = tail;
	end->data = x;
	end->next = NULL;
	return end;
}

struct node* removeBeg(struct node *head){
	struct node *newHead = head;
	if (head->next != NULL)
	{
		newHead = head->next;
		newHead->pre = NULL;
	}
	return newHead;
}

struct node* removeLast(struct node *tail){
	struct node *newTail = tail;
	if (tail->pre != NULL)
	{
		newTail = tail->pre;
		newTail->next = NULL;
	}
	return newTail;
}

void removeElement(struct node *head){
	int x;
	scanf("%d",&x);
	struct node *current = head;
	while(current != NULL){
		if (current->data == x)
		{
			struct node *temp1 = current->pre;
			struct node *temp2 = current->next;
			if (temp1!=NULL && temp2!=NULL)
			{
				temp1->next = temp2;
				temp2->pre = temp1;
			}
			return;
		}
		current = current->next;
	}
	return;
}

void printList(struct node *head){
	struct node *current = head;
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
	return;
}

int main(int argc, char const *argv[])
{
	char c;
	scanf("%c",&c);
	struct node *head = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	head->data = 1;
	head->pre = NULL;
	head->next = NULL;
	struct node *tail = head;
	while(c != 'q'){
		if (c=='a')
		{
			head = insertBeg(head);
		}
		else if (c=='b')
		{
			tail = insertLast(tail);
		}
		else if (c=='c')
		{
			head = removeBeg(head);
		}
		else if (c=='d')
		{
			tail = removeLast(tail);
		}
		else if (c=='e')
		{
			removeElement(head);
		}
		else if (c=='f')
		{
			printList(head);
		}
		scanf("%c",&c);
	}
	return 0;
}