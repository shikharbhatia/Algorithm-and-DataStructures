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
int getCount(struct node *head){
    if(head == NULL)
        return 0;
    return(1+getCount(head->next));
}
int nthnodefromback(struct node *head, int n){
    int k = getCount(head);

    int c = k-n+1;

    for(int i = 1; i < c; i++){
        head = head->next;
    }
    return head->data;
}
int nthInOnePass(struct node *head, int n){
    struct node *ptr1 = head, *ptr2=head;
    int i;

    for(i = 0; i < n; i++){
        ptr1 = ptr1->next;
    }
    while(ptr1  != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr2->data;

}
int main(){
    struct node *head = NULL;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    push(&head, 0);

    cout<<nthnodefromback(head, 2)<<endl;
    cout<<nthInOnePass(head, 2)<<endl;

    return 0;
}
