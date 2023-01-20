#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};



struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node)); //creting node
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


void inorder(struct node *root) {
    if (root != NULL) {

        inorder(root->left);

        printf("%d ", root->key);  //inorder


        inorder(root->right);
    }
}

void Preorder(struct node* root)
{
    if (root != NULL) {

        Preorder(root->left);
        printf("%d ", root->key);      //preorder
        Preorder(root->right);
    }
}

void Postorder(struct node* root)
{
    if (root == NULL) {
        Postorder(root->left);
        Postorder(root->right);      //postorder
        printf(" %d ", root->key);
    }
}


struct node *insert(struct node *node, int key) {

    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);    //insertion
    else
        node->right = insert(node->right, key);
    return node;
}


struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL)    //inorder sucessorf
        current = current->left;
    return current;
}


struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);  //deleting inorder node
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}




int main() {
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);    // Driver code
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    printf("Preorder Traversal: ");
    Preorder(root);
    printf("\n");
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Postorder Traversal: \n");
    Postorder(root);
    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 10);
    printf("After Deleting Preorder traversal: ");
    inorder(root);



}
