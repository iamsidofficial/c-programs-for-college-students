#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=NULL;

void push(int x){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("STACK OVERFLOW \n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
void display(){
    if(top==NULL){
        printf("Stack Empty\n");
    }
    else{
        struct node *p=top;
        while(p!=NULL){
            printf("%d \n",p->data);
            p=p->next;
        }

    }
}
void pop(){
    if(top==NULL){
        return;
    }
    else{
        struct node *p=top;
        top=top->next;
        int x=p->data;
        free(p);
    }
}

int peek(int pos){
    struct node *p=top;
    for(int i=0;i<pos-1 && p!=NULL;i++){
        p=p->next;
    }
    if(p!=NULL){
        return p->data;
    }
    else{
        return -1;
    }
}



int main(){
    push(1);
    push(2);
    push(9);
    push(10);
    push(21);
    push(93);
    display();
    printf("_________________________\n");
    pop();
    display();
    printf("_________________________\n");
    int h=peek(2);
    printf("%d \n",h);

    



return 0;

}