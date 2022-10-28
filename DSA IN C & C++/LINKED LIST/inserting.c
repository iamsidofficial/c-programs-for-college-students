#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
}*rear=NULL,*front=NULL;

void enqueue(int x){
    struct node*t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
    if(t==NULL){
		printf("Queue full\n");
	}
    
	else{
		
		if(front==NULL){
			front=rear=t;
		}
		else{
			
			rear->next=t;
            t->next=NULL;
			rear=t;
		}

	}
}


int Dequeue(){
	if(front==NULL){
		printf("Queue Empty\n");
		return -1;
	}
	else{
		
		struct node*t;
		int x=front->data;
		front=front->next;
        return x;
	}
}

int isEmpty(){
	if(front==NULL){
		return 0;
	}
	else{
		return 1;
	}
}

void display(){
	struct node*t=front;
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;
	}
    printf("\n");
}

int A[7][7]={   {0,0,0,0,0,0,0},
                {1,0,1,0,0,0,0},
                {1,1,0,1,1,0,0},
                {1,0,1,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}
            };

int visited[7]={0,0,0,0,0,0,0};
void BFS(int i){
    printf("%d ",i);
    visited[i]=1;
    enqueue(i);
    int u;
    while(front!=NULL){
        u=Dequeue();
        for(int v=1;v<=6;v++){
            if(A[u][v]==1&&visited[v]==0){
                printf("%d ",v);
                visited[v]=1;
                enqueue(v);
            }
        }
    }
}            

int main(){
	   BFS(2);
       // enqueue(21);
       // enqueue(32);
       // display();
       // printf("%d ",Dequeue())   ;
	return 0;
}