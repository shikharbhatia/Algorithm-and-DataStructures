#include <bits/stdc++.h>

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
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;

    return newnode;
}

bool printPath(struct node *root, struct node *target_leaf)
{
 //   cout<<root->data;
    if(root == NULL)
        return 0;
    if(root == target_leaf || printPath(root->left, target_leaf) || printPath(root->right, target_leaf))
    {
        cout<<root->data<<" ";
        return 1;
    }
    return 0;
}

int getTarget(struct node *node, int max_sum, int curr_sum, struct node **target_leaf)
{
   // static struct node *root_temp = node;

    if(node == NULL)
        return max_sum;

    struct node *target = NULL;

    curr_sum += node->data;

    if(node->left == NULL && node->right == NULL)
    {
        if(curr_sum > max_sum)
        {
            max_sum = curr_sum;
            *target_leaf = node;
            //return max_sum;
        }
    }
    int lt = getTarget(node->left, max_sum, curr_sum, target_leaf);
    int rt = getTarget(node->right, max_sum, curr_sum, target_leaf);

    max_sum = max(lt, rt);

   // printPath(root_temp, target);

    return max_sum;
}
int main()
{
    struct node *root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

    struct node *target_leaf;
    int max_sum = getTarget(root, INT_MIN, 0, &target_leaf);
    printPath(root, target_leaf);
    cout<<endl;
    cout<<"maximum sum = "<<max_sum;

    return 0;

}
