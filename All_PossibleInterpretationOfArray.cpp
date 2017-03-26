#include <bits/stdc++.h>

using namespace std;

struct node{
    char data[100];
    struct node *left;
    struct node *right;
};

char alphabet[27][2] = {"", "a", "b", "c", "d", "e","f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "v", "z"};
struct node *root=NULL;
int arr[100];
int n;
struct node* create_tree(char str1[], int val){
    struct node *node = new struct node;
    char strn[100];
    strcpy(strn, str1);
    strcpy(node->data, strn);

    if(((10*arr[val+1]+arr[val+2]) <= 26) && (val < n-2)){
        strcat(strn, alphabet[arr[val+1]]);
        node->left = create_tree(strn, val+1);

        strcpy(strn, str1);
        strcat(strn, alphabet[10*arr[val+1] + arr[val+2]]);
        node->right = create_tree(strn, val+2);
    }
    else if(val < n-1){
        strcat(strn, alphabet[arr[val+1]]);
        node->left = create_tree(strn, val+1);
        node->right = NULL;
    }
    else if(val == n-1)
        cout<<node->data<<" ";
    return node;
}
int main()
{
    int i;
    cin>>n;
    for(i = 0; i < n; i++){
        cin>>arr[i];
    }
    struct node *root = create_tree("",-1);
    return 0;
}

