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

void reverse(struct node *p,int n){
    p=first;
    struct node*temp=NULL;
    while(p!=NULL){
        
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p->next==NULL){
            first=p;
        }

    }
    int A[n];
    int i=0;
    while(p!=NULL){
        A[i]=p->data;
        p=p->next;
        i++;
    }
    i--;
    p=first;
    while(p!=NULL){
        p->data=A[i--];
        p=p->next;
    }
    
}


int main(){
    int A[5]={1,2,3,4,5};
    create(A,5);
    display(first);
    reverse(first,5);
    display(first);
    



return 0;

}