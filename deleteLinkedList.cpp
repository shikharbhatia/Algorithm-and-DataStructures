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
void deleteList(struct node **head){
    if((*head) == NULL)
        return;

    struct node *curr, *next;
    curr = (*head);

    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}
void printList(struct node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    struct node *head = NULL;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printList(head);

    deleteList(&head);

    cout<<endl;
    cout<<"UDA DI MAINE LIST"<<endl;
    printList(head);

    return 0;
}
