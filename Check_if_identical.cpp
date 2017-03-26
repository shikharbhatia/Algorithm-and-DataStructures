#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int identical(struct node *node1, struct node *node2)
{
    if(node1 == NULL && node2 == NULL)
        return 1;

    if(node1 != NULL && node2 != NULL)
    {
        return (node1->data == node2->data && identical(node1->left, node2->left) && identical(node1->right, node2->right));
    }

    return 0;
}
struct node *newNode(int data){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

int main()
{
    struct node *root1 = newNode(1);
    struct node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    if(identical(root1, root2))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    return 0;
}
