#include <bits/stdc++.h>

using namespace std;

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

void PrintRange(struct node *root, int k1, int k2)
{
    if(root == NULL)
        return;
    if(k1 < root->data){
        PrintRange(root->left, k1, k2);
    }
    if(k1 <= root->data && k2>= root->data)
        cout<<root->data<<" ";
    if(k2 > root->data)
        PrintRange(root->right, k1, k2);
}

struct node* newNode(int data)
{
  struct node *temp = new struct node;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

int main()
{
  struct node *root = new struct node;
  int k1 = 10, k2 = 25;

  root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);

  PrintRange(root, k1, k2);

  return 0;
}
