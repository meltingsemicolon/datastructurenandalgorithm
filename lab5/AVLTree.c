//Program in C for inserting an element in AVL tree
#include <stdio.h>
#include <stdlib.h>
// Structure for a node of AVL tree
struct Node 
{
    int key;
    struct Node *left, *right;
    int height;
};
// Function prototypes
int max(int a, int b);
int height(struct Node* node);
struct Node* newNode(int key);
struct Node* rightRotate(struct Node* y);
struct Node* leftRotate(struct Node* x);
int getBalance(struct Node* node);
struct Node* insert(struct Node* node, int key);
void preorder(struct Node* root);
int main() 
{
    struct Node* root = NULL;
    int n, key;
    // Input number of elements
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    // Input elements
    printf("Enter %d elements to insert: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &key);
        root = insert(root, key);
    }
    // Print the AVL tree
    printf("Preorder traversal of the AVL tree after insertion:\n");
    preorder(root);
    printf("\n");
    return 0;
}
// Function to get the maximum of two integers
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
// Function to get height of the tree
int height(struct Node* node) 
{
    if (node == NULL)
        return 0;
    return node->height;
}
// Function to create a new node with the given key
struct Node* newNode(int key) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}
// Function to perform a right rotation
struct Node* rightRotate(struct Node* y) 
{
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x; // New root
}
// Function to perform a left rotation
struct Node* leftRotate(struct Node* x) 
{
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;
    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y; // New root
}
// Function to get the balance factor of a node
int getBalance(struct Node* node) 
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
// Function to insert a key into AVL tree
struct Node* insert(struct Node* node, int key) 
{
    // Perform standard BST insertion
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys not allowed
        return node;
    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));
    // Get the balance factor of this ancestor node to check whether it became unbalanced
    int balance = getBalance(node);
    // If unbalanced, there are 4 cases
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    // Left Right Case
    if (balance > 1 && key > node->left->key) 
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && key < node->right->key) 
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    // If the tree is already balanced, return the unchanged node
    return node;
}
// Function to perform preorder traversal of AVL tree
void preorder(struct Node* root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
