#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *newNode(int key)
{
    struct node *temp = new struct node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
void removeloop(struct node *loopnode, struct node *head){
    struct node *ptr1;
    struct node *ptr2;

    ptr1 = head;

    while(1){
        ptr2 = loopnode;

        while(ptr2->next != loopnode && ptr2->next != ptr1)
            ptr2 = ptr2->next;

        if(ptr2->next == ptr1)
            break;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
}
void DetectandRemove(struct node *head){
    if(head == NULL)
        return;
    struct node *slowptr=head,*fastptr = head;

    while(slowptr != NULL && fastptr != NULL && fastptr->next != NULL){
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;

        if(fastptr == slowptr){
            removeloop(slowptr, head);
            break;
        }
    }
}
int main(){
    struct node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    head->next->next->next->next->next = head->next;

    DetectandRemove(head);

    printList(head);
}
