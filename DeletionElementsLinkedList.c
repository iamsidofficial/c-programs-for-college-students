//Q. Delete the head node of a given linked list
//eg : before deletion : 2 5 8 9 7
//eg : after deletion : 5 8 9 7





#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * deletionElements(struct Node * head){
    head = head->next;
    return(head);
    }

void llTraversal(struct Node * head){
    while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main(){
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Linked list before deletion : \n");
    llTraversal(head);

    printf("linked list after deletion is : \n");
    head = deletionElements(head);
    llTraversal(head);

    return 0;
}