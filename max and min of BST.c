#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

struct Node* findMin(struct Node* root) {
    if (root == NULL) return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node* findMax(struct Node* root) {
    if (root == NULL) return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    struct Node* minNode = findMin(root);
    struct Node* maxNode = findMax(root);

    if (minNode != NULL)
        printf("Minimum element = %d\n", minNode->data);

    if (maxNode != NULL)
        printf("Maximum element = %d\n", maxNode->data);

    return 0;
}

