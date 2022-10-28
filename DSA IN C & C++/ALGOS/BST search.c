#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* createNode(int data){
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

struct node * Rsearch(struct node *t,int key){
	if(t->data==key){
		return t;
		printf("Found:%d",key);
	}
	
	else if(t->data>key){
		return Rsearch(t->left,key);
	}
	else{
		return Rsearch(t->right,key);
	}
	return NULL;
}

struct node* Isearch(struct node *t,int key){
	while(t!=NULL){
		if(t->data==key){
			return t;
		}
		else if(key<t->data){
			t=t->left;
		}
		else{
			t=t->right;
		}


	}
	return NULL;
}


int main(){
	struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
	p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    struct node* n = Rsearch(p, 6);
    if(n!=NULL){
    printf("Found: %d \n", n->data);
    }
    else{
        printf("Element not found");
    }
    
    struct node* n1 = Isearch(p, 9);
    if(n1!=NULL){
    printf("Found: %d \n", n1->data);
    }
    else{
        printf("Element not found");
    }




	return 0;
}
