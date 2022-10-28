#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node * createNode(int value){
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=value;
	t->left=NULL;
	t->right=NULL;
	return t;
}

struct node* insertNode(struct node*root,int key){
	struct node *t=root,*r;//r:tail pointer
	while(t!=NULL){
		r=t;
		if(t->data==key){
			return NULL;
		}
		else if(t->data>key){
			t=t->left;
		}
		else{
			t=t->right;
		}
	}

	struct node* p=(struct node *)malloc(sizeof(struct node));
	p->data=key;
	p->left=p->right=NULL;
	if(p->data<r->data){
		r->left=p;
	}
	else{
		r->right=p;
	}
}
struct node* Rinsert(struct node* root,int key){
	struct node *t;
	if(root==NULL){
		t->data=key;
		t->left=t->right=NULL;
		return t;
	}
	else if(key<root->data){
		root->left=Rinsert(root->left,key);
	}
	else{
		root->right=Rinsert(root->right,key);
	}
	return t;
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
    
    insertNode(p,10);
     struct node* n1 = Isearch(p, 9);
    if(n1!=NULL){
    printf("Found: %d \n", n1->data);
    }
    else{
        printf("Element not found");
    }
    Rinsert(p,123);
    struct node* n2 = Isearch(p, 9);
    if(n2!=NULL){
    printf("Found: %d \n", n2->data);
    }
    else{
        printf("Element not found");
    }




	return 0;
}