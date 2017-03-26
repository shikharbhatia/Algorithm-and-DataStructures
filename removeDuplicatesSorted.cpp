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
void removeDuplicates(struct node *head){
    struct node *curr = head;
    struct node *next;

    if(curr == NULL){
        return;
    }

    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            next = curr->next->next;
            free(curr->next);
            curr->next = next;
        }
        else
            curr = curr->next;
    }
}
void printList(struct node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    struct node *head = NULL;

    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    removeDuplicates(head);

    printList(head);

    return 0;
}
