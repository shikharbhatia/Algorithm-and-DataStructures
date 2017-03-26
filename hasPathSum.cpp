#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int val){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

bool hasPathSum(struct node *root, int sum){
    if(root == NULL){
        return (sum == 0);
    }
    bool ans = 0;
    int subsum = sum-root->data;

    if(subsum == 0 && root->left == NULL & root->right == NULL){
        return 1;
    }
    if(root->left){
        ans = ans || hasPathSum(root->left, subsum);
    }
    if(root->right)
        ans = ans || hasPathSum(root->right, subsum);

    return ans;
}
int main(){
    struct node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);

    int sum = 21;

    if(hasPathSum(root, sum)){
        cout<<"YOYOYO";
    }
    else{
        cout<<"NONONO";
    }

    return 0;
}
