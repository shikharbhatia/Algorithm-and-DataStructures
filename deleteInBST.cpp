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
struct node *deletion(struct node *root, int key){
    if(root == NULL){
        return root;
    }
    if(root->data > key){
        root->left = deletion(root->left, key);
    }
    else if(root->data < key){
        root->right = deletion(root->right, key);
    }
    else{
        struct node *temp;
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }

        temp = minVal(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
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
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);
    cout<<endl;
    root = deletion(root, 50);
    root = deletion(root, 20);
    root = deletion(root, 30);

    inorder(root);

    return 0;
}
