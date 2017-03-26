#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
struct node* node = (struct node*)
					malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}


struct info{
    int sz;
    int max;
    int min;
    int ans;
};

info largestBSTBT(node* root){
    info ret = {1,root->data,root->data,1};
    if(root->left)
    {
        info l = largestBSTBT(root->left);
        if(l.max <= ret.min)
        {
            ret.sz += l.sz;
            ret.min = l.min;
        }
        ret.ans = max(ret.ans,max(ret.sz,l.ans));
    }
    if(root->right)
    {
        info r = largestBSTBT(root->right);
        if(r.min>=ret.max)
        {
            ret.sz+=r.sz;
            ret.max = r.max;
        }
        ret.ans = max(ret.ans,max(ret.sz,r.ans));
    }
    return ret;
}


/* Driver program to test above functions*/
int main()
{
	/* Let us construct the following Tree
		50
	/	 \
	10	 60
	/ \	 / \
5 20 55 70
			/	 / \
		45	 65 80
*/

struct node *root = newNode(50);
root->left	 = newNode(30);
root->right	 = newNode(60);
root->left->left = newNode(5);
root->left->right = newNode(20);
root->right->left = newNode(45);
//root->right->left->left = newNode(45);
root->right->right = newNode(70);
root->right->right->left = newNode(65);
root->right->right->right = newNode(80);

/* The complete tree is not BST as 45 is in right subtree of 50.
	The following subtree is the largest BST
		60
	/ \
	55 70
/	 / \
45	 65 80
*/
printf(" Size of the largest BST is %d\n", largestBSTBT(root).ans);

getchar();
return 0;
}
