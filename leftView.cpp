#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int val){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
void leftViewUtil(struct node *root, int level, int *mx){
    if(root == NULL)
        return;
    if(level > *mx){
        *mx = level;
        cout<<root->data<<" ";
    }
    leftViewUtil(root->left, level+1, mx);
    leftViewUtil(root->right, level+1, mx);
}
void leftView(struct node *root){
    int mx = 0;
    leftViewUtil(root, 1 ,&mx);
}
int main(){
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    leftView(root);

    return 0;
}
