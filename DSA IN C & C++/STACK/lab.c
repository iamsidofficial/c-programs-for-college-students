#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
    struct node *next;
}*top=NULL;

void push(char s){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        return;
    }
    else{
        t->data=s;
        t->next=top;
        top=t;
    }
    }
char pop(){
    if(top==NULL){
        return '\0';
    }
    else{
        char c=top->data;
        top=top->next;
        return c;
    }
}    

int isOperand(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/'){
        return 0;
    }
    else{
        return 1;
    }
}

int prec(char c){
    if(c=='+' || c=='-'){
        return 1;
    }

    if(c=='*' || c=='/'){
        return 2;
    }

    return 0;

}

char* InfToPost(char *infix){
    int len=strlen(infix);
    char *postfix=(char*)malloc(sizeof(char)*(len+2));
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])==1){
            postfix[j++]=infix[i++];
        }
        else{
            if(prec(infix[i])>prec(top->data)){
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
    char *c="a+b*c-d/e";
    push(' ');
    char *postfix=InfToPost(c);
    printf("%s",postfix);
    



return 0;

}