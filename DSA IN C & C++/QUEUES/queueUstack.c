#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*top1=NULL,*top2=NULL,*top3=NULL;

void push(struct node *p,int x){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("stack overflow\n");
    }
    else{
        t->data=x;
        t->next=p;
        p=t;
    }
}

int pop(struct node *p){
    if(p==NULL){
        printf("Empty\n");
        return -1;
    }
    else{
        int x=p->data;
        p=p->next;
        return x;
    }
}

void enqueue(int x){
    push(&top1,x);
    
}

int dequeue(){
    int x=-1;
    if(top2==NULL){
        if(top1==NULL){
            printf("Queue Empty\n");
        }
    }
    else{
        while(top1!=NULL){
            push(top2,pop(&top1));
        }
        return pop(&top2);
        
    }
}

// void display(){
//     struct node *t1=top1;
//     struct node *t2=top2;
//     struct node *t3=top3;
//     t3=(struct node*)malloc(sizeof(struct node));
//     while(top1=NULL){
//         push(&top3,pop(top1));
//     }
    
// }


int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);

    



return 0;

}