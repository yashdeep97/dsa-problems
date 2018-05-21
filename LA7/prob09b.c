#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *left;
	struct node *right;
};

struct node * insert(int val,struct node *tail);
struct node * makeBST(int len,struct node *start,struct node *end);
void inorder_chalo(struct node *root);

int main(){
	int N;
	scanf("%d",&N);
	struct node *head=NULL;
	struct node *tail=NULL;
	for(int i=0;i<N;i++){
		int val;
		scanf(" %d",&val);
		tail=insert(val,tail);
		printf(" %d:%p \n",i,tail);
		if(head==NULL){
			head=tail;
		}
	}

	printf("Making BST\n");
	struct node *root = makeBST(N-1,head,tail);

	printf("Making BST successful\n");
	inorder_chalo(root);
	printf("\n");
	return 0;
}

struct node * insert(int val,struct node *tail){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->left=tail;
	temp->right=NULL;
	if(tail!=NULL){
		tail->right=temp;
	}
	return temp;
}

void inorder_chalo(struct node *root){
	if(root->left==NULL && root->right==NULL){
		printf("%d ",root->val);
		return;
	}
	else{
		if(root->left!=NULL){
			inorder_chalo(root->left);
		}
		printf("%d ",root->val);
		if(root->right!=NULL){
			inorder_chalo(root->right);
		}
	}
}

struct node * makeBST(int len,struct node *start,struct node *end){
	//len is in terms of 0 based indexing 0,1,2,3.....
	//printf("%p %p\n",start,end);
	//handling the base case
	if(start==end){
		printf("%d %p\n",len,start);
		start->left=NULL;
		start->right=NULL;
		return start;
	}

	//getting the current mid element as root
	int mid=len/2+len%2;
	struct node *root=start;
	for(int i=0;i<mid;i++){
		root=root->right;
	}
	printf("%d %d %p\n",len,mid,root);


	//making the left subporition to sub-tree
	struct node *lroot=NULL;
	if(root->left!=NULL){
		(root->left)->right=NULL;	//disconnecting the twor halves ffrom root now.
		lroot=makeBST(mid-1,start,root->left);
	}
	root->left=lroot;

	//making the right sub-portion to sub-tree
	struct node *rroot=NULL;
	if(root->right!=NULL){
		(root->right)->left=NULL;	//disconnecting the twor halves ffrom root now.
		rroot=makeBST(len-mid-1,root->right,end);
	}
	root->right=rroot;

	return root;
}
