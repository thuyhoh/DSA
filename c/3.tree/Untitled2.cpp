#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Node* currNode = *root;
    while (true) {
        if (data < currNode->data) {
            if (currNode->left == NULL) {
                currNode->left = newNode;
                return;
            }
            currNode = currNode->left;
        } else {
            if (currNode->right == NULL) {
                currNode->right = newNode;
                return;
            }
            currNode = currNode->right;
        }
    }
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;

    insertNode(&root, 10);
    insertNode(&root, 5);
    insertNode(&root, 15);
    insertNode(&root, 2);
    insertNode(&root, 12);
    

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

