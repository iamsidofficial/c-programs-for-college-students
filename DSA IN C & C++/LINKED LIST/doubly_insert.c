#include <stdio.h>
#include <stdlib.h>

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
    printf("\n");
}

void insert(struct node *p,int pos,int x){
    struct node *t=(struct node *)malloc(sizeof(struct node));
    if(pos==1){
        p=first;
        t->data=x;
        t->next=p;
        p->prev=t;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
          
        }
        t->data=x;
        t->next=p->next;
        t->prev=p;
        if(p->next!=NULL){
            p->next->prev=t;
        }
        p->next=t;
    }
}


int main(){
    int A[5]={1,2,3,4,5};
    create(A,5);
    display(first);
    insert(first,2,100);
    display(first);
    



return 0;

}