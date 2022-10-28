#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL){
        printf("Queue is full\n");
    }
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
           rear->next=t;
           rear=t;
        }
    }
}

int dequeue(){
    int x=-1;
    struct node* t;
 
 if(front==NULL){
    printf("Queue is Empty\n");
    return -1;
 }
    
    else
    {
    x=front->data;
    t=front;
    front=front->next;
    free(t);
    }
    return x;
}


visited[7][7]={0,0,0,0,0,0,0};
void BFS(int i){
    int u;
    printf("%d ",i);
    visited[i]=1;
    enqueue(i);
    while(){
        u=dequeue();
        for(int v=1;v<=n;v++){
            if(visited[v]==0 && A[u][v]==1){
                printf("%d",v);
                enqueue(v);
                visited[v]=1;
            }
        }
    }
}


int main(){

}