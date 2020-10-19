#include<stdio.h>
#include<stdlib.h>
int stack[6], rev[6];
int top= -1, k= 0, size;
void push();
void pop();
void display();
int pali();
void main() {
  int choice, f;
  printf("Enter the size for stack\n");
  scanf("%d",&size);
  printf("1. Push\n2. Pop\n3. Display\n4. Check for Palindrome\n5. Exit\n");
  while(1) {
    printf("\nEnter the choice\n");
    scanf("%d",&choice);
    switch(choice) {
      case 1: push();
              break;
      case 2: pop();
              break;
      case 3: display();
              break;
      case 4: f= pali();
              if(f==1)
                printf("It's a Palindrome\n");
              else
                printf("It's not a Palindrome\n");
              break;
      case 5: exit(0);
      default : printf("Wrong choice...\n");
    }
  }
}
void push() {
  int num;
  if(top==(size-1)) {
    printf("Stack Overflow\n");
  }
  else {
    printf("Enter the number to be pushed\n");
    scanf("%d",&num);
    top++;
    stack[top]= num;
  }
}
void pop() {
  int num;
  if(top==-1) {
  printf("Stack Underflow\n");
  }
  else {
    num= stack[top];
    printf("Popped element is %d\n", num);
    top--;
  }
}
void display() {
  int i;
  if(top==-1) {
    printf("Stack Underflow\n");
  }
  else {
    printf("Stack Contents....\n");
    for(i=top;i>=0;i--) {
      printf("%d\n",stack[i]); rev[k++]=stack[i];
    }
  }
}
int pali() {
  int i,flag=1;
  for(i=top;i>=0;i--) {
    if(stack[i]!=rev[--k]) {
      flag=0;
    }
  }
  return flag;
}
