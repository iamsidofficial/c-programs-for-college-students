#include<stdio.h>
int stack[50],top,x,i,n;
char par[30];
void push(int );
void pop();
int c;
c=0;
int main()
 {
 top=-1;
 printf("Enter the paranthesized expression:");
 scanf("%s",&par);
 n=sizeof(par);
 for (int i=0;i<n;i++){
    if (par[i]=='('||par[i]=='['||par[i]=='{'){
        push(par[i]);
    }
    else if(par[i]==')'){
        if (stack[top]=='('){
            pop();
        }
        else{
            c=1;
            printf("Invalid");
            break;
        }

        }
    else if(par[i]=='}'){
        if (stack[top]=='{'){
            pop();
        }
         else{
            c=1;
            printf("Invalid");
            break;
        }
    }
    else if(par[i]==']'){
        if (stack[top]=='['){
            pop();
        }
        else{
            c=1;
            printf("Invalid");
            break;
        }
    }    
 }
 if(c==0){
    printf("Valid");
 }
 }
void push(int x){
  if (top>=n-1){
   printf("Stack is overflowed\n");
   }
  else{
   stack[++top]=x;
   }
 }
void pop()
  {
  if(top<=-1){
   printf("stack is underflown\n");
   }
  else{
   top--;
   }
}
