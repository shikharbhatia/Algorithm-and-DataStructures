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

void deleteTree(struct node *node){
    if(node == NULL)
        return;
    deleteTree(node->left);
    deleteTree(node->right);

    cout<<"data being deleted = "<<node->data<<endl;

    free(node);
}
int main(){

       struct node *root1 = newNode(1);
   // struct node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);

    deleteTree(root1);

    return 0;
}
