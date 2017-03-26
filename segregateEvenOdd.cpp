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
void printList(struct node *p){
    while(p != NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
void segregate(struct node **head){
    struct node *lastnode = *head;
    struct node *curr = *head;
    struct node *prev = NULL;
    struct node *temp;

    while(lastnode->next != NULL){
        lastnode = lastnode->next;
    }
    struct node *finall = lastnode;
    while(curr != finall){
        if((curr->data)%2 != 0){
            temp = curr->next;
            lastnode->next = curr;
            lastnode = curr;
            lastnode->next = NULL;
            curr = temp;
            if(prev != NULL)
                prev->next = curr;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}

int main(){
    struct node *head = NULL;
   push(&head, 11);
    push(&head, 10);
    push(&head, 8);
    push(&head, 7);
    push(&head, 4);
    push(&head, 2);
    push(&head, 0);

    struct node *p = head;

    while(p != NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    segregate(&head);
    p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}
