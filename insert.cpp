#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};
void agae(struct node **head, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;

    return;
}
void peeche(struct node **head, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    struct node *p = *head;

    if(*head == NULL){
        *head = temp;
        return;
    }
    while(p->next != NULL)
        p = p->next;

    p->next = temp;
}
void middle(struct node *prev, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;

    temp->next = prev->next;
    prev->next = temp;

    return;
}
void printList(struct node *node){
  while (node != NULL)
  {
     cout<<node->data;
     node = node->next;
  }
}
int main(){
    struct node *head = NULL;

    peeche(&head, 1);
    peeche(&head, 2);
    peeche(&head, 3);
    agae(&head, 0);
    middle(head->next->next, 4);

    printList(head);

    return 0;

}
