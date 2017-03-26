#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
}

void mirror(struct node *newnode){

    struct node *temp;
    if(newnode == NULL)
        return;
    mirror(newnode->left);
    mirror(newnode->right);

    temp = newnode->left;
    newnode->left = newnode->right;
    newnode->right = temp;
}

void inorder(struct node *node){
    if(node == NULL)
        return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
int main(){

       struct node *root1 = newNode(1);
   // struct node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);

    inorder(root1);

    cout<<endl;

    mirror(root1);

    inorder(root1);
    return 0;
}
