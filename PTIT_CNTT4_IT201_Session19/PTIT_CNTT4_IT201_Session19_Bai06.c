#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right= NULL;
    return newNode;
}
typedef struct Queue{
    Node **arr;
    int capacity;
    int front;
    int rear;
}Queue;
Queue *createQueue(int capacity){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Node **)malloc(sizeof(Node)*capacity);
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}
int isEmpty(Queue *queue){
    if(queue->rear < queue->front){
        return 1;
    }
    return 0;
}
void enQueue(Queue *queue, Node *node){
    if(queue->rear == queue->capacity-1){
        return ;
    }
    queue->rear++;
    queue ->arr[queue->rear]= node;
}
void levelorderBFS(Node *root){
    if(root == NULL){
        printf("tree is empty");
        return ;
    }
    Queue *queue = createQueue(100);
    enQueue(queue, root);
    while(!isEmpty(queue)){
        Node *node = queue->arr[queue->front++];
        
        printf("%d ", node->data);
        if(node->left!=NULL){
            enQueue(queue, node->left);
        }
        if(node->right !=NULL){
            enQueue(queue, node->right);
        }
    }
}
void searchLevelOrderBFS(Node *root, int value){
    if(root == NULL){
        printf("tree is empty");
        return ;
    }
    Queue *queue = createQueue(100);
    enQueue(queue, root);
    int found = 0;
    while(!isEmpty(queue)){
        Node *node = queue->arr[queue->front++];
        if(node->data==value){
            found ++;
            printf("true");
        }
        // printf("%d ", node->data);
        if(node->left!=NULL){
            enQueue(queue, node->left);
        }
        if(node->right !=NULL){
            enQueue(queue, node->right);
        }
    }
    if(found==0){
        printf("false");
    }
}
int main(){
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    levelorderBFS(root);
    int value;
    printf("nhap vao gia tri muon tim kiem: ");
    scanf("%d", &value);
    searchLevelOrderBFS(root, value);
    return 0;
}