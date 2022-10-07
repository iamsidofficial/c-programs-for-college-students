//Q. adding the element to the head node of a given linked list
//eg : before deletion : 2 5 8 9 7
//eg : after deletion : 10 2 5 8 9 7



#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * addingElements(struct Node * head, int ele){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr->next = p;
    ptr->data = ele;
    head = ptr;
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

    int ele;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Enter the element : ");
    scanf("%d", &ele);

    printf("Linked list before insertion : \n");
    llTraversal(head);

    printf("linked list after insertion is : \n");
    head = addingElements(head, ele);
    llTraversal(head);

    return 0;
}