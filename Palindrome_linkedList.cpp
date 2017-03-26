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
void reverseLL(struct node **head){
    struct node *curr = *head, *prev = NULL, *next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
bool isPalindrome(struct node *head){
    if(head == NULL){
        return 1;
    }
    struct node *slowptr,*midnode,*second_half, *fastptr,*prev_slowptr = head;
    slowptr = head;
    fastptr = head;

    while(fastptr != NULL && fastptr->next != NULL){
        fastptr = fastptr->next->next;
        prev_slowptr = slowptr;
        slowptr = slowptr->next;
    }
    if(fastptr != NULL){
        midnode = slowptr;
        slowptr = slowptr->next;
    }
    second_half = slowptr;
    prev_slowptr->next =NULL;
    reverseLL(&second_half);

    struct node *p1 = head, *p2 = second_half;

    while(p1 != NULL && p2 != NULL){
        if(p1->data != p2->data){
            return 0;
        }
        else{
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    if(p1 == NULL && p2 == NULL){
        return 1;
    }
    return 0;
}
void printList(struct node *head){

}
int main(){
    struct node *head = NULL;

    push(&head, 0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
         push(&head, 5);
    push(&head, 2);
    push(&head, 1);
    push(&head, 0);

    bool check = isPalindrome(head);

    cout<<check<<endl;

    return 0;
}
