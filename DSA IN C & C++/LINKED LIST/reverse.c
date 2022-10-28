#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void reverse(struct node *p,int n){
    int A[n];
    int i=0;
    while(p!=NULL){
        A[i]=p->data;
        i++;
        p=p->next;

    }
    p=first;
    i--;
    while(p!=NULL){
        p->data=A[i--];
        p=p->next;
    }
}
    
int main(){
    int A[5]={21,43,54,23,76};
    create(A,5);
    display(first);
    reverse(first,5);
    display(first);
    

    




return 0;

}