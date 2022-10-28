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

void delete(struct node *p,int pos){
    if(pos==1){
        p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        if(p==head){
            head=NULL;
        }
        else{
             p->next=head->next;
             free(head);
             head=p->next;//new head
        }
       
    }

    else{
        struct node*q;
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        free(q);
    }
}
    
int main(){
    int A[5]={1,2,3,4,5};
    create(A,5);
    display(head);
    delete(head,2);
    display(head);
    



return 0;

}