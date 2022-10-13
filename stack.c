#include <stdio.h>
#include <stdlib.h>

struct stack
{

     int *ptr;
     int top;
     int capacity;
};
struct stack *createStack(int n)
{
     struct stack *stack;
     stack = (struct stack *)malloc(sizeof(struct stack));
     stack->capacity = n;
     stack->top = -1;
     stack->ptr = (int *)malloc((stack->capacity) * sizeof(int));

     return stack;
}

int isFull(struct stack *ptr)
{
     return ptr->top == (ptr->capacity - 1);
}

int isEmpty(struct stack *ptr)
{
     return (ptr->top == -1);
}

void push(struct stack *p, int val)
{
     if (!(isFull(p)))
     {
          (p->top)++;

          p->ptr[p->top] = val;
     }

     else
     {
          printf("Stack is Full\n");
     }
}

int pop(struct stack *p)
{
     if (!isEmpty)
     {
          printf("Stack is empty can't pop\n");
          return 0;
     }
     else
     {
          (p->top)-=1;
          return (p->ptr[p->top + 1]);
     }
}

void printStack(struct stack *stack)
{
     for (int i = 0; i <= (stack->top); i++)
     {
          printf("value at %dth postion is %d\n", i, (stack->ptr[i]));
     }
}

int main()
{
     int size;
     printf("enter size of stack in c\n");
     
     // scanf("%d",&size);
     size = 5;
     struct stack *ptr;
     ptr = createStack(size);
     int fullresult = isFull(ptr);
     int emp = isEmpty(ptr);
     push(ptr, 19);
     push(ptr, 10);
     push(ptr, 20);
     printStack(ptr);
     printf("\n%d is popped from stack\n", pop(ptr));
     printStack(ptr);

     return 0;
}
