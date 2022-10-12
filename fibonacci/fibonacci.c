#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b,c,i,n;
	clrscr();
	printf("Enter the limit : ");
	scanf("%d",&n);
	printf("\nThe first %d fibonacci numbers are :\n",n);
	for(a=1,b=0,i=0;i<n;i++)
	{
		c=a+b;
		printf("\n%d",c);
		a=b;
		b=c;
	}
	getch();
}