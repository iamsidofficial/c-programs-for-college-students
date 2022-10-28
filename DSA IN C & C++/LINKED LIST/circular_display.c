#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *head=NULL;

void create(int A[],int n){
    struct node*t,*last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;;
        
    }

    

}
void display(struct node *p){
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
}

int main(){
    int A[5]={12,23,25,6,5};
    create(A,5);

    display(head);



return 0;

}