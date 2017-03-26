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

struct node *mergingtwolist(struct node *a, struct node *b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    struct node *result = NULL;
    if(a->data <= b->data){
        result = a;
        result->next = mergingtwolist(a->next, b);
    }
    else if(a->data > b->data){
        result = b;
        result->next = mergingtwolist(a, b->next);
    }
    return result;
}
int main(){
    struct node *head1 = NULL, *head2 = NULL;

    push(&head1, 15);
    push(&head1, 10);
    push(&head1, 5);

    push(&head2, 20);
    push(&head2, 3);
    push(&head2, 2);

    struct node *head = mergingtwolist(head1, head2);

    printList(head);

    return 0;
}
