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
void splitAlternate(struct node *head, struct node **a, struct node **b){
    bool flag;
    flag = 0;
    struct node *curr = head;
    struct node *x = curr,*xhead = curr;
    struct node *y, *yhead;
    if(curr->next){
        y = curr->next;
        yhead = y;
    }
    else
        return;

    curr = curr->next->next;

    while(curr != NULL){
        if(flag == 0){
            (x)->next = curr;
            (x)=curr;
        }
        else if(flag == 1){
            (y)->next = curr;
            (y) = curr;
        }
        curr = curr->next;
        flag = !flag;
    }
    (x)->next = NULL;
    (y)->next = NULL;

    *a = xhead;
    *b = yhead;
}
void printList(struct node *p){
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main(){
    struct node *head = NULL;
    struct node *a = NULL;
    struct node *b = NULL;

    push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);
  push(&head, 0);
    printList(head);
    cout<<endl;

    splitAlternate(head, &a, &b);

  //  printList(head);
   // cout<<endl;
    printList(a);
    cout<<endl;
    printList(b);
    return 0;
}
