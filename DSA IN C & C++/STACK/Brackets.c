#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
}*top=NULL;

void push(char c){
    struct node *t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL){
        printf("Stack Overflow\n");
    }
    else{
        t->data=c;
        t->next=top;
        top=t;
    }
}

char pop(){
    if(top==NULL){
        return '\0';
    }
    else{
        char x=top->data;
        top=top->next;
        return x;
    }
}

int Para(char *c){
    int i=0;
    while(c[i]!='\0'){
        if(c[i]=='(' || c[i]=='{' || c[i]=='['){
            push(c[i]);
        }
        if(c[i]==')' && top->data=='(' ||c[i]=='}' && top->data=='{' ||c[i]==']' && top->data=='[' ){
            if(top!=NULL){
                pop();
            }
            else{
                return 0;
                break;
            } 
        }
        i++;
    }
    if(top!=NULL){
        return 0;
    }
    if(top==NULL){
        return 1;
    }
}




int main(){
    char *c="{a+[b+c]+d}";
    int h=Para(c);
    if(h==1){
        printf("Balanced\n");
    }
    if(h==0){
        printf("Unbalanced\n");
    }



return 0;

}