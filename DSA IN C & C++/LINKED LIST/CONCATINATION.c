#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int data;
    struct node *next;
}*first=NULL,*second=NULL;

void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void create1(int A[],int n){
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

void create2(int A[],int n){
    struct node *t,*last;
    second=(struct  node*)malloc(sizeof(struct  node));
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

void concatenate(struct node *p,struct node *q){
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}

    
int main(){
    int A[5]={21,43,54,23,76};
    create1(A,5);
    int B[5]={32,43,55,21,75};
    create2(B,5);
    display(first);
    display(second);
    concatenate(first,second);
    display(first);
    

    




return 0;

}