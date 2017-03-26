#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

vector<int> v1;
vector<int> v2;

struct node *newNode(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    v1.push_back(root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    v2.push_back(root->data);
}

int LCA(struct node *root, int x, int y)
{
    struct node *temp = root;
    inorder(root);
    postorder(temp);
    int k = 0;
    int i;
    int arr[100];

    vector<int>::iterator it;
    vector<int>::iterator jt;
    vector<int>::iterator index1;
    vector<int>::iterator index2;
    vector<int>::iterator mx;

    for(it = v1.begin(); it != v1.end(); it++)
    {
        if(*it == x)
            index1 = it;
        if(*it == y)
            index2 = it;
    }

    for(it = index1; it <= index2; it++)
    {
        arr[k++] = *it;
    }

    for(i = 0; i < k; i++)
    {
        for(jt = v2.begin(); jt != v2.end(); jt++)
        {
            if(*jt == arr[i])
            {
                if(mx < jt)
                    mx = jt;
            }
        }
    }
    return *mx;
}

int dist(struct node *root, int x, int level)
{
    if(root == NULL)
        return 0;
    if(root->data == x)
    {
        return level;
    }
    int downlevel;
    downlevel = dist(root->left, x, level+1);
    if(downlevel != 0)
        return downlevel;
    downlevel = dist(root->right, x, level+1);
        return downlevel;
}

int main() {
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    struct node *temp1, *temp2, *temp3;
    temp1 = temp2 = temp3 = root;
    cout<<LCA(temp3, 4,5);
   // int ans = dist(root, 4, 1) + dist(temp1, 5, 1) - (2*dist(temp2, LCA(temp3,4,5), 1));
   // cout<<ans;

    return 0;
}
