#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;

}*first=NULL;

void create(int A[],int n){
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}
void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int search(struct node *p,int key){ 
    while(p!=NULL){
        if (p->data==key)
        { 
            return 1;
        }
        p=p->next; 
    }
    return 0;
}

int Rsearch(struct node *p,int key){
    
    if(p->data==key){
        return 1;
    }
    else if(p->next==NULL && p->data!=key){
        return 0;
    }
     else{
       Rsearch(p->next,key);
    }

}



int main(){
    int A[5]={21,43,54,23,76};
    create(A,5);
    display(first);
    int x;
    scanf("%d",&x);
    if(search(first,x)==1){
        printf("PRESENT\n");
    }
    if(search(first,x)==0){
        printf("NOT PRESENT\n");
    }
    int y;
    scanf("%d",&y);
    if(Rsearch(first,y)==1){
        printf("PRESENT\n");
    }
    if(Rsearch(first,y)==0){
        printf("NOT PRESENT\n");
    }
   
    



return 0;

}