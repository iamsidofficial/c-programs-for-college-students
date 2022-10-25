#include <stdio.h>
#include <stdlib.h>
#define size 6
int queue[size];
int front = -1;
int rear = -1;
void enqueue(int element)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % size == front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = element;
    }
}

void dequeue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe dequeued element is %d", queue[front]);
        front = (front + 1) %size;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\nElements in a Queue are :");
        while (i <= rear)
        {
            printf("%d,", queue[i]);
            i = (i + 1) % size;
        }
    }
}
int main()
{
    int choice, x;
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element which is to be inserted");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\n Wrong choice");
        }
    }
    return 0;
}
