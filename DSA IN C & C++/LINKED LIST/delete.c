1`Q#include <stdio.h>
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

int delete(struct node *p,int index){
    struct node *q;
    int x=-1;
    if(index <1 || index>count(p)){
        return -1;
    }
    else{
        if(index==1){
            q=first;
            x=first->data;
            first=first->next;
            return x;
        }
        else{
            p=first;
            q=NULL;
            for(int i=1;i<index;i++){
                q=p;
                p=p->next;
            }
            x=p->data;
            q->next=p->next;
            return x;
            
            
        }
    }
}
    
int main(){
    int A[5]={21,43,54,23,76};
    create(A,5);
    display(first);
    int h;
    h=delete(first,4);
    display(first);
    printf("%d \n",h);

    




return 0;

}