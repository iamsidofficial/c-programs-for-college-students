#include<stdio.h>  
#include<stdlib.h>

struct LinkedList{
	int data;
	struct LinkedList *next;
}; 

typedef struct LinkedList *node;

node createNode(){
	node temp;
	temp = (node)malloc(sizeof(struct LinkedList));
	temp->next = NULL;
	return temp;
} 

node addNode(node head, int value){
	node temp,p;
	p = head;
	temp = createNode();
	temp->data = value;
	if(head == NULL){
		head = temp;
	}
	else{
		while(p->next != NULL){
		    p = p->next;
		}
		p->next = temp;
	}
	return head;
}

void printList(node);

int main() {
	node head = NULL;
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		int val;
		scanf("%d", &val);
		head = addNode(head, val);
	}
	printList(head);
	return 0;
}

void printList(node head){
	 node p;
   if (head == NULL) {
      printf("List is empty.\n");
      return;
   }
   printf("elements of list are : ");
   p = head;
   while (p != NULL) {
      printf("%d ", p->data);
      p = p->next;
   }
   printf("\n");
}