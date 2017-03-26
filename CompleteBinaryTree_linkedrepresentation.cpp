#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

struct node* createCompleteTree(struct node** root,struct node** root1,int data,queue <node*> &q)
{

    struct node* node= (*root);
    if(q.empty())
    {
        node=createNode(data);
        (*root1)=(node);
        q.push(node);
    }

    else
    {
        node=q.front();

        if(node->left==NULL)
        {
            node->left=createNode(data);
            q.push(node->left);
            node=node->left;
        }

        else if(node->right==NULL)
        {
            node->right=createNode(data);
            q.push(node->right);
            q.pop();
            node=node->right;
        }
        return node;
    }
    return (node);
}

void print(struct node* node)

{

    if(node==NULL)

        return;

    print(node->left);

    printf("%d ",node->data);

    print(node->right);

}

int main()

{

    queue <node *> q;
    int i;
    struct node* root1=NULL;
    struct node* root=NULL;
    root1=root;

    for(i=1; i<7; i++){
        root=createCompleteTree(&root,&root1,i,q);
    }

    print(root1);

    return 0;
}
