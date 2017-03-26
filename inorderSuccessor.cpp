#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};
struct node *minVal(struct node *node);
struct node *inOrderSuccessor(struct node *root, struct node *key){
    if(key->right != NULL)
        return minVal(key->right);
    struct node *p = key->parent;
    while(p != NULL && key == p->right){
        key = p;
        p = p->parent;
    }
    return p;
}
struct node *minVal(struct node *node){
    struct node *current = node;
    while(current->left != NULL)
        current = current->left;
    return current;
}

struct node *newNode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;

    return newnode;
}
struct node* insert(struct node* node, int data)
{
  /* 1. If the tree is empty, return a new,
      single node */
  if (node == NULL)
    return(newNode(data));
  else
  {
    struct node *temp;

    /* 2. Otherwise, recur down the tree */
    if (data <= node->data)
    {
         temp = insert(node->left, data);
         node->left  = temp;
         temp->parent= node;
    }
    else
    {
        temp = insert(node->right, data);
        node->right = temp;
        temp->parent = node;
    }
/* return the (unchanged) node pointer */
    return node;
  }
}
int main()
{
  struct node* root = NULL, *temp, *succ, *min;

  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);
  root = insert(root, 14);
  temp = root->left->right->right;

  succ =  inOrderSuccessor(root, temp);
  cout<<succ->data;
}
