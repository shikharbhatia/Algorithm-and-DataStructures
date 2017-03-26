#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
void print(int path[], int n){
    for(int i = 0; i < n; i++){
        cout<<path[i]<<" ";
    }
}
void util(struct node *root, int path[], int len, int target){
    if(root == NULL)
        return;
    path[len] = root->data;
    len++;
    if(root->data == target){
        print(path, len-1);
    }
    if(root->left == NULL && root->right == NULL){}
    else{
        util(root->left, path, len, target);
        util(root->right, path, len, target);
    }
}
void printAncestors(struct node *root, int target)
{
    int path[1000];
    util(root, path, 0, target);
}
 struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

int main()
{

  /* Construct the following binary tree
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
