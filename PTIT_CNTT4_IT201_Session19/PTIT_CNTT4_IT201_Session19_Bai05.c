#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
bool search(Node *root, int target) {
    if(root == NULL) {
        return false;
    }
    if(root->data == target) {
        return true;
    }
    bool left = search(root->left, target);
    if(left) {
        return true;
    }
    bool right = search(root->right, target);
    return right;
}
int main(){
    Node *root = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    inorder(root);
    int value;
    printf("nhap gia tri: ");
    scanf("%d", &value);
    if (search(root, value)) {
        printf("true");
    }else {
        printf("false");
    }
    return 0;
}