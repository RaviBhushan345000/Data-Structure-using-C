#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {
    struct node *tempNode = (struct node*)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    if (root == NULL) {
        root = tempNode;
        return;
    }

    current = root;

    while (1) {
        parent = current;

        if (data < parent->data) {
            current = parent->leftChild;
            if (current == NULL) {
                parent->leftChild = tempNode;
                return;
            }
        } else {
            current = parent->rightChild;
            if (current == NULL) {
                parent->rightChild = tempNode;
                return;
            }
        }
    }
}

void postorder_traversal(struct node* root) {
    if (root != NULL) {
        postorder_traversal(root->leftChild);   // LEFT
        postorder_traversal(root->rightChild);  // RIGHT
        printf("%d ", root->data);              // ROOT
    }
}

int main() {
    int i;
    int array[7] = {27, 14, 35, 10, 19, 31, 42};

    for (i = 0; i < 7; i++)
        insert(array[i]);

    printf("Postorder Traversal: ");
    postorder_traversal(root);

    return 0;
}
