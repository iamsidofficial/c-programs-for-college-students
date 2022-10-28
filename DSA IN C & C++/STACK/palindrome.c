#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

struct node{
    char data;
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
char pop(){
    if(top==NULL){
        return ' ';
    }
    else{
        struct node *p=top;
        top=top->next;
        char x=p->data;
        free(p);
        return x;
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
int isPal(char *c){
    for(int i=0;i<strlen(c);i++){
        push(c[i]);
    }
    for(int i=0;i<strlen(c);i++){
        if(c[i]!=pop()){
            return 0;
            break;
        }
    }
    return 1;

}


int main(){
   char *c="abba";
   int h=isPal(c);
   if(h==0){
       printf("not a palindrome\n");
   }

   if(h==1){
       printf("is Palindrome\n");
   }

    



return 0;

}