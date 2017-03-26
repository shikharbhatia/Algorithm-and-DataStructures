#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};

void push(struct node **head, int val){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}
bool check_iterative(struct node *head, int key){
    if(head == NULL){
        return false;
    }
    while(head != NULL && head->data != key){
        head = head->next;
    }
    if(head == NULL)
        return false;
    return true;
}

bool check(struct node *head, int key){
    if(head == NULL){
        return 0;
    }
    if(head->data == key)
        return true;
    return check(head->next, key);
}
int main(){
    struct node *head = NULL;

    push(&head, 0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    bool ans = check(head, 2);
    bool ans2 = check_iterative(head, 22);

    cout<<ans<<" "<<ans2<<endl;

    return 0;
}
