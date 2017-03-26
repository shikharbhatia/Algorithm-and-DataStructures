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
void deletenodes(struct node *head, int m, int n){
    if(head == NULL)
        return;
    struct node *x = head;
    while(x != NULL){
        int i;
        struct node *t = x;
        struct node *p, *temp;
        for(i = 1; i < m; i++){
            if(t != NULL)
                t = t->next;
        }
        if(t->next != NULL)
            p = t->next;
        for(i = 0; i < n; i++){
            temp = p;
            p = p->next;
            free(temp);
        }
        t->next = p;
        x = p;
    }
}
int main(){
    struct node* head = NULL;

    int M=1, N=1;

 push(&head,43);
push(&head,67);
push(&head,33);
push(&head,91);
push(&head,1);

    deletenodes(head, M,N);

    printList(head);

    return 0;
}
