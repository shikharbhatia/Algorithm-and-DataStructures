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

bool detectLoop(struct node *temp){
    struct node *slowptr, *fastptr;
    slowptr = temp;
    fastptr = temp;

    while(slowptr && fastptr && fastptr->next){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;

        if(slowptr == fastptr){
            return 1;
        }
    }
    return 0;
}
int main(){
    struct node *head = NULL;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    head->next->next->next->next->next = head;

    //printList(head);

    cout<<detectLoop(head)<<endl;

//    printList(head);

    return 0;
}
