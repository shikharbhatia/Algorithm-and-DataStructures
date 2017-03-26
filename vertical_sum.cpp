#include <bits/stdc++.h>
#include <map>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *newnode;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
void vertical(struct node *root, int dist, map<int,int> &m){
    if(root == NULL)
        return;

    m[dist] += root->data;

    vertical(root->left, dist-1, m);
    vertical(root->right, dist+1, m);
}
void verticalSum(struct node *root){
    map<int , int> m;
    int dist = 0;
    vertical(root, dist, m);
 //   map<int, int> ordered(m.begin(), m.end());
    map<int, int>::iterator it = m.begin();
    while(it != m.end()){
        cout<<it->second<<" ";
        it++;
    }
}
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    verticalSum(root);

    return 0;
}
