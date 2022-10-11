#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

int main()
{
    int length, i;
    printf("Enter size of the list : ");
    scanf("%d", &length);
      struct node *headNode, *currentNode, *temp;

    
    for (i = 0; i < length; i++)
    {
       
        currentNode = (node *)malloc(sizeof(node));

       
        printf("Enter element %d : ", (i + 1));
        scanf("%d", &currentNode->value);

       
        if (i == 0)
        {
            headNode = temp = currentNode;
     
        }
        else
        {
        
            temp->next = currentNode;
            temp = currentNode;
        }
    }

    
    temp->next = NULL;
    temp = headNode;
    printf("Iterating through the elements of the linked list : \n");
    while (temp != NULL)
    {
        
        printf("%d \n", temp->value);
        temp = temp->next;
    }
}
