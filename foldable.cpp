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

void mirror(struct node *root){
    if(root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);

    struct node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}
bool SameStruct(struct node *a, struct node *b){
    if(a == NULL && b == NULL){
        return 1;
    }
    if(a != NULL && b != NULL && SameStruct(a->left, b->left) && SameStruct(a->right, b->right)){
        return 1;
    }
    return 0;
}
bool isFoldable(struct node *root){
    if(root == NULL)
        return 1;

    mirror(root->left);

    bool ans = SameStruct(root->left, root->right);

    mirror(root->right);

    return ans;
}
int main(){
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->right->left  = newNode(4);
    root->right->right = newNode(5);

    if(isFoldable(root) == 1)
    { printf("\n tree is foldable"); }
    else
    { printf("\n tree is not foldable"); }

    return 0;
}
