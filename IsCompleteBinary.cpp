#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int val){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
bool isComplete(struct node *root){
    if(root == NULL){
        return 1;
    }
    queue<struct node *>q;
    q.push(root);
    bool flag = 0;  //this sets true when nonfull node is encountered
    while(!q.empty()){
        struct node *temp = q.front();
        q.pop();
        if(temp->left){
            if(flag == true)
                return false;
            q.push(temp->left);
        }
        else
            flag = true;

        if(temp->right){
            if(flag == true)
                return false;
            q.push(temp->right);
        }
        else
            flag = true;
    }
    return true;
}

int main(){
    struct node *root  = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->left = newNode(6);


    bool ans = isComplete(root);

    cout<<ans<<endl;

    return 0;
}
