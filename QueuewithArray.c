#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int rear;
    int front;
    int *arr;
};

int isFull(struct Queue *q)
{
    if (q->rear >= q->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Add(struct Queue *q)
{
    if (isFull(q))
    {
        printf("Queue is Full..\n");
        return 0;
    }
    else
    {
        int data;
        printf("Enter Your No: ");
        scanf("%d", &data);
        q->arr[q->rear] = data;
        q->rear++;
        return 1;
    }
}

int Delete(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty..\n");
        return 0;
    }
    else
    {
        for (int i = q->front; i < q->rear-1; i++)
        {
            q->arr[i] = q->arr[i + 1];
        }
        q->rear--;
    }
}

void Transversal(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty...\n");
    }
    else
    {
        for (int i = q->front; i < q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{

    int choice;
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    q->size = 3;
    q->arr = (int *)malloc(q->size * sizeof(int));

    while (1)
    {

        printf("1.add\n2.delete\n3.Display\n4.exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Add(q);
            break;
        case 2:
            Delete(q);
            break;
        case 3:
            Transversal(q);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Enter Correct choice..\n");
            break;
        }
    }
    return 0;
}