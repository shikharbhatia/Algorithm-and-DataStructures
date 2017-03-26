#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};


struct node* newnode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

bool printAncestors(struct node *root, int key){
    if(root == NULL)
        return 0;
    if(root->data == key)
        return 1;
    if(printAncestors(root->left, key) || printAncestors(root->right, key)){
        cout<<root->data<<" ";
        return 1;
    }
    return 0;

}

int main()
{
/*
                1
              /   \
            2      3
          /  \
        4     5
       /
      7
    */
    struct node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5);
    root->left->left->left  = newnode(7);

    printAncestors(root, 1);

    return 0;
}
