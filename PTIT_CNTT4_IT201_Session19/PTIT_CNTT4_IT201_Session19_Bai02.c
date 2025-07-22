#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;
Node *createNode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void preorder(Node* root){
	if(root == NULL){
	return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}
int main(){
	Node *root = createNode(1);
	Node *node1 = createNode(2);
    Node *node2 = createNode(3);
	Node *node3 = createNode(4);
    root->left = node1;
	root->right = node2;
	node1->left = node3;
	preorder(root);
	return 0;
}