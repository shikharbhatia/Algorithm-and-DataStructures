#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->left = NULL;
    t->right = NULL;

    return t;
}

int liss(struct node *root){
    if(root == NULL)
        return 0;

    int size_exc = liss(root->left)+liss(root->right);

    int size_inc = 1;
    if(root->left)
        size_inc += liss(root->left->left)+liss(root->left->right);
    if(root->right)
        size_inc += liss(root->right->left)+liss(root->right->right);

    return max(size_inc, size_exc);
}
int main(){
    struct node *root         = newnode(20);
    root->left                = newnode(8);
    root->left->left          = newnode(4);
    root->left->right         = newnode(12);
    root->left->right->left   = newnode(10);
    root->left->right->right  = newnode(14);
    root->right               = newnode(22);
    root->right->right        = newnode(25);

    cout<<liss(root);

    return 0;

}
