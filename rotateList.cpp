#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};

void rotateList(struct node **head, int k){
    int i = 0;
    struct node *p = *head;
    for(i = 0; i < k-1; i++){
        p = p->next;
    }
    struct node *temp = p->next;
    p->next = NULL;

    struct node *t = temp;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = *head;
    *head = temp;
}
void push(struct node **head, int val){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main(){
    struct node *head = NULL;

    for(int i = 60; i > 0; i=i-10){
        push(&head, i);
    }
    int k = 4;
     printList(head);
     cout<<endl;
    rotateList(&head, k);
     printList(head);

     return 0;
}
