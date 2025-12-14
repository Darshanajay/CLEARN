#include <stdio.h>
#include <stdlib.h>

// BST Node structure
struct Node {
    int imageID;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int id) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->imageID = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert image ID into BST
struct Node* insert(struct Node *root, int id) {
    if (root == NULL)
        return createNode(id);

    if (id < root->imageID)
        root->left = insert(root->left, id);
    else if (id > root->imageID)
        root->right = insert(root->right, id);

    return root;
}

// Preorder Traversal (Root → Left → Right)
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->imageID);
        preorder(root->left);
        preorder(root->right);
    }
}

// Find the largest image ID
int findLargest(struct Node *root) {
    if (root == NULL) {
        printf("No images in database.\n");
        return -1;
    }

    while (root->right != NULL)
        root = root->right;

    return root->imageID;
}

// Main function
int main() {
    struct Node *root = NULL;

    // Insert CT image IDs
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 90);

    // Display preorder traversal
    printf("Preorder Traversal (Indexed Image IDs): ");
    preorder(root);

    // Display largest image ID
    printf("\nLargest Image ID: %d\n", findLargest(root));

    return 0;
}
