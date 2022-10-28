#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL;


void create(int A[],int n){
    struct node*t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

void display(struct node*p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int pal(struct node *p,int n){
    int A[n];
    int i=0;
    while(p!=NULL){
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;
    int B[n];
    int j=0;
    for(int j=0;j<n;j++){
        B[j]=A[i];
        i--;
    }
    int x=1;
    for(int i=0;i<n;i++){
        if(A[i]!=B[i]){
            x=0;
            break;

        }
    }
    return x;


}


int main(){
    int A[4]={1,2,2,1};
    create(A,4);
    int h=pal(first,4);
    display(first);
    if(h==0){
        printf("Not a palindrome");
    }
    if(h==1){
        printf("Palindrome");
    }



return 0;

}