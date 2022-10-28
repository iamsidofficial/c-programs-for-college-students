#include <stdio.h>
#include <stdlib.h>
struct node{
   int data;
   struct node*left;
   struct node *right;
};

struct node* insertNode(struct node*root,int key){
	struct node *t=root,*r;//r:tail pointer
	if(root==NULL){

		struct node* p=(struct node *)malloc(sizeof(struct node));
		p->data=key;
		p->left=p->right=NULL;
		root=p;
	}
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

struct node * createNode(int value){
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=value;
	t->left=NULL;
	t->right=NULL;
	return t;
}

int Height(struct node *p){
	if(p==NULL){
		return 0;
	}

	int x=Height(p->left);
	int y=Height(p->right);
	if(x>y){
		return x+1;
	}
	else{
		return y+1;
	}
}

struct node* InPre(struct node* p){
	while(p && p->right!=NULL){
		p=p->right;
	}
	return p;
}

struct node* InSucc(struct node* p){
	while(p && p->left!=NULL){
		p=p->left;
	}
	return p;
}

struct node * Delete(struct node *p,int key){
	if(p==NULL){
		return NULL;
	}

	if(p->left==NULL && p->right==NULL){
		
		free(p);
		return NULL;
	}
	
	if(key<p->data){
		p->left=Delete(p->left,key);
	}
	else if(key>p->data){
		p->right=Delete(p->right,key);
	}
	else{
		if(Height(p->left)>Height(p->right)){
			struct node *q;
			q=InPre(p->left);
			p->data=q->data;
			p->left=Delete(p->left,q->data);
		}
		else{
			struct node *q;
			q=InPre(p->right);
			p->data=q->data;
			p->left=Delete(p->right,q->data);

		}

	}
	return p;
}


int main(){
	struct node *p = createNode(25);
	insertNode(p,20);
	insertNode(p,40);
	insertNode(p,10);
	insertNode(p,25);
	insertNode(p,35);
	insertNode(p,45);
	insertNode(p,42);
	insertNode(p,43);
	Delete(p,42);


	struct node *t=Isearch(p,42);
	if(t!=NULL){
		printf("%d FOUND \n",t->data);
	}
	else{
		printf("NOT FOUND \n");
	}





	return 0;
}


cd Desktop
mkdir IEC2021005
cd IEC2021005
touch 1.c
cd 1.c
