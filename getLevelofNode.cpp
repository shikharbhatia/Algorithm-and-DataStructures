#include<stdio.h>

/* A tree node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
int getLevelUtil(struct node *root, int x, int level){
    if(root == NULL)
        return 0;
    if(root->data == x){
        return level;
    }

    int ans = getLevelUtil(root->left, x, level+1);
    if(ans != 0)
        return ans;
    ans = getLevelUtil(root->right, x, level+1);
    return ans;
}
int getLevel(struct node *root, int x){
        return getLevelUtil(root, x, 1);
}
int main()
{
    struct node *root = new struct node;
    int x;

    /* Constructing tree given in the above figure */
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    for (x = 1; x <=5; x++)
    {
      int level = getLevel(root, x);
      if (level)
        printf(" Level of %d is %d\n", x, getLevel(root, x));
      else
        printf(" %d is not present in tree \n", x);

    }

    getchar();
    return 0;
}
