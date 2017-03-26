#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
}

void TreeToList(struct node *root){
    queue<struct node *> q;
    q.push(root);

    struct node *last = NULL;
    struct node *present = NULL;

    while(!q.empty()){
        present = q.front();
        q.pop();

        if(present->left)
            q.push(present->left);
        if(present->right)
            q.push(present->right);
        present->left = last;
        present->right = q.front();
        last = present;
    }
}

void printlist(struct node *head){
    struct node *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->right;
    }
}
int main() {
    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    TreeToList(root);

    printlist(root);

    return 0;
}
