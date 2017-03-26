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
        p = p->next;
    }
}
struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node* result = NULL;

  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);

  /* Pick either a or b, and recur */
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}
void partition(struct node *head, struct node **af, struct node **bf){


    if(head == NULL || head->next == NULL){
        *af = head;
        *bf = NULL;
    }
    else{
        struct node *slowptr = head;
        struct node *fastptr = head->next;

        while(fastptr != NULL){
            fastptr = fastptr->next;
            if(fastptr!= NULL){
            fastptr = fastptr->next;
            slowptr = slowptr->next;}
        }

    *af = head;
    *bf = slowptr->next;
    slowptr->next = NULL;
    }
}
void mergesort(struct node **t){
    struct node *head = *t;
    struct node *a,*b;

    if(head == NULL || head->next == NULL)
        return;

    partition(head, &a, &b);

    mergesort(&a);
    mergesort(&b);

    *t = SortedMerge(a,b);
}
int main(){
    struct node *a = NULL;

    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    mergesort(&a);

    printList(a);

    return 0;
}
