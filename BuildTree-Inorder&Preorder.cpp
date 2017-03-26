#include<stdio.h>
#include<stdlib.h>
struct node
{
  char data;
  struct node* left;
  struct node* right;
};
int search(char arr[], int strt, int end, char value);
struct node* newNode(char data);

struct node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int idx = 0;
    if(inStrt > inEnd){
        return NULL;
    }
    struct node *root = newNode(pre[idx++]);

    if(inStrt == inEnd){
        return root;
    }
    int inidx = search(in, inStrt, inEnd, root->data);

    root->left = buildTree(in, pre, inStrt, inidx-1);
    root->right = buildTree(in, pre, inidx+1, inEnd);

    return root;
}
int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}
struct node* newNode(char data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

void printInorder(struct node* node)
{
  if (node == NULL)
     return;

  printInorder(node->left);
  printf("%c ", node->data);
  printInorder(node->right);
}
int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};

  int len = sizeof(in)/sizeof(in[0]);

  struct node *root = buildTree(in, pre, 0, len - 1);

  printInorder(root);

  return 0;
}
