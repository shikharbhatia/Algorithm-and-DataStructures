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

struct node *reverseList(struct node *head, int k){
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next = NULL;
    int i = 0;

    while(curr != NULL && i < k){
        next  = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    if(next != NULL){
        head->next = reverseList(next, k);
    }
    return prev;
}
int main(){
    struct node *head = NULL;

    push(&head, 0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    int k = 3;

    head = reverseList(head, k);
    struct node *t = head;
    while(t != NULL){
        cout<<t->data<<" ";
        t = t->next;
    }

    return 0;
}
