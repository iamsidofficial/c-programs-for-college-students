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
        t->next=NULL;
        t->data=A[i];
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

void Rdisplay(struct node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        Rdisplay(p->next);
        

    }
}

int main(){
    struct node *p;
    int A[5]={1,3,5,9,10};
    create(A,5);
    display(first);
    Rdisplay(first);





    return 0;
}