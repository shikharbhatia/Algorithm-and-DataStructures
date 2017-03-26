#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *right;
    struct node *down;
};

void push(struct node **head, int val){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->right = NULL;
    temp->down = *head;
    *head = temp;
}
struct node *merge(struct node *a, struct node *b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    struct node *result;
    if(a->data <= b->data){
        result = a;
        result->down = merge(a->down, b);
    }
    else{
        result = b;
        result->down = merge(a, b->down);
    }
    return result;
}
struct node *flatten(struct node *root){
    if(root == NULL || root->right == NULL)
        return root;
    return merge(root, flatten(root->right));
}
void printList(struct node *t)
{
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->down;
    }
}
int main(){
    struct node *root = NULL;
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    root = flatten(root);

    printList(root);

    return 0;
}
