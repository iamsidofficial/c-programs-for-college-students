#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
    struct node *next;
}*top=NULL;

void push(int x){
    struct node *t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL){
        printf("stack overflow\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    if(top==NULL){
        printf("Empty\n");
        return -1;
    }
    else{
        int x=top->data;
        top=top->next;
        return x;
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
    
    char *postfix=InfToPost(infix);
    printf("%s",postfix);


return 0;

}