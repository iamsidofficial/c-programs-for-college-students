#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char data;
    struct node *next;
}*top=NULL;

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

void push(char x){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        printf("stack overflow");
    }
    else{
        p->data=x;
        p->next=top;
        top=p;
    
    }
    
}

char pop(){
    if(top==NULL){
        return -1;
    }
    else{
      char x=top->data;
      top=top->next;
      return x;
    }
}

int isOperand(char s){
    if(s=='+' || s=='-' || s=='/' || s=='*'){
        return 0;
    }
    else{
        return 1;
    }
}

int prec(char s){
    if(s=='+' || s=='-'){
        return 1;
    }
    else if(s=='*' || s=='/'){
        return 2;
    }
    return 0;
}

char* IntoPost(char *infix){
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char*)malloc(sizeof(char)*(len+2));

    while(infix[i]!='\0'){
        if(isOperand(infix[i])==1){
            postfix[j++]=infix[i++];
        }
        else{
            if(prec(infix[i])> prec(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++]=pop();
            }
        }

    }
    while(top!=NULL){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;

}



int main(){
    char *infix="a+b*c-d-e/f+g";
    push(' ');
    
    char *postfix=IntoPost(infix);
    
    printf("%s ",postfix);
    



return 0;

}