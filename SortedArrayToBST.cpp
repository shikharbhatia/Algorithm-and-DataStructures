#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node *ArrayToBST(int arr[], int s, int e){
    if(s > e)
        return NULL;

    int mid = (s+e)/2;
    struct node *root = newNode(arr[mid]);

    root->left = ArrayToBST(arr, s, mid-1);
    root->right = ArrayToBST(arr, mid+1, e);

    return root;
}

void preOrder(struct node* node)
{
    if (node == NULL)
        return;

    preOrder(node->left);
     printf("%d ", node->data);
    preOrder(node->right);
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    /* Convert List to BST */
    struct node *root = ArrayToBST(arr, 0, n-1);
    printf("\n PreOrder Traversal of constructed BST ");
    cout<<endl;
    preOrder(root);

    return 0;
}

