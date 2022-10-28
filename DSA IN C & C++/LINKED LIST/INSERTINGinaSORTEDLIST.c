#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL;

void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


void create(int A[],int n){
    struct node *t,*last;
    first=(struct  node*)malloc(sizeof(struct  node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}
void insert(struct node *p,int x){
    struct node *q,*t;
    while(p->data<x){
        q=p;
        p=p->next;   
    }
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    q->next=t;
    t->next=p;

}

int main(){
    int A[5]={21,43,54,59,76};
    create(A,5);
    display(first);
    insert(first,27);
    display(first);
    




return 0;

}