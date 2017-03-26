#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
void recursive(struct node *newnode, int path[], int pathlen);
void printpaths(struct node *newnode)
{
    int path[1000];
    recursive(newnode, path, 0);
}
void printArray(int path[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void recursive(struct node *newnode, int path[], int pathlen)
{
    if(newnode == NULL)
        return;
    path[pathlen] = newnode->data;
    pathlen++;

    if(newnode->left == NULL && newnode->right == NULL)
    {
        printArray(path, pathlen);
    }
    else
    {
        recursive(newnode->left, path, pathlen);
        recursive(newnode->right, path, pathlen);
    }
}
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printpaths(root);

}
