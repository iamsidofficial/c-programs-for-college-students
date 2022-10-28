#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int top;
	int capacity;
	int* array;
};

struct stack* createstack(int capacity){
	struct Stack* stack = malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = malloc(capacity*sizeof(int));
	return stack;
}

int isFull(struct Stack* stack){
	return stack->capacity-1 == stack->top;
}

int isEmpty(struct Stack* stack){
	return stack->top == -1;
}

int peek(struct Stack* stack){
	return stack->array[stack->top];
}

void push(struct Stack* stack, int value){
	(!isFull(stack)) ? stack->array[++(stack->top)] = value : printf("Stack is full\n");
}

void pop(struct Stack* stack){
	(!isEmpty(stack)) ? stack->array[stack->top--] = 0 : printf("Stack is already Empty\n");
}

void display(struct Stack* stack){
	if(stack->top == -1) printf("list is empty");
	else for(int i=0;i<stack->top+1;i++) printf("%d ",stack->array[i]);
	printf("\n");
}

int main()
{
	int capacity;
	printf("Enter the capacity: ");
	scanf("%d",&capacity);
	struct Stack* stack = createstack(capacity);

	display(stack);
	isEmpty(stack) ? printf("The list is Empty\n"): printf("The stack is not empty\n");
	push(stack,15);
	printf("Value pushed in the stack\n");
	push(stack,63);
	push(stack,85);
	push(stack,85);
	push(stack,85);
	push(stack,85);
	pop(stack);
	printf("The last value is popped of the stack\n");
	display(stack);

	return 0;
}
