#include<stdio.h>
#include<conio.h>

int evaluate(char*);

void main()
{
	char exp[15];
	clrscr();
	printf("Enter an expression in postfix form : ");
	gets(exp);
	printf("\nResult = %d",evaluate(exp));
	getch();
}

int evaluate(char *str)
{
	int stack[15],top=0,op1,op2,i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='0' && str[i]<='9')
			stack[top++]=str[i]-'0';
		else
		{
			op2=stack[--top];
			op1=stack[--top];
			switch(str[i])
			{
				case '+':
					stack[top++]=op1+op2;
					break;
				case '-':
					stack[top++]=op1-op2;
					break;
				case '*':
					stack[top++]=op1*op2;
					break;
				case '/':
					stack[top++]=op1/op2;
					break;
				default:top+=2;
			}
		}
	}
	return stack[--top];
}