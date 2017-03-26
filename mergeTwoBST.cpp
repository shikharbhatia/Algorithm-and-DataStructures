#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

vector<int> v1;
vector<int> v2;
vector<int> v;

struct node *newNode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void inorder1(struct node *root){
    if(root == NULL)
        return;
    inorder1(root->left);
    v1.push_back(root->data);
    inorder1(root->right);
}
void inorder2(struct node *root){
    if(root == NULL)
        return;
    inorder2(root->left);
    v2.push_back(root->data);
    inorder2(root->right);
}

void mergeTwoBST(struct node *root1, struct node *root2){
    vector<int>::iterator i;
    vector<int>::iterator j;

    inorder1(root1);
    inorder2(root2);

    i = v1.begin();
    j = v2.begin();
    while(i != v1.end() && j != v2.end()){
        if(*i <= *j){
            v.push_back(*i);
            i++;
        }
        if(*i > *j){
            v.push_back(*j);
            j++;
        }
    }
    while(i != v1.end()){
        v.push_back(*i);
        i++;
    }
    while(j != v2.end()){
        v.push_back(*j);
        j++;
    }
    for(i = v.begin(); i != v.end(); i++){
        cout<<*i<<" ";
    }
}
int main()
{
    struct node  *root1 = NULL, *root2 = NULL;

    /* Let us create the following tree as first tree
            3
          /  \
         1    5
     */
    root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(10);

    /* Let us create the following tree as second tree
            4
          /  \
         2    6
     */
    root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(6);

    mergeTwoBST(root1, root2);

    return 0;
}
