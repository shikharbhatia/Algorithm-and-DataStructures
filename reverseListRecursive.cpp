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
void printList(struct node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
void utility(struct node **head, struct node *curr, struct node *prev){
    if(curr->next == NULL){
        curr->next = prev;
        *head = curr;
        return;
    }
    struct node *next = curr->next;
    curr->next = prev;
    utility(head, next, curr);
}
void reverseList(struct node **head){
    if(*head == NULL)
        return;
    utility(head, *head, NULL);
}
int main(){
    struct node *head = NULL;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printList(head);
    cout<<endl;
    reverseList(&head);

    printList(head);

    return 0;
}
