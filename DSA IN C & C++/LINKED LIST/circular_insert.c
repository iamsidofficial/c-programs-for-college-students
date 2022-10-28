#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL;

void create(int A[],int n){
    struct node *t,*last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct node *p){
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}

void insert(struct node *p,int pos,int x){
    if(pos==0){
        struct node *t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        while(p->next!=head){
            p=p->next;

        }
        p->next=t;
        t->next=head;
    }
    else{
         struct node *t=(struct node*)malloc(sizeof(struct node));
         for(int i=0;i<pos-1;i++){
             p=p->next;
             t->data=x;
             t->next=p->next;
             p->next=t;

         }

    }

}
int main(){
    int A[5]={1,2,3,4,5};
    create(A,5);
    display(head);
    insert(head,2,100);
    display(head);
    



return 0;

}