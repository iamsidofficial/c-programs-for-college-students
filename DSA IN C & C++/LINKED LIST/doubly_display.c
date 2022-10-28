#include <stdio.h>
#include <stdlib.h>
//Q. Please write functions for STACK operations (push, pop and top) using doubly linked list.
struct node {
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

void create(int A[],int n){
    struct node*t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->prev=last;
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}


int main(){
    int A[5]={1,2,3,4,5};
    create(A,5);
    display(first);
    



return 0;

}