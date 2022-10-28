#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL;

void create(int A[],int n){
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int sum(struct node *p){
    int s=0;
    while(p!=NULL){
        s=s+p->data;
        p=p->next;
    }
    return s;

}
void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int Rsum(struct node *p){
    if(p==NULL){
        return 0;

    }
    else{
        
        return Rsum(p->next)+p->data;
    }
}
int main(){
     int A[5]={21,43,54,23,76};
    create(A,5);
    display(first);
    printf("%d\n",sum(first));
    printf("%d\n",Rsum(first));


    



return 0;

}