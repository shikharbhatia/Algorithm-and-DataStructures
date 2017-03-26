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
void reverseList(struct node **head){
    struct node *curr = *head;
    struct node *prev = NULL;
    struct node *next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void greaterDel(struct node **head){
    reverseList(head);
    struct node *curr = *head,*temp;
    struct node *mxnode = *head;
    while(curr != NULL && curr->next != NULL){
        if(curr->next->data < mxnode->data){
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
        else{
            curr = curr->next;
            mxnode = curr;
        }
    }
    reverseList(head);
}
int main(){
    struct node *head = NULL;
    push(&head,1);
    push(&head,3);
    push(&head,5);
    push(&head,1);
    push(&head,3);
    push(&head,0);

    struct node *p = head;

    while(p != NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    greaterDel(&head);

    p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}
