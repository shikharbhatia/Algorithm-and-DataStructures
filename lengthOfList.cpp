#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *next;
};
void push(struct node **head, int val){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}
int length(struct node *temp){
    if(temp == NULL)
        return 0;
    return(1 + length(temp->next));
}
int leng(struct node *temp){
    int c = 0;

    while(temp != NULL){
        temp=temp->next;
        c++;
    }
    return c;
}
int main(){
    struct node *head = NULL;

    push(&head, 0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 0);

    cout<<length(head)<<endl;
    cout<<leng(head)<<endl;
}
