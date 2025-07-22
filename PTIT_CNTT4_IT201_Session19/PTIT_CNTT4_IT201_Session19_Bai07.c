#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(Node *root, int value) {
    if (root == NULL) return;

    Node **queue = (Node**)malloc(100 * sizeof(Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node *current = queue[front++];

        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            queue[rear++] = current->right;
        }
    }

    free(queue);
}

void printLevelOrder(Node *root) {
    if (root == NULL) return;

    Node **queue = (Node**)malloc(100 * sizeof(Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node *current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    free(queue);
}

int main() {
    Node *root = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    int value;
    printf("nhap gia tri: ");
    scanf("%d", &value);
    addNode(root,value);

    printf("cay sau khi them:\n");
    printLevelOrder(root);

    return 0;
}
