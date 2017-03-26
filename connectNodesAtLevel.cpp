#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};

struct node *newnode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->next = NULL;

    return temp;
}
int height(struct node *root){
    if(root == NULL)
        return 0;
    return (1 + max(height(root->left), height(root->right)));
}
void printLevel(struct node *root, int level, struct node **prev){
    if(root == NULL)
        return;
    if(level == 1){
        root->next = *prev;
        *prev = root;
    }
    else if(level>1){
        printLevel(root->right, level-1, prev);
        printLevel(root->left, level-1, prev);

    }
}
void connectNodes(struct node *root){
    int i;

    for(i = 1; i <= height(root); i++){
       struct node *prev = NULL;
        printLevel(root, i, &prev);
    }
}

int main(){
    struct node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->left->right = newnode(999);

    connectNodes(root);

    cout<<root->left->left->data<<" ";
    cout<<root->left->left->next->data;

    return 0;
}
