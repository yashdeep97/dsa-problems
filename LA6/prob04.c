#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char data;
	struct node* pre;
	struct node* next;
};

struct node* tail;
struct node* head;
void push(char n){
	if (tail == NULL)
	{
		tail = (struct node*)malloc(sizeof(struct node*));
		tail->pre = NULL;
		tail->next = NULL;
		tail->data = n;
		head = tail;
		return;
	}
	struct node* newNode = (struct node*)malloc(sizeof(struct node*));
	newNode->pre = tail;
	newNode->next = NULL;
	newNode->data = n;
	return;
}

char pop(){
	int num = tail->data;
	tail = tail->pre;
	if (tail!=NULL)
	{
		tail->next = NULL;
	}
	
	return num;
}

int mapRankToOperator(char operation){

	// We are giving rank in the magnitude of number.
	// 4:Best and 1:Last
	if(operation =='/'){
		return 4;
	}
	else if(operation =='*'){
		return 3;
	}
	else if(operation =='-'){
		return 2;
	}
	else if(operation =='+'){
		return 1;
	}
	return -1;//to take care of the "("" which is pushed inside the work buffer.
	// The popping of Stack of operator will only go until "(" cuz it will be in less rank
	//than any of the current operator.
}

int main(int argc, char const *argv[])
{
	tail = NULL;
	char infix[100];
	scanf("%s",infix);
	char postfix[100];
	int index = 0;;
	int currentRank = 0;
	int previousRank = 0;
	for (int i = 0; i < strlen(infix); ++i)
	{
		char data = infix[i];
		if (data=='/' || data=='*' || data=='+' || data=='-')
		{
			currentRank = mapRankToOperator(data);
			if (currentRank > previousRank)
			{
				push(data);
				previousRank=currentRank;
			}
			else{
				do{
					postfix[index] = pop();
					index++;
					if(tail->pre == NULL){
						break;
					}
					char stackData = tail->data;
					previousRank=mapRankToOperator(stackData);
				}while(currentRank <= previousRank);
				push(data);
				previousRank = currentRank;

			}
		}
		else if (data == '('){
			push(data);
			previousRank = mapRankToOperator(data);
		}
		else if (data == ')')
		{
			char stackData = pop();
			while(stackData != '('){
				postfix[index] = stackData;
				index++;
				stackData = pop();
			}
			stackData = pop();
			previousRank = mapRankToOperator(stackData);
		}
		else{
			postfix[index] = data;
			index++;
		}
	}
	while(tail != NULL){
		postfix[index] = pop();
		index++;
	}
	postfix[index] = '\0';
	printf("%s\n", postfix);
	return 0;
}