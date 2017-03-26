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
bool isLeaf(struct node *a){
    if(a == NULL)
        return 0;
    if(a->left == NULL && a->right == NULL)
        return 1;
    return 0;
}
bool isSumTree(struct node *root){
    if(root == NULL || isLeaf(root))
        return 1;
    int lsum, rsum;

    if(isSumTree(root->left) && isSumTree(root->right)){
        if(root->left == NULL){
            lsum = 0;
        }
        else if(isLeaf(root->left)){
            lsum = root->left->data;
        }
        else{
            lsum = 2*(root->left->data);
        }

        if(root->right == NULL){
            rsum = 0;
        }
        else if(isLeaf(root->right)){
            rsum = root->right->data;
        }
        else{
            rsum = 2*(root->right->data);
        }
        return(root->data == (lsum + rsum));
    }
    return 0;
}
int main(){
    struct node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);

    if(isSumTree(root))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");

    return 0;
}
