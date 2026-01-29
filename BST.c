#include <stdio.h>
#include <stdlib.h>

/* BST Node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

/* Insert a node into BST */
void insert(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL) {
        root = temp;
        return;
    }

    struct node *current = root;
    struct node *parent;

    while (1) {
        parent = current;

        if (data < current->data) {
            current = current->left;
            if (current == NULL) {
                parent->left = temp;
                return;
            }
        } else {
            current = current->right;
            if (current == NULL) {
                parent->right = temp;
                return;
            }
        }
    }
}

/* Inorder Traversal */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder Traversal */
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder Traversal */
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int arr[] = {27, 14, 35, 10, 19, 31, 42};
    int n = 7, i;

    for (i = 0; i < n; i++)
        insert(arr[i]);

    printf("Inorder Traversal  : ");
    inorder(root);

    printf("\nPreorder Traversal : ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
