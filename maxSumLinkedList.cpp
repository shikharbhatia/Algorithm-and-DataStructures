#include<iostream>
using namespace std;

//A linked list node
struct node
{
    int data; //data belong to that node
    node *next; //next pointer
};

// Push the data to the head of the linked list
void push(node **head, int data)
{
    //Alocation memory to the new node
    node *newnode = new node;

    //Assigning data to the new node
    newnode->data = data;

    //Adjusting next pointer of the new node
    newnode->next = *head;

    //New node becomes the head of the list
    *head = newnode;
}
void finalMaxSumList(struct node *a, struct node *b){
    struct node *curr1 = a;
    struct node *curr2 = b;
    struct node *prev1 = a;
    struct node *prev2 = b;

    struct node *result = NULL;

    while(curr1 != NULL && curr2 != NULL){
        int sum1 = 0;
        int sum2 = 0;
        while(curr1 != NULL && curr2 != NULL && curr1->data != curr2->data){
            if(curr1->data < curr2->data){
                sum1 += curr1->data;
                curr1 = curr1->next;
            }
            else{
                sum2 += curr2->data;
                curr2 = curr2->next;
            }
        if(curr1 == NULL){
            while(curr2 != NULL){
                sum2 += curr2->data;
                curr2 = curr2->next;
            }
        }
        if(curr2 == NULL){
            while(curr1 != NULL){
                sum1 += curr1->data;
                curr1 = curr1->next;
            }
        }
        if(prev1 == a && prev2 == b){
            if(sum1 > sum2){
                result = a;
            }
            else{
                result = b;
            }
        }
        else{
            if(sum1>sum2){
                prev2->next = prev1->next;
            }
            else{
                prev1->next = prev2->next;
            }
        }
        prev1 = curr1;
        prev2 = curr2;

        if(curr1)
            curr1=curr1->next;
        if(curr2)
            curr2=curr2->next;
        }
    }
    while(result != NULL){
        cout<<result->data<<" ";
        result = result->next;
    }
}
int main()
{
    //Linked List 1 : 1->3->30->90->110->120->NULL
    //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
    node *head1 = NULL, *head2 = NULL;
    push(&head1, 120);
    push(&head1, 110);
    push(&head1, 90);
    push(&head1, 30);
    push(&head1, 3);
    push(&head1, 1);

    push(&head2, 130);
    push(&head2, 120);
    push(&head2, 100);
    push(&head2, 90);
    push(&head2, 32);
    push(&head2, 12);
    push(&head2, 3);
    push(&head2, 0);

    finalMaxSumList(head1, head2);
    return 0;
}
