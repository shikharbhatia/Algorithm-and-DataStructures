#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
int k = 1;
struct node *newNode(int data){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
struct node *insert(struct node *root, int key){
    if(root == NULL)
        return newNode(key);
    if(key < root->data)
        root->left = insert(root->left, key);
    if(key > root->data)
        root->right = insert(root->right, key);
    return root;
}

void kthLargest(struct node *root){
    if(root == NULL || k <= 0)
        return;

    kthLargest(root->right);
    k--;
    if(k == 0){
        cout<<root->data;
        return;
    }


    //cout<<root->data<<" "<<k<<endl;
    kthLargest(root->left);
}
/*void myfunc(struct node *root, int k){
    int c = 0;
    kthLargest(root, c, k);
}*/
void inorder(struct node *root){
  if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    //int k = 3;
    cout<<endl;
    cout<<"kth largest element = ";
    kthLargest(root);

    return 0;
}
