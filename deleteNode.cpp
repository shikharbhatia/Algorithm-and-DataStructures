#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};
void push(struct node **head, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void deletenode(struct node **head, int data){
    struct node *p = *head, *prev;

    if(p != NULL && p->data == data){
        *head = p->next;
        free(p);
        return;
    }
    while(p != NULL && p->data != data){
        prev = p;
        p = p->next;
    }
    if(p == NULL){
        return;
    }
    prev->next = p->next;
    free(p);
}
void printList(struct node *head){
    struct node *p = head;

    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main(){
    struct node *head = NULL;

    push(&head, 0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    deletenode(&head, 4);

    printList(head);

    return 0;
}
