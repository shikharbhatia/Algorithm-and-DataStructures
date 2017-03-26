#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
void inorder(struct node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
struct node *insert(struct node *root, int data)
{
    if(root == NULL)
        return newNode(data);
    if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}
void utility(struct node *root, int *sum){
    if(root == NULL)
        return;
    utility(root->right, sum);
    *sum += root->data;
    root->data = *sum;
    utility(root->left, sum);
}
void AddGreaterValues(struct node *root){
    int sum = 0;
    utility(root, &sum);
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    AddGreaterValues(root);

    inorder(root);

    return 0;
}


