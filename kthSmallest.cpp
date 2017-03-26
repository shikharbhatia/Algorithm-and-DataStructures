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
struct node *insert(struct node *root, int key){
    if(root == NULL){
        return newNode(key);
    }
    if(root->data < key){
        root->right = insert(root->right, key);
    }
    else{
        root->left = insert(root->left, key);
    }
    return root;
}
struct node *minVal(struct node *p){
    while(p->left != NULL){
        p = p->left;
    }
    return p;
}
void kthSmallest(struct node *root ,int k){
    static int i = 0;

    if(root == NULL)
        return;
    kthSmallest(root->left, k);
        if(k == i){
            cout<<root->data<<endl;
        }
    i++;
    kthSmallest(root->right, k);
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    struct node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    inorder(root);
    cout<<endl;

    kthSmallest(root, 6);

    return 0;
}
