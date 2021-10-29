#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};
 

struct node* last = NULL;

void insertAtFront()
{
 
    int data;
 

    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
 
    printf("\nEnter data to be "
           "inserted: \n");
    scanf("%d", &data);
 
    if (last == NULL) {
        temp->info = data;
        temp->next = temp;
        last = temp;
    }
 

    else {
        temp->info = data;
        temp->next = last->next;

        last->next = temp;
    }
}

void viewList()
{

    if (last == NULL)
        printf("\nList is empty\n");
 

    else {
        struct node* temp;
        temp = last->next;
 
        do {
            printf("\nData = %d", temp->info);
            temp = temp->next;
        } while (temp != last->next);
    }
}

int main()
{
    // Function Call
    insertAtFront();
    insertAtFront();
    insertAtFront();
 

    viewList();
 
    return 0;
}
