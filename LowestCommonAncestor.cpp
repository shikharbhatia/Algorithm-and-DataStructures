#include <bits/stdc++.h>

using namespace std;


struct node {
    int data;
    struct node *left, *right;
};

vector <int> v1;
vector <int> v2;

struct node *newNode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
void inorder(struct node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    v1.push_back(#include <bits/stdc++.h>

using namespace std;


struct node {
    int data;
    struct node *left, *right;
};

vector <int> v1;
vector <int> v2;

struct node *newNode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
void inorder(struct node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    v1.push_back(root->data);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    v2.push_back(root->data);
    cout<<root->data<<" ";
}

int LCA(struct node *root, int x, int y){
    struct node *temp = root;
    inorder(root);
    cout<<endl;
    postorder(temp);
    int arr[100];
    vector<int>::iterator index1,index2;
    int i,j;
    vector<int>::iterator it;
    vector<int>::iterator jt;
    for(it = v1.begin(); it != v1.end(); it++){
        if(*it == x)
            index1 = it;
        if(*it == y)
            index2 = it;
    }
   cout<<*index1<<" "<<*index2;
    int k = 0;
    for(it = index1; it <= index2; it++){
        arr[k++] = *it;
    }
    vector<int>::iterator mx;
    for(i = 0; i < k; i++){
        for(jt = v2.begin(); jt != v2.end(); jt++){
            if(arr[i] == *jt){
                if(mx < jt)
                    mx = jt;
            }
        }
    }
    return *mx;
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

    int ans = LCA(root, 4, 6);
    cout<<endl;
    cout<<"answer is=";
    cout<<ans;
}
root->data);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    v2.push_back(root->data);
    cout<<root->data<<" ";
}

int LCA(struct node *root, int x, int y){
    struct node *temp = root;
    inorder(root);
    cout<<endl;
    postorder(temp);
    int arr[100];
    vector<int>::iterator index1,index2;
    int i,j;
    vector<int>::iterator it;
    vector<int>::iterator jt;
    for(it = v1.begin(); it != v1.end(); it++){
        if(*it == x)
            index1 = it;
        if(*it == y)
            index2 = it;
    }
    int k = 0;
    for(it = index1; it <= index2; it++){
        arr[k++] = *it;
    }
    vector<int>::iterator mx;
    for(i = 0; i < k; i++){
        for(jt = v2.begin(); jt != v2.end(); jt++){
            if(arr[i] == *jt){
                if(mx < jt)
                    mx = jt;
            }
        }
    }
    return *mx;
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

    int ans = LCA(root, 4, 6);
    cout<<endl;
    cout<<"answer is=";
    cout<<ans;
}
