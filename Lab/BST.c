#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;


// Function to create a new node with a given value
Node* createNode(int value)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to perform in-order traversal
void inOrder(Node* root)
{
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

// Function to insert a node in the tree
Node* insertNode(Node* root, int value)
{
    if(root == NULL) {
        return createNode(value);
    }
    if(value < root->key) {
        root->left = insertNode(root->left, value);
    }
    else if(value > root->key) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to find the minimum value
Node* findMin(Node* root)
{
    if(root == NULL) {
        return NULL;
    }
    else if(root->left != NULL) {
        return findMin(root->left);
    }
    return root;
}

// Function to delete a node from the tree
Node* deleteNode(Node* root, int key)
{
    if(root == NULL)
        return NULL;
    
    if(key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else if(key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL) {
            Node* temp;
            if(root->left == NULL) {
                temp = root->right;
            }
            else {
                temp = root->left;
            }
            free(root);
            return temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

int main()
{
    Node* root = NULL;
    
    root = insertNode(root, 50);
    
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    
    inOrder(root);
    printf("\n");
    
    deleteNode(root, 50);
    
    inOrder(root);
 
    return 0;   
}