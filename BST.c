//
// Created by Sumit Suman on 03-11-2021.
//

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int key;
};

struct Node* new_node(int val){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct  Node *insert(struct Node *Node, int data) {
    if (Node == NULL) return new_node(data);

    if (data < Node->data)
        Node->left = insert(Node->left, data);
    else
        Node->right = insert(Node->right, data);

    return Node;
}

void inorder(struct Node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root){
    if(root != NULL){
        printf("%d -> ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ", root->data);
    }
}

// Find the inorder successor
struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;
    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Deleting a node
struct Node *deleteNode(struct Node *root, int key) {
    // Return if the tree is empty
    if (root == NULL) return root;
    // Find the node to be deleted
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // If the node is with only one child or no child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // If the node has two children
        struct Node *temp = minValueNode(root->right);
        // Place the inorder successor in position of the node to be deleted
        root->key = temp->key;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int count(struct Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

struct Node *min(struct Node *root){
    if(root == NULL){
        return 0;
    }
    else if(root->right == NULL)
        return root;
    else
        return min(root->right);
}


int main() {
    struct Node *root = NULL;
    root = insert(root, 5);//Root of tree will be 5
    insert(root, 1);
    insert(root, 3);
    insert(root, 4);
    insert(root, 2);
    insert(root, 7);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    printf("Total no. of nodes: %d",count(root));
    printf("\n");
    root = min(root);
    printf("Minimum value node:%d",root->data);



    return 0;
}


#include<stdio.h>
int main()
{
    int N,i;
    scanf("%d",&N);
    int count = 0;
    for(i = 1; i <=N; ++i)
    {
        if(N % i == 0)
        {
            count += 1;
        }
    }
    printf("%d",count);

    for(i = 1; i <=N; ++i) {
        if (N % i == 0) {
            printf("%d ", i);
        }

    }
    return 0;
}


