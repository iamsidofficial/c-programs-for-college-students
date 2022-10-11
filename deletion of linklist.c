// #include<stdio.h>
// int main()
// {
//     int i;
//     int a[5];
//     printf("Enter elements of array");
//     for(i=0;i<6;i++)
//     {
//     scanf("%d",&a[i]);
//        if( a[0]<a[i])
//        a[0]=a[i];
//     }
//     printf("largest element = %d",a[i]);
//     return 0;

// }

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;          
    struct node *next;  
}*head;


void createList(int n);
void deleteNodeAtBeginning(int position);
void deleteNodeAtEnd(int position);
void deleteNodeAtMiddle( int position);
void displayList();


int main()
{
    int n,position;

   
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("Enter the position where you want to delete ");
    scanf("%d",&position);
    if(position<1 || position>n)
    printf("Invalid Input");
    else if(position==1)
    {

    deleteNodeAtBeginning(position);
    printf("\nData in the list \n");
    displayList();
}
else if( position==n)
    {

    deleteNodeAtEnd(position);

    printf("\nData in the list \n");
    displayList();
}
else
{

    deleteNodeAtMiddle(position);

    printf("\nData in the list \n");
    displayList();
    return 0;
}
}


void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
       
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

           
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;
               
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}



void deleteNodeAtBeginning(int position)
{
    struct node *temp;

    temp=head;
head=temp->next;
free(temp);      
printf("DATA DELETED SUCCESSFULLY\n");
   
}

void deleteNodeAtEnd(int position)
{
    struct node  *temp,*prevnode;
     temp = head;
       while(temp->next != NULL)
            {
prevnode=temp;
            temp=temp->next;
        }
            if(temp==head)
            {
            head=0;
            free(temp);
}
else

{
prevnode->next=0;
free(temp);
}
        printf("DATA DELETED SUCCESSFULLY\n");
    }


void deleteNodeAtMiddle(int position)
{
    int i=1;
    struct node *nextnode, *temp;
        temp=head;
        while(i<position-1)
        {
        temp=temp->next;
        i++;
}
nextnode=temp->next;
temp->next=nextnode->next;
free(nextnode);
        printf("DATA DELETED SUCCESSFULLY\n");
       
       
   
}

void displayList()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;                
        }
    }
}