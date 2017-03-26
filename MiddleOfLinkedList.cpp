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
int middle(struct node *head){
    struct node *slow, *fast;
    slow = head;
    fast = head;

    while(fast->next != NULL && slow != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}
int main(){
    struct node *head = NULL;

    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    push(&head, 0);

    int mid = middle(head);

    cout<<mid<<endl;

    return 0;
}
