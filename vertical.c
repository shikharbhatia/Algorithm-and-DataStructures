#include<stdio.h>

#include<stdlib.h>

int k,n,a[100],b[100],c[100];

struct node

{

    int data;

    struct node *left;

    struct node *right;

};

struct node* insert(int n)

{

    struct node *ptr=(struct node*)malloc(sizeof(struct node*));

    ptr->data=n;

    ptr->left=NULL;

    ptr->right=NULL;

}

void vertical(struct node *node, int hd)

{

    if(node==NULL)

        return;

    if(hd==0)

        a[hd]+=node->data;

    else if(hd<0)

    {

        k=hd*-1;

        b[k]+=node->data;

    }

    else

    {

        n=hd;

        c[n]+=node->data;

    }

    if(node->left!=NULL)

        vertical(node->left, hd-1);

    if(node->right!=NULL)

        vertical(node->right, hd+1);

}

void print()

{

    int i,m=1;

    for(i=k; i>=1; i--)

    {

        printf(" \n sum of vertical line number %d is %d ",m,b[i]);

        m++;

    }

    printf("\n sum of vertical line number %d is %d ",m,a[0]);

    for(i=n; i>=1; i--)

    {

        printf(" \n sum of vertical line number %d is %d ",m,c[i]);

        m++;

    }

}

main()

{

    struct node *root=insert(26);

    root->left=insert(10);

    root->left->left=insert(4);

    root->left->right=insert(6);

    root->right=insert(3);

    root->right->left=insert(3);

    vertical(root,0);

    print();

}
