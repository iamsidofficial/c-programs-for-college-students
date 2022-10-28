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

int count(struct node *p){
    int ct=0;
    while(p!=NULL){
        ct++;
        p=p->next;
    }
    return ct;
}

void removeD(struct node *p){
    struct node *q;
    q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q->next;
            q=q->next;

        }
        else{
            p->next=q->next;
            q=p->next;
        }
        
    }
   

}
    
int main(){
    int A[6]={21,27,54,54,54,76};
    create(A,6);
    display(first);
    removeD(first);
    display(first);
    

    




return 0;

}