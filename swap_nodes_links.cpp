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
void swapnodes(struct node **head, int x, int y){
    struct node *prevX, *prevY, *currX, *currY, *temp;

    currX = *head;
    currY = *head;

    prevY = NULL;
    prevX = NULL;

    while(currX != NULL && currX->data != x){
        prevX = currX;
        currX = currX->next;
    }

    while(currY != NULL && currY->data != y){
        prevY = currY;
        currY = currY->next;
    }
    if(currY==NULL || currX==NULL){
        return;
    }
     if (prevX != NULL)
       prevX->next = currY;
   else
        *head = currY;

   if (prevY != NULL)
       prevY->next = currX;
   else
       *head = currX;

    temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

}
void printList(struct node *p){
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
    push(&head, 5);

    swapnodes(&head,3,4);

    printList(head);

    return 0;
}
