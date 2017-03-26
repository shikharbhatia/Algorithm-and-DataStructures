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
bool isBST(struct node *root){
    static struct node *prev = NULL;
    if(root){
        if(!isBST(root->left))
            return false;
        if(prev != NULL && prev->data >= root->data)
            return false;
        prev = root;

        return isBST(root->right);
    }
    return true;
}
int main(){
    struct node *root = NULL;
    root = insert(root, 50);
    root->right = newNode(60);

    cout<<isBST(root);

    return 0;
}
