#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};
int getCount(struct node *head){
    if(head == NULL)
        return 0;
    return(1 + getCount(head->next));
}
int utility(struct node *head1, struct node *head2,int d){
    int i;
    struct node *curr1 = head1, *curr2=head2;

    for(i = 0; i < d; i++){
        if(curr1){
        curr1 = curr1->next;
        }
        else
            return -1;
    }
    while(curr1 && curr2){
        if(curr1 == curr2){
            return curr1->data;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}
int getIntersection(struct node *head1, struct node *head2){
    int c1 = getCount(head1);
    int c2 = getCount(head2);

    int d = abs(c1-c2);
    if(c1 > c2){
        return utility(head1, head2, d);
    }
    else
        return utility(head2, head1, d);
}
int main()
{
    struct node* newNode;
    struct node* head1 =
        (struct node*) malloc(sizeof(struct node));
    head1->data  = 10;

    struct node* head2 =
        (struct node*) malloc(sizeof(struct node));
    head2->data  = 3;

    newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = 6;
    head2->next = newNode;

    newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next  = newNode;

    newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = 30;
    head1->next->next= newNode;

    head1->next->next->next = NULL;

    cout<<getIntersection(head1, head2);

    return 0;
}
