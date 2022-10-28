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

int check(struct node *p){
    int y=INT_MIN;
    while(p!=NULL){
        if(p->data>y){
            y=p->data;
            p=p->next;
        }
        else{
            return 0;
        }
    }
    return 1;

}

    
int main(){
    int A[5]={21,43,54,59,76};
    create(A,5);
    display(first);
    int u=check(first);
    if(u==0){
        printf("NO\n");
    }
    else if(u==1){
        printf("YES\n");
    }




return 0;

}