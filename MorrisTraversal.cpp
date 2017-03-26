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
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void morris(struct node *root)
{
    struct node *curr, *pre;

    if(root == NULL)
        return;
    curr = root;

    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else
        {
            pre = curr->left;

            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;
            if(pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);

    morris(root);

    return 0;
}
