#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
vector<int> v1;
vector<int>::iterator it;

struct node *newNode(int data){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void printInorder(struct node *root){
    if(root == NULL)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
void storeInorder(struct node *root){
    if(root == NULL)
        return;
    storeInorder(root->left);
    v1.push_back(root->data);
    storeInorder(root->right);

    it = v1.begin();
}

struct node *arrayToBST(struct node *root){

    if(root == NULL)
        return NULL;

    arrayToBST(root->left);
    root->data = *it;
    if(it != v1.end())
        it++;
    arrayToBST(root->right);

    return root;
}
struct node *binaryTreeToBST(struct node *root){
    if(root == NULL)
        return NULL;

    storeInorder(root);

    sort(v1.begin(), v1.end());

    struct node *new_root = arrayToBST(root);

    return new_root;
}
int main()
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */

    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    printInorder(root);

    cout<<endl;

    struct node *new_root = binaryTreeToBST (root);

    cout<<"Converted BST is :"<<endl;

    printInorder (new_root);

    return 0;
}
