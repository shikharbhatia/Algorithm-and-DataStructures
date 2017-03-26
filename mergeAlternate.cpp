#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};
void push(struct node ** head_ref, int new_data)
{
    struct node* new_node =
           (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void gfgmerge(struct node *p, struct node **q)
{
     struct node *p_curr = p, *q_curr = *q;
     struct node *p_next, *q_next;

     // While therre are avialable positions in p
     while (p_curr != NULL && q_curr != NULL)
     {
         // Save next pointers
         p_next = p_curr->next;
         q_next = q_curr->next;

         // Make q_curr as next of p_curr
         q_curr->next = p_next;  // Change next pointer of q_curr
         p_curr->next = q_curr;  // Change next pointer of p_curr

         // Update current pointers for next iteration
         p_curr = p_next;
         q_curr = q_next;
    }

    *q = q_curr; // Update head pointer of second list
}
struct node *merger(struct node *a, struct node *b, bool flag){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    struct node *result;

    if(flag == 0){
        result = a;
        result->next = merger(a->next, b, 1);void push(struct node ** head_ref, int new_data)
{
    struct node* new_node =
           (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}
    }
    else{
        result = b;
        result->next = merger(a, b->next, 0);
    }
    return result;
}
int main(){
    struct node *p = NULL, *q = NULL;

    push(&p, 3);
    push(&p, 2);
    push(&p, 1);
    printf("First Linked List:\n");
    printList(p);

    push(&q, 8);
    push(&q, 7);
    push(&q, 6);
    push(&q, 5);
    push(&q, 4);
    printf("Second Linked List:\n");
    printList(q);

    p = merger(p, q, 0);

    cout<<endl;
    printList(p);
    cout<<endl;
    printList(q);

    return 0;
}
