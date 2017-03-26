#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *a = (struct node *)malloc(sizeof(struct node));
    a->left = NULL;
    a->right = NULL;
    a->data = data;

    return a;
}

int sizeofTree(struct node *root){
    if(root == NULL){
        return 0;
    }
    return sizeofTree(root->left) + 1 + sizeofTree(root->right);
}
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(10);

    int ans = sizeofTree(root);

    cout<<ans<<endl;
}
